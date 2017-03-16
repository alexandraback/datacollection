#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#define MAXN 12121
using namespace std;
typedef long long big;
big E,R,N;
big ar[MAXN];
int l[MAXN];
int main()
{
	int i;
	int Test,tt;
	big mxE,t;
	scanf(" %d",&Test);
	for(tt=1;tt<=Test;tt++)
	{
		memset(ar,0,sizeof ar);
		memset(l,0,sizeof l);
		mxE=E=R=N=t=0;
		printf("Case #%d: ",tt);
		scanf(" %lld %lld %lld",&E,&R,&N);
		mxE=E;
		for(i=1;i<=N;i++) scanf(" %lld",&ar[i]);
		ar[0]=1e9;
		for(i=N;i>=1;i--)
		{
			l[i]=i+1;
			while(ar[l[i]] <= ar[i])
				l[i]=l[l[i]];
		}
		long long res=0;

		for(i=1;i<=N;i++)
		{
			if(E > mxE) E=mxE;
			if(!l[i])
			{
				res+=E*ar[i];
				E=R;
			}
			else
			{
				t=mxE-R*(l[i]-i);
				if(t>E){E+=R; continue;}
				if(t < 0) t=0;
				res+=(E-t)*ar[i];
				E=t+R;
			}
		}
		printf("%lld\n",res);
	} 
	return 0;
}