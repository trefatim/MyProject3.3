#include <iostream>
#include <string>

using namespace std;

struct queue
{
	int i;
	queue *pNext;
};

/*! Добавление элемента в очередь.
 * \param [in] pPrev − указатель на предыдущий элемент.
 * \param [in] p − указатель на добавляемый элемент.
 * \param [in] pFirst − указатель на первый элемент.
 */
void add (queue *&pPrev, queue *p, queue *&pFirst)
{
	if(pPrev==NULL)
	{
		pFirst=p;
		pPrev=p;
	}
	else
	{
		pPrev->pNext=p;
		pPrev=p;
	}
}

/*! Удаление элемента из очереди.
 * \param [in] pFirst − указатель на первый элемент.
 */
void del(queue *&pFirst)
{
	pFirst=pFirst->pNext;
}

//!Функция main
int main()
{
	queue *p, *pPrev=NULL, *pFirst=NULL;
	int n, k=0, value;//!<кол-во действий, счетчик, значение элемента
	string mode;//!<операция над очередью
	cout<<"n="; cin>>n;
	while (k!=n)
	{
		cout<<"mode=";
		fflush(stdin);
		getline(cin,mode);
		if(mode=="add")
		{
			cin>>value;
			p=new queue;
			p->i=value;
			p->pNext=NULL;
			add(pPrev,p, pFirst);
			k++;
		}
		else if(mode=="del")
		{
			del(pFirst);
			k++;
		}
		else
		{
			cout<<"wrong";
		}
	}
	p=pFirst;
	while(p!=NULL)
	{
		cout<<p->i<<" ";
		p=p->pNext;
	}
	system("pause");
	return 0;
}