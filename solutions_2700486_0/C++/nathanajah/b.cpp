//nathanajah's template
//28-11-2012
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <map>
#include <ctime>
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned LL
#define INF 0x3FFFFFFF
#define INFLL 0x3FFFFFFFFFFFFFFF
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(),(a).end()
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

inline string GetString()
{
	char GS[1000005];
	scanf("%s",GS);string ret=GS;
	return ret;
}

inline char getc()
{
	char c=' ';
	while (c==' ' || c=='\t' || c=='\r' || c=='\n')
		c=getchar();
	return c;
}
//ENDOFTEMPLATE
int t,n,i,j;
int aaaa;
int x,y;
int bawah;
int sisa;
int f(int x)
{
	return (2*x+1)*(x+1);
}
double dp[3005][3005];
int main()
{
	scanf("%d",&t);
	for (aaaa=0;aaaa<t;++aaaa)
	{
		printf("Case #%d: ",aaaa+1);
		scanf("%d %d %d",&n,&x,&y);
		bawah=0;
		while (f(bawah+1)<=n)
			++bawah;
		sisa=n-f(bawah);
		if (abs(x)+abs(y)<=2*bawah)
			printf("1.0\n");
		else if (abs(x)+abs(y)>2*(bawah+1))
			printf("0.0\n");
		else
		{
			for (i=0;i<=4*(bawah+1);++i)
				for (j=0;j<=4*(bawah+1);++j)
					dp[i][j]=0;
			dp[0][0]=1;
			for (j=0;j<=4*(bawah+1)-1;++j)
			{
				for (i=0;i<=j;++i)
				{
					if (i<=2*(bawah+1) && (j-i)<=2*(bawah+1))
					{
						if (i+1<=2*(bawah+1) && (j-i+1)<=2*(bawah+1))
						{
							dp[i+1][j-i]+=dp[i][j-i]/2.0;
							dp[i][j-i+1]+=dp[i][j-i]/2.0;
						}
						else if (i+1<=2*(bawah+1))
						{
							dp[i+1][j-i]+=dp[i][j-i];
						}
						else if ((j-i+1)<=2*(bawah+1))
						{
							dp[i][j-i+1]+=dp[i][j-i];
						}
					}
				}
			}
			int kiri=(-2*(bawah+1));
			int kanan=(2*(bawah+1));
			double hasil=0;
			
			for (i=0;i<=sisa;++i)
			{
				int j=sisa-i;
				if (((kiri<=x && x<kiri+i) || (kanan-j<x && x<=kanan)))
				{
//					printf("%d %d\n",i,j);
					hasil+=dp[i][j];
				}
			}
			printf("%.10lf\n",hasil);
		}
	}
}
