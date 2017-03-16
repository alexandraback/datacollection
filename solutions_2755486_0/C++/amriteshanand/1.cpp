#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cstring>
#include <limits>

using namespace std;

#define FOR(I,A,B) for(int I= (A); I<(B); ++I)
#define REP(I,N) FOR(I,0,N)
#define S(N) scanf("%d", &N)
#define SL(N) scanf("%lld", &N)
#define PB push_back
#define MP make_pair
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define cell pair<int,int>
#define edge pair<int, cell>
typedef vector<char *> vs;
typedef long long int LL;
typedef vector<int> vi;
typedef vector<LL> vii;
int www[40000000];
int mid=40000000/2;
int main()
{
	int t,T,i,N,n[10],s[10],d[10],w[10],e[10],del_d[10],del_p[10],del_s[10],ans,rem,temp;
	int min,j;
	S(T);
	for(t=1;t<=T;t++)
	{
		S(N);
		ans=0;
		rem=0;
		for(i=0;i<N;i++)
		{
			scanf("%d%d%d%d%d%d%d%d",&d[i],&n[i],&w[i],&e[i],&s[i],&del_d[i],&del_p[i],&del_s[i]);
			rem+=n[i];
		}
		REP(i, 40000000)
			www[i]=0;
		while(rem>0)
		{
			min=10000000;
			REP(i, N)
			{
				if(d[i]<min&&n[i]>0)
					min=d[i];
			}
			REP(i, N)
			{
				temp=0;
				if(d[i]==min&&n[i]>0)
				{
					for(j=2*w[i]+mid;j<=2*e[i]+mid;j++)
					{
						if(www[j]<s[i])
						{
							temp=1;
							break;
						}
					}
					//printf("tribe=%d day=%d\n",i,d[i]);
				}
				ans+=temp;				
			}
			REP(i, N)
			{
				if(d[i]==min&&n[i]>0)
				{
					for(j=2*w[i]+mid;j<=2*e[i]+mid;j++)
					{
						if(www[j]<s[i])
						{
							www[j]=s[i];
						}
					}
					d[i]=d[i]+del_d[i];
					n[i]--;
					rem--;
					w[i]=w[i]+del_p[i];
					e[i]=e[i]+del_p[i];
					s[i]=s[i]+del_s[i];
				}				
			}
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
