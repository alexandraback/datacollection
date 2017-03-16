#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define FILL(a,x) memset(a,x,sizeof(a))
#define foreach( gg,ii ) for( typeof(gg.begin()) ii=gg.begin();ii!=gg.end();ii++)
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define sz(a) int((a).size())
#define N 1000010
#define MAX 30
#define mod 1000000007
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define all(a) a.begin(),a.end()
const ll INF = 1e18+1;

inline ll input(void)
{
	char t;
	ll x=0;
	int neg=0;
	t=getchar();
	while((t<48 || t>57) && t!='-')
		t=getchar();
	if(t=='-')
		{neg=1; t=getchar();}
	while(t>=48 && t<=57)
	{
		x=(x<<3)+(x<<1)+t-48;
		t=getchar();
	}
	if (neg) x=-x;
	return x;
}

inline void output(ll x)
{
	char a[20];
	int i=0,j;
	a[0]='0';
	if (x<0) {putchar('-'); x=-x;}
	if (x==0) putchar('0');
	while(x)
	{
		a[i++]=x%10+48;
		x/=10;
	}
	for(j=i-1;j>=0;j--)
	{
		putchar(a[j]);
	}
	putchar('\n');
}

char s[21];
ll a[1001][2];
set <ll> first,second;

inline ll hasher()
{
	ll n=strlen(s),ans=0;
	REP(i,n)
		ans=(27*ans+s[i]-'a'+1)%mod;
	return ans;
}

int main()
{
	int t,n,x,y,ans,sz;
	t=input();
	REP(kase,t)
	{
		n=input();
		ans=n;
		REP(i,n)
		{
			scanf("%s",s);
			a[i][0]=hasher();
			scanf("%s",s);
			a[i][1]=hasher();		
		}
		REP(i,1<<n)
		{
			first.clear();
			second.clear();
			x=i;
			sz=0;
			REP(j,n)
			{
				if (x%2)
				{
					sz++;
					first.insert(a[j][0]);
					second.insert(a[j][1]);
				}
				x/=2;
			}
			for(x=0;x<n;x++)
				if (first.find(a[x][0])==first.end()||second.find(a[x][1])==second.end()) break;
			if (x==n)
				ans=min(ans,sz);
		}
		printf("Case #%d: %d\n",kase+1,n-ans);
	}
return 0;
}
