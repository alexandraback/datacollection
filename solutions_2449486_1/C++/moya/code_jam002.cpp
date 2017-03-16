#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int maxn=10010;
typedef struct Node
{
	int row;
	int clo;
	int num;
	Node *next;
	Node * pre;
}block;
block num[maxn];
int n0,m0,n,m;
int cmp(const void *a,const void *b)
{
	block *_a=(block*)a;
	block *_b=(block*)b;
	if(_a->num!=_b->num)
		return _b->num-_a->num;
	else if(_a->row!=_b->row)
		return _b->row-_a->row;
	else
		return _b->clo-_a->clo;
}
int del(block *head)
{
	block *now;
	int flag[210];
	int i,id,temp,row_flag;
	for(i=0;i<n0;i++)
		flag[i]=m;
	for(i=0;i<m0;i++)
		flag[i+n0]=n;
	now=head->next;
	id=-1;
	while(1)
	{
		if(--flag[now->row]==0)
		{
			id=now->row;
			break;
		}
		if(--flag[n0+now->clo]==0)
		{
			id=n0+now->clo;
			break;
		}
		if(now->next&&(now->next)->num==now->num)
			now=now->next;
		else
			break;
	}
	if(id<0)
		return 1;
	now=head->next;
	temp=m;
	row_flag=1;
	if(id>=n0)
	{
		id-=n0;
		temp=n;
		row_flag=0;
	}
//	printf("this:%d %d %d\n",row_flag,id,temp);
	while(1)
	{
		if(row_flag&&now->row==id)
		{
			if(now->next)
				(now->next)->pre=now->pre;
			(now->pre)->next=now->next;
			temp--;
		}
		else if(!row_flag&&now->clo==id)
		{
			if(now->next)
				(now->next)->pre=now->pre;
			(now->pre)->next=now->next;
			temp--;
		}
		if(temp==0)
			break;
		if(now->next&&(now->next)->num==now->num)
			now=now->next;
		else
			return 1;
	}
	if(row_flag)
		n--;
	else
		m--;
//	printf("%d %d\n",n,m);
	return 0;
}
int main()
{
	int T,t,id,i,j;
	block head;
	scanf("%d",&T);
	t=1;
	while(T--)
	{
		scanf("%d %d",&n0,&m0);
		n=n0;
		m=m0;
		id=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				scanf("%d",&num[id].num);
				num[id].row=i;
				num[id].clo=j;
				num[id].next=NULL;
				num[id++].pre=NULL;
			}
		qsort(num,id,sizeof(num[0]),cmp);
		for(i=1;i<id;i++)
			num[i].next=num+i-1;
		for(i=0;i<id-1;i++)
			num[i].pre=num+i+1;
		head.next=num+id-1;
		num[id-1].pre=&head;
		while(n&&m)
			if(del(&head))
				break;
		printf("Case #%d: ",t++);
		if(n&&m)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 1;
}