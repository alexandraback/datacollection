#include<bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define For(i,a,b) for(int i=a-1;i>=b;i--)
#define rep(i,b) FOR(i,0,b)
#define Rep(i,b) For(i,a,0)
#define SORT(x) sort(x.begin(),x.end());
#define ERASE(x) x.erase(x.begin(),x.end());
#define FILL(x,i) memset(x,i,sizeof(x));
#define K 1000000007
#define L 400
#define s1(a) scanf("%d",&a);
#define s2(a) scanf("%lld",&a);
#define s3(a,b) scanf("%lld%lld",&a,&b);
#define s4(a,b,c) scanf("%lld%lld%lld",&a,&b,&c);
#define pb push_back
#define mp make_pair
#define F first
#define S second 
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define EPS 0.000001
#define MAX 1

typedef long long int ll;

bool cmp(ll a,ll b){if(a>b) return true; return false;}

ll powr(int s,int p)
{
	if(p==0)
		return 1;	
 
	if(p%2==1)
	{
		ll q=powr(s,p/2);
		ll a=q;
		q=(a*a);
		q=(q*s);	
		return ( q );
	}
 
	else
	{
		ll q=powr(s,p/2);
		ll a=q;
		q=(a*a);	
		return (q);
	}
}
/*******************************MAIN CODE STARTS*******************************/

string c,j;
int x,y;

void f(int i,int s,int r)
{
	if(i==c.size())
	{
		//cout<<s<<' '<<r<<'\n';
		if(abs(s-r)<abs(x-y))
		{
			x=s;
			y=r;
		}
		else if(abs(s-r)==abs(x-y))
		{
			if(x>s)
			{
				x=s;
				y=r;
			}
			else if(x==s && y>r)
			{
				x=s;
				y=r;
			}
		}
		return;
	}
	ll a=s,b=r;
	if(c[i]=='?')
	{
		FOR(l,0,10)
		{
			a=a*10+l;
			if(j[i]=='?')
			{
				FOR(m,0,10)
				{
					b=b*10+m;
					f(i+1,a,b);
					b=r;
				}
			}
			else
			{
				b=b*10+j[i]-'0';
				f(i+1,a,b);
				b=r;
			}
			a=s;
		}
	}
	else
	{
		a=a*10+c[i]-'0';
		if(j[i]=='?')
		{
			FOR(l,0,10)
			{
				b=b*10+l;
				f(i+1,a,b);
				b=r;
			}
		}
		else
		{
			b=b*10+j[i]-'0';
			f(i+1,a,b);
			b=r;
		}
	}
}

int main()
{
	int t=1;
	s1(t)
	FOR(i,1,t+1)
	{
		x=K;
		y=0;
		printf("Case #%d: ",i);
		cin>>c>>j;
		f(0,0,0);
		//cout<<x<<' '<<y<<'\n';
		FOR(i,0,c.size())
		{
			c[i]='0'+x/pow(10,c.size()-i-1);
			j[i]='0'+y/pow(10,c.size()-i-1);
			x=x%(int)pow(10,c.size()-i-1);
			y=y%(int)pow(10,c.size()-i-1);
		}
		cout<<c<<' '<<j<<'\n';
	}
	return 0;
}
