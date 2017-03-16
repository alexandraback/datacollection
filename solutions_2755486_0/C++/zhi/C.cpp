#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#define MAX_N 10
#define MAX_n 10
#define MAX_ABS_P 1000
using namespace std;
typedef double LL;
struct attack { int d,w,e,s; } a[MAX_N*MAX_n];
int wall[MAX_ABS_P*2+1];
int MAX(int A,int B)
{
	if(A>B)
		return A;
	return B;
}
bool CMP(struct attack A,struct attack B)
{
	if(A.d<B.d)
		return true;
	return false;
}
int TRANS(int A)
{
	return A+MAX_ABS_P;
}
int main()
{
	int T,N,d,n,w,e,s,dd,dp,ds,p,ans,last;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		p=0;
		scanf("%d",&N);
		for(int j=0;j<N;j++)
		{
			scanf("%d%d%d%d%d%d%d%d",&d,&n,&w,&e,&s,&dd,&dp,&ds);
			for(int k=0;k<n;k++)
			{
				a[p].d=d+k*dd;
				a[p].w=w+k*dp;
				a[p].e=e+k*dp;
				a[p].s=s+k*ds;
				p++;
			}
		}
		sort(a,a+p,CMP);
		ans=0;
		last=0;
		for(int j=0;j<MAX_ABS_P*2+1;j++)
			wall[j]=0;
		for(int j=0;j<p;j++)
		{
			for(int k=a[j].w;k<a[j].e;k++)
				if(wall[TRANS(k)]<a[j].s)
				{
					ans++;
					break;
				}
			if(j+1==p||a[j].d!=a[j+1].d)
			{
				for(int k=last;k<=j;k++)
					for(int l=a[k].w;l<a[k].e;l++)
						wall[TRANS(l)]=MAX(wall[TRANS(l)],a[k].s);
				last=j+1;		
			}
		}
		printf("Case #%d: %d\n",i+1,ans);
	}
	return 0;
}
