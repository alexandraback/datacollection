#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cplx;

#define sqr(x) ((x)*(x))
#define pb push_back
#define X first
#define Y second
#define sit(a) set<a>::iterator
#define mit(a,b) map<a,b>::iterator

const ll mod=1000000007LL;
const int inf=0x3f3f3f3f;
const int maxn=100005,maxm=1005;
const double eps=1e-10;
const double pi=acos(-1.0);

ll abst(ll x){return x<0?-x:x;}

char c[25],d[25];
ll r1,r2;
int n;

ll cal(char *ct,int t,int n)
{
	ll r=0;
	int i=0;
	for(i=0;i<n;i++)
	{
		if(ct[i]=='?') r=r*10+t;
		else r=r*10+ct[i]-'0';
	}
	return r;
}

bool cmp(ll x,ll y,ll z,ll w)
{
	if(abst(x-y)<abst(z-w)) return 1;
	if(abst(x-y)==abst(z-w)&&x<z) return 1;
	if(abst(x-y)==abst(z-w)&&x==z&&y<w) return 1;
	return 0;
}

void tmp()
{
	ll rt1=cal(c,9,n),rt2=cal(d,0,n);
	if(cmp(rt1,rt2,r1,r2)) r1=rt1,r2=rt2;
	rt1=cal(c,0,n),rt2=cal(d,9,n);
	if(cmp(rt1,rt2,r1,r2)) r1=rt1,r2=rt2;
	rt1=cal(c,9,n),rt2=cal(d,9,n);
	if(cmp(rt1,rt2,r1,r2)) r1=rt1,r2=rt2;
	rt1=cal(c,0,n),rt2=cal(d,0,n);
	if(cmp(rt1,rt2,r1,r2)) r1=rt1,r2=rt2;
}

void solve()
{
	int i,j;
	r1=0,r2=1LL<<61;
	for(i=0;i<=n;i++)
	{
		if(i==n) {tmp();break;}
		if(c[i]!='?'&&d[i]!='?')
		{
			tmp();
		}
		else if(c[i]!='?'&&d[i]=='?')
		{
			d[i]=(c[i]-'0'+1)%10+'0';tmp();
			d[i]=(c[i]-'0'+9)%10+'0';tmp();
			d[i]=c[i];tmp();
		}
		else if(c[i]=='?'&&d[i]!='?')
		{
			c[i]=(d[i]-'0'+1)%10+'0';tmp();
			c[i]=(d[i]-'0'+9)%10+'0';tmp();
			c[i]=d[i];tmp();
		}
		else
		{
			c[i]='0',d[i]='1';tmp();
			c[i]='1',d[i]='0';tmp();
			c[i]='0',d[i]='0';tmp();
		}
	}
}

ll cf[18]={1};
void print(ll x)
{
	int i,j;
	for(i=n-1;i>=0;i--) printf("%lld",x/cf[i]%10);
}

int T,ca;

int main()
{
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<18;i++) cf[i]=cf[i-1]*10;
	for(ca=1;ca<=T;ca++)
	{
		scanf("%s %s",c,d);
		n=strlen(c);
		printf("Case #%d: ",ca);
		solve();
		print(r1);printf(" ");print(r2);printf("\n");
	}
	return 0;
}
