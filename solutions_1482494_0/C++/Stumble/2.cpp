#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<fstream>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int MAXN=1111;
struct node
{
	int a,b;
	bool ap,bp;
};
node data[MAXN];
int T,N;
int cmp(const void * a,const void * b)
{
	node * aa=(node * )a;
	node * bb=(node * )b;
	if(aa->b==bb->b)
	return aa->a-bb->a;
	return aa->b-bb->b;
}
void solve(int cnum)
{
	memset(data,0,sizeof(data));
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d%d",&data[i].a,&data[i].b);
	}
	qsort(&data[1],N,sizeof(node),cmp);
	int S=0;
	int times=0;
	for(int i=1;i<=N;i++)
	{
		if(!data[i].bp)
		{
			if(S>=data[i].b)
			S+=(!data[i].ap)+1,data[i].bp=1,data[i].ap=1,times++;
			else 
			{
				bool flag=0;
				for(int j=N;j>=1;j--)
				if(S>=data[j].a&&!data[j].ap)
				{
					S++,times++,data[j].ap=1;
					flag=1;break;
				}
				if(flag==0)
				{
					printf("Case #%d: Too Bad\n",cnum);
					return ;
				}
				i--;
			}
		}
	}
	printf("Case #%d: %d\n",cnum,times);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		solve(tt);
	}
}