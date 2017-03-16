#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<climits>
#include<complex>
#include<cassert>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)((x).size())
#define all(x) x.begin(),x.end()
#define clr(x) memset((x),0,sizeof(x))
#define cdp(x) memset((x),-1,sizeof(x))
#define rep(i,n) for (i=0;i<n;i++)
#define Rep(i,a,b) for (i=a;i<=b;i++)
#define ff(i,x) for (i=start[x];i!=-1;i=a[i].next)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
int dblcmp(double d){if (fabs(d)<eps)return 0;return d>eps?1:-1;}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
char s[6][6];
bool win(char c)
{
	int i,j,k;
	for (i=0;i<4;i++)
	{
		int x=0;
		for (j=0;j<4;j++)
		{
			if (s[i][j]==c||s[i][j]=='T')x++;
		}
		if (x==4)return 1;
	}
	for (i=0;i<4;i++)
	{
		int x=0;
		for (j=0;j<4;j++)
		{
			if (s[j][i]==c||s[j][i]=='T')x++;
		}
		if (x==4)return 1;
	}
	int x=0;
	for (i=0;i<4;i++)
	{
		if (s[i][i]==c||s[i][i]=='T')x++;
	}
	if (x==4)return 1;
	x=0;
	for (i=0;i<4;i++)
	{
		if (s[3-i][i]==c||s[3-i][i]=='T')x++;
	}
	if (x==4)return 1;
	return 0;
}
int main()
{
	freopen("C:\\Users\\daizhy\\Downloads\\A-small-attempt0 (9).in","r",stdin);
	freopen("C:\\2013¸öÈËÈü\\gcj\\oa.txt","w",stdout);
	int i,j,k,cas,cc=0;	
	scanf("%d",&cas);
	while (cas--)
	{
		for (i=0;i<4;i++)scanf("%s",s[i]);
		printf("Case #%d: ",++cc);
		if (win('X'))
		{
			puts("X won");
			continue;
		}
		if (win('O'))
		{
			puts("O won");
			continue;
		}
		int sum=0;
		for (i=0;i<4;i++)
		{
			for (j=0;j<4;j++)sum+=(s[i][j]=='.');
		}
		if (!sum)puts("Draw");
		else puts("Game has not completed");
	}
	return 0;
}
