#include"stdio.h"
#include"vector"
#include"set"
#include"map"
#include"assert.h"
#include"algorithm"
#include"math.h"
#include"stdlib.h"
#include"string.h"
#include"string"
using namespace std;
typedef unsigned int ui;
typedef long long int ll;
typedef unsigned long long int ull;
#define REP(i,n) for(unsigned int i=0;i<(n);i++)
#define LOOP(i,x,n) for(int i=(x);i<(n);i++)
#define ALL(v) v.begin(),v.end()
#define FOREACH(it,v)   for(typeof((v).begin()) it=(v).begin();it != (v).end();it++)
#define i(x) scanf("%d",&x)
#define u(x) scanf("%u",&x)
#define l(x) scanf("%lld",&x)
#define ul(x) scanf("%lld",&x)
ll maxim(ll a,ll b)
{
	if(a>b)
		return a;
	else
		return b;
}
ll E,R,N,array[11],V[11],maxi,IN[11];
ll sum,ans,parti,left[11],right[11],ans1,ans2,S;
void soln()
{
	ll val=0,S=E;
	for(int i=1;i<=N;i++)
	{
		S=S-V[i];
		//printf("%lld is S\n",S);
		if(S<0)
			return ;
		else
		{
			S=(S+R);
			if(S>E)
				S=E;
		}
		val+=V[i]*IN[i];
		//printf("%lld  %lld is val\n",V[1],V[2]);
	}
	ans=maxim(val,ans);
}
int main()
{
	int test;i(test);
	for(int i=1;i<=test;i++)
	{
		ans=0;
		printf("Case #%d: ",i);
		scanf("%lld%lld%lld",&E,&R,&N);
		for(int j=1;j<=N;j++)
			scanf("%lld",&IN[j]);
		for(V[1]=R;V[1]<=E;V[1]++)
		{
			if(N>1)
			for(V[2]=0;V[2]<=E;V[2]++)
			{
				if(N>2)
				for(V[3]=0;V[3]<=E;V[3]++)
				{
					if(N>3)
					for(V[4]=0;V[4]<=E;V[4]++)
					{
						if(N>4)
						for(V[5]=0;V[5]<=E;V[5]++)
						{
							if(N>5)
							for(V[6]=0;V[6]<=E;V[6]++)	
							{
								if(N>6)
								for(V[7]=0;V[7]<=E;V[7]++)
								{
								if(N>7)
									for(V[8]=0;V[8]<=E;V[8]++)
									{
										if(N>8)
										for(V[9]=0;V[9]<=E;V[9]++)
										{
											if(N>9)
											for(V[10]=0;V[10]<=E;V[10]++)
											{
												soln();
											}
											else soln();
										}
										else soln();
									}
									else soln();
								}
								else soln();
							}
							else soln();
						}
						else soln();
					}
					else soln();
				}
				else soln();
			}
			else soln();
		}
		printf("%lld\n",ans);
	}
	return 0;
}