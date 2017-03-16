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
vl p;
string itos(ll x)
{
	string s="";
	if (x==0)return "0";
	if (x<0){s+="-";x=-x;}
	while (x){s+='0'+x%10;x/=10;}
	if (s[0]=='-'){reverse(s.begin()+1,s.end());}
	else reverse(all(s));
	return s;
}
bool ispar(int x)
{
	string s1=itos(x);
	string s2=s1;
	reverse(all(s2));
	return s1==s2;
}
int main()
{
	freopen("C:\\Users\\daizhy\\Downloads\\C-small-attempt0 (9).in","r",stdin);
	freopen("C:\\2013¸öÈËÈü\\gcj\\oc1.txt","w",stdout);
	int i,j,k,cas,cc=0;	
	scanf("%d",&cas);
	while (cas--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int ans=0;
		for (i=1;i<=1000;i++)
		{
			if (i*i>=l&&i*i<=r&&ispar(i)&&ispar(i*i))ans++;
		}
		printf("Case #%d: %d\n",++cc,ans);
	}
	return 0;
}
