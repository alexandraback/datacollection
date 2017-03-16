#include <iostream>
#include <fstream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define GCD(a,b)  { return (b==0)?a:GCD(b,a%b);
#define FOR(i,n) for(i=0;i<n;i++)
#define FOR_X(i,n,x) for(i=x;i<n;i++)
#define BACK(i,n) for(i=n;i>=0;i--)
#define BACK_X(i,n,x) for(i=n;i>=x;i--)
#define pp <int,double>
typedef long long int lld;
using namespace std;
double dp[102][102]	;
int cp[102][102];
int S,L,K;
int f[102];
int a[27];
string lstr,kstr;
double rec( int pos, int now)
{
	if( cp[pos][now]!=-1) return dp[pos][now];
	if( pos<=S && now==L)
	{
		cp[pos][now]=1;
		dp[pos][now]=1.0+rec(pos,f[L]);
		return dp[pos][now];
	}
	else if( pos==S ) return 0;
	 
	else
	{
		cp[pos][now]=1;
		double ans=0;
		int i;
		FOR(i,26)
		{
			if( a[i]!=0 )
			{
				if( i+'A' == lstr[ now ] )
				{
				 	double x=rec( pos+1,now+1);
					ans= ans+ x*(double)a[i]/(double)K;
				}
				else
				{
					int j=f[now];
					while(1)
					{
						if( lstr[j] == i+'A')
						{
							j=j+1; break;
						}
						else if(j==0)
						{
							break;
						}
						else j=f[j];
					}
					double x=rec( pos+1,j);
					ans= ans+ x*(double)a[i]/(double)K;
				}
			}
		}
		dp[pos][now]=ans;
		return dp[pos][now];
	}
}
int main()
{
//	ios_base::sync_with_stdio(0); //dont use with EOF
	int t,i,j,x=0;
	cin>>t;
	while(t--)
	{
		x++;
		memset(cp,-1,sizeof(cp));
		memset(a,0,sizeof(a));
		cin>>K>>L>>S;
		cin>>kstr;
		cin>>lstr;
		FOR(i,K)
		{
			a[ kstr[i]-'A' ]++;
		}
		int poss=1;
		FOR(i,L)
		{
			if( a[lstr[i]-'A']==0) poss=0;
		}
		if( poss==0)
		{
			printf("Case #%d: 0.0\n",x );
			continue;
		}
		f[0]=f[1];
		for(i=2;i<=L;i++)
		{
			j=f[i-1];
			while( 1 )
			{
				if( lstr[j]== lstr[i-1])
				{
					f[i]=j+1;
					break;
				}
				else if( j==0)
				{
					f[i]=0;
					break;
				}
				else j=f[j];
			}
		}
		int mxi=L-f[L];
		int p=S-L;
		int xx=p/mxi+1;
	//	cout<<rec(0,0)<<endl;
		printf("Case #%d: %.6lf\n",x,(double)xx-rec(0,0) );
	}
	return 0;
}
