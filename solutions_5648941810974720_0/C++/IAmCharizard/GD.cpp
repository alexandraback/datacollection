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

string s;
ll a[26],h[10];

int main()
{
	int t=1;
	s1(t)
	FOR(i,1,t+1)
	{
		printf("Case #%d: ",i);
		cin>>s;
		FILL(a,0)
		FILL(h,0)
		FOR(i,0,s.size())
		{
			a[s[i]-'A']++;
		}
		h[0]=a[25];
		h[2]=a['W'-'A'];
		h[4]=a['U'-'A'];
		h[6]=a['X'-'A'];
		h[8]=a['G'-'A'];
		h[1]=a['O'-'A']-h[0]-h[2]-h[4];
		h[3]=a['R'-'A']-h[0]-h[4];
		h[5]=a['F'-'A']-h[4];
		h[7]=a['V'-'A']-h[5];
		h[9]=a['I'-'A']-h[5]-h[6]-h[8];
		FOR(i,0,10)
		{
			while(h[i]>0)
			{
				cout<<i;
				--h[i];
			}
		}
		cout<<'\n';
	}
	return 0;
}
