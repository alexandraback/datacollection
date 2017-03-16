#pragma warning(disable:4786)
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<set>
#include<stdlib.h>
#include<sstream>
#include<functional>
#include<queue>
#include<stack>
using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define ABS(A) ((A)>0?(A):(-(A)))
#define S(X) ((X)*(X))

typedef pair<int,int> PII;

//int dr[]={-1,0,1,0};
//int dc[]={0,1,0,-1};
//int dr[]={-2,-2,-1,1,2,2,1,-1};
//int dc[]={-1,1,2,2,1,-1,-2,-2};

typedef __int64 LL;
#define I64d "%I64d"

int surprise[40], nonsurprise[40];

void gen()
{
	memset(surprise,-1,sizeof(surprise));
	memset(nonsurprise,-1,sizeof(nonsurprise));

	int i, j, k, S;
	for(i=0;i<=10;i++)
		for(j=i;j<=10 && j<=i+2;j++)
			for(k=j;k<=10 && k<=i+2;k++)
			{
				S = i+j+k;

				if(k==i+2)
				{
					if(surprise[S]<k) surprise[S] = k;
				}
				else
				{
					if(nonsurprise[S]<k) nonsurprise[S]=k;
				}
			}
}

int p,num[105],N;
int dp[105][105];

int DP(int at, int left)
{
	if(left<0) return -1000;

	if(at==N)
	{
		if(left==0) return 0;
		return -1000;
	}

	int &ret = dp[at][left];
	if(ret!=-1) return ret;

	if(surprise[num[at]]!=-1)
	{
		ret = MAX(ret, DP(at+1,left-1)+(surprise[num[at]]>=p));
	}

	if(nonsurprise[num[at]]!=-1)
	{
		ret = MAX(ret, DP(at+1,left)+(nonsurprise[num[at]]>=p));
	}

	return ret;
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);

//	freopen("c-large.in","r",stdin);
//	freopen("c-large.out","w",stdout);

	int T, ks;
	int S, i;

	gen();

	scanf("%d",&T);
	for(ks=1;ks<=T;ks++)
	{
		printf("Case #%d: ",ks);

		scanf("%d%d%d",&N,&S,&p);
		for(i=0;i<N;i++)
			scanf("%d",&num[i]);

		memset(dp,-1,sizeof(dp));
		printf("%d\n",DP(0,S));
	}

	return 0;
}