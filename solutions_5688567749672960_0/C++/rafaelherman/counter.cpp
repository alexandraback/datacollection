#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define mp make_pair
#define ff first
#define ss second
using namespace std;

queue<pair<int,int> > q;

int ans[1000005];

int oper(int a)
{
	int b=0;

	return b;
}

int main()
{
	int test,r,c,tot,ang,in,no;
	for(int a=1;a<=1000004;a++)
	{
		ans[a]=10000000;
	}
	q.push(mp(1,1));
	while(!q.empty())
	{
		int kk=0;
		no=q.front().ff;
		tot=q.front().ss;
		if(no<=1000001&&tot<ans[no])
		{
			ans[no]=tot;
			q.push(mp(no+1,tot+1));
			while(no!=0)
			{
				kk=kk*10+no%10;
				no/=10;
			}
			q.push(mp(kk,tot+1));
		}
		q.pop();
	}
	scanf("%d",&test);
	for(int a=1;a<=test;a++)
	{
		scanf("%d",&in);
		printf("Case #%d: %d\n",a,ans[in]);
	}
}
