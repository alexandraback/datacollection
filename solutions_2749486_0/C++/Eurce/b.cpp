#include<queue>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
using namespace std;

int t,x,y;

struct node
{
	int x,y,d;
	string S;
}*p,*q;

main()
{
	int i,j,k;
	scanf("%*d");
	while(cin>>x>>y)
	{
		p=new node;
		p->x=0;
		p->y=0;
		p->d=0;
		queue<node*>Q;
		Q.push(p);
		while(!Q.empty())
		{
			p=Q.front(); Q.pop();
			i=p->d+1;
			if(p->x+i==x)
			{
				p->S+='E';
				p->d++;
				break;
			}
			else
			{
				q=new node;
				q->x=p->x+i;
				q->y=p->y;
				q->d=i;
				q->S=p->S+'E';
				Q.push(q);
			}
			if(p->x-i==x)
			{
				p->S+='W';
				p->d++;
				break;
			}
			else
			{
				q=new node;
				q->x=p->x-i;
				q->y=p->y;
				q->d=i;
				q->S=p->S+'W';
				Q.push(q);
			}
		}
		while(!Q.empty()) Q.pop();
		Q.push(p);
		while(!Q.empty())
		{
			p=Q.front(); Q.pop();
			i=p->d+1;
			if(p->y+i==y)
			{
				p->S+='N';
				p->d++;
				break;
			}
			else
			{
				q=new node;
				q->x=p->x;
				q->y=p->y+i;
				q->d=i;
				q->S=p->S+'N';
				Q.push(q);
			}
			if(p->y-i==y)
			{
				p->S+='S';
				p->d++;
				break;
			}
			else
			{
				q=new node;
				q->x=p->x;
				q->y=p->y-i;
				q->d=i;
				q->S=p->S+'S';
				Q.push(q);
			}
		}
		cout<<"Case #"<<++t<<": "<<p->S<<endl;
	}
}



