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

int n,k;
int i,j;
int t,aaaa;
bool bisa[1100000][31];
int banyakkey[205];
vector <int> isi[505];
int tmp;
int tmp2;
int butuh[505];

void bf(int x, int y)
{
	int i;
	if (y==n)
	{
		for (i=0;i<n;++i)
		{
			if ((x&(1<<i))==0)
			{
				if (banyakkey[butuh[i]]>0)
					bisa[x][i]=true;
				else
					bisa[x][i]=false;
			}
		}
	}
	else
	{
		bf(x,y+1);
		for (i=0;i<SZ(isi[y]);++i)
			++banyakkey[isi[y][i]];
		--banyakkey[butuh[y]];
		bf(x+(1<<y),y+1);
		for (i=0;i<SZ(isi[y]);++i)
			--banyakkey[isi[y][i]];
		++banyakkey[butuh[y]];
	}
}

int dp[1100000];
int dari[1100000];
int hitung(int x)
{
	if (x==(1<<n)-1)
		return 1;
	int &ret=dp[x];
	if (ret>=0)
		return ret;
	int i;
	for (i=0;i<n;++i)
	{
		if (bisa[x][i])
		{
			if (hitung(x+(1<<i))>0)
			{
				ret=1;
				dari[x]=i;
				return 1;
			}
		}
	}
	ret=0;
	return 0;
}

void btrack(int x)
{
	if (x==(1<<n)-1)
		return;
	printf(" %d",dari[x]+1);
	btrack(x+(1<<dari[x]));
}

int main()
{
	scanf("%d",&t);
	for (aaaa=0;aaaa<t;++aaaa)
	{
		memset(dp,-1,sizeof(dp));
		memset(banyakkey,0,sizeof(banyakkey));
		printf("Case #%d:",aaaa+1);
		scanf("%d %d",&k,&n);
		for (i=0;i<n;++i)
			isi[i].clear();
		for (i=0;i<k;++i)
		{
			scanf("%d",&tmp);
			++banyakkey[tmp];
		}
		for (i=0;i<n;++i)
		{
			scanf("%d",&butuh[i]);
			scanf("%d",&tmp);
			for (j=0;j<tmp;++j)
			{
				scanf("%d",&tmp2);
				isi[i].push_back(tmp2);
			}
		}
		bf(0,0);
		int hasil=hitung(0);
		if (hasil==0)
			printf(" IMPOSSIBLE\n");
		else
		{
			btrack(0);
			printf("\n");
		}
	}
}
