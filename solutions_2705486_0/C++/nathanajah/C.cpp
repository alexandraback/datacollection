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
int t;
string dict[600000];
int i,j,k;
string s;
int dp[60][6];
int dictnum=521196;
vector <int> bedatmp[600000][56];
bool valid[600000][56];

int hitung(int x, int last)
{
	if (x==SZ(s))
		return 0;
	int &ret=dp[x][last];
	if (ret>=0)
		return ret;
	int i,j;
	ret=500;
	for (i=0;i<dictnum;++i)
	{
		if (x+SZ(dict[i])<=SZ(s))
		{
			if (valid[i][x])
			{
				if (SZ(bedatmp[i][x])==0)
					ret=min(ret,hitung(x+SZ(dict[i]),min(4,last+SZ(dict[i]))));
				else
				{
					if (last+bedatmp[i][x][0]>3)
					{
						ret=min(ret,SZ(bedatmp[i][x])+hitung(x+SZ(dict[i]),min(4,SZ(dict[i])-1-bedatmp[i][x][SZ(bedatmp[i][x])-1])));
					}
				}
			}
		}
	}
	return ret;
}
int main()
{
	freopen("garbled_email_dictionary.txt","r",stdin);
	for (i=0;i<dictnum;++i)
		dict[i]=GetString();
	freopen("a.in","r",stdin);
	scanf("%d",&t);
	for (int aaaa=0;aaaa<t;++aaaa)
	{
		printf("Case #%d: ",aaaa+1);
		memset(dp,-1,sizeof(dp));
		s=GetString();
		for (i=0;i<SZ(s);++i)
		{
			for (j=0;j<dictnum;++j)
			{
				bedatmp[j][i].clear();
				valid[j][i]=true;
				if (i+SZ(dict[j])<=SZ(s))
				{
					for (k=0;k<SZ(dict[j]);++k)
					{
						if (dict[j][k]!=s[i+k])
							bedatmp[j][i].pb(k);
					}
					for (k=0;k<SZ(bedatmp[j][i])-1;++k)
						if (bedatmp[j][i][k+1]-bedatmp[j][i][k]<5)
							valid[j][i]=false;
				}
			}
		}
		printf("%d\n",hitung(0,4));
	}
}
