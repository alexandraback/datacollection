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

string s[2][1010];
ll n,res;

void f(int i,vector<int> a)
{
	if(i==n)
	{
		ll p=0,flag=0;
		map<string,int> m[2];
		map<string,int>::iterator it;
		FOR(j,0,2)
		m[j].erase(m[j].begin(),m[j].begin());
		FOR(i,0,a.size())
		{
			if(a[i]==0)
			{
				FOR(j,0,2)
				{
					m[j][s[j][i]]++;
				}
				++p;
			}
		}
		FOR(i,0,a.size())
		{
			if(a[i]==0)
			{
				int f=0;
				FOR(j,0,2)
				{
					if(m[j].find(s[j][i])->S>1)
						++f;
				}
				if(f==2)
				{
					flag=1;
					break;
				}
			}
		}
		//cout<<flag<<n-p<<'\n';
		if(flag==0)
			res=min(res,n-p);
		return;
	}
	a[i]=0;
	f(i+1,a);
	a[i]=1;
	f(i+1,a);
}

int main()
{
	int t=1;
	s1(t)
	FOR(i,1,t+1)
	{
		printf("Case #%d: ",i);
		s2(n)
		FOR(i,0,n)
		{
			cin>>s[0][i]>>s[1][i];
			//cout<<s[0][i]<<' '<<s[1][i]<<'\n';
		}
		vector<int> a(n);
		FOR(i,0,a.size())
			a[i]=0;
		res=K;
		f(0,a);
		cout<<res<<'\n';
	}
	return 0;
}
