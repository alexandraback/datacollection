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
char re[222];
char *s="ejp mysljylc kd kxveddknmc re jsicpdrysi";
char *rs="our language is impossible to understand";
char *s1="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
char *rs1="there are twenty six factorial possibilities";
char *s2="de kr kd eoya kw aej tysr re ujdr lkgc jv";
char *rs2="so it is okay if you want to just give up";
void init()
{
	for (int i=0;s[i];i++)
	{
		re[s[i]]=rs[i];
	}
	for (int i=0;s1[i];i++)
	{
		re[s1[i]]=rs1[i];
	}
	for (int i=0;s2[i];i++)
	{
		re[s2[i]]=rs2[i];
	}
	re['z']='q';
	//for (int i='a';i<='z';i++)putchar(i);puts("");
	int vis[333]={0};
	for (int i='a';i<='z';i++)
	{
		vis[re[i]]=1;
	}
	for (int i='a';i<='z';i++)if (!vis[i])
	{
		re['q']=i;
		break;
	}
	//for (int i='a';i<='z';i++)putchar(re[i]);
	//puts("");
}
char st[333];
int main()
{
	freopen("C:\\Users\\daizhy\\Documents\\output.txt","w",stdout);
	init();
	int i,j,k,cas,cc=0;
	scanf("%d",&cas);getchar();
	while (cas--)
	{
		gets(st);int l=strlen(st);
		printf("Case #%d: ",++cc);
		for (i=0;i<l;i++)putchar(re[st[i]]);
		puts("");
	}
	return 0;
}
	
