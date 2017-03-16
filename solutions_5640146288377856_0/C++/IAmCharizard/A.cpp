#include<bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define For(i,a,b) for(int i=a-1;i>=b;i--)
#define rep(i,b) FOR(i,0,b)
#define Rep(i,b) For(i,a,0)
#define SORT(x) sort(x.begin(),x.end());
#define FILL(x,i) memset(x,i,sizeof(x));
#define K 1000000007
#define L 400
#define ll long long
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

bool cmp(ll a,ll b){if(a>b) return true; return false;}
/*******************************MAIN CODE STARTS*******************************/

int CaseNo,r,c,w;

void scan()
{
	cin>>r>>c>>w;
}

void out()
{
	int ans=(r-1)*(c/w) + (c/w - 1) + w;
	if(c%w!=0)
		++ans;
	printf("Case #%d: %d\n",CaseNo,ans);
}

int main()
{
	int t;
	s1(t)
	while(CaseNo!=t)
	{
		CaseNo++;
		scan();
		out();
	}
	return 0;
}
