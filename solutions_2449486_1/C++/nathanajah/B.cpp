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

int n,m,i,j,k;
int t,aaaa;
int arr[105][105];
int now[105][105];
int main()
{
	scanf("%d",&t);
	for (aaaa=0;aaaa<t;++aaaa)
	{
		scanf("%d %d",&n,&m);
		for (i=0;i<n;++i)
			for (j=0;j<m;++j)
			{
				scanf("%d",&arr[i][j]);
				now[i][j]=100;
			}
		bool bisa=true;
		for (i=0;i<n;++i)
			for (j=0;j<m;++j)
			{
				bool verti=true;
				for (k=0;k<n;++k)
					if (arr[k][j]>arr[i][j])
						verti=false;
				bool hori=true;
				for (k=0;k<m;++k)
					if (arr[i][k]>arr[i][j])
						hori=false;
				if (!hori && !verti)
					bisa=false;
			}
		printf("Case #%d: ",aaaa+1);
		if(bisa)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
