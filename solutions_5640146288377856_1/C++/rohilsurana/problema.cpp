#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<string> vs;
typedef unsigned long long llu;
#define loop(i,a,b) for(i=a;i<b;i++)
#define iter(j,a) for(vector<int>::iterator j = a.begin();j!=a.end();j++)
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define gc getchar   


ll rl()
{
	char c = gc();
	while(c<'0' || c>'9') c = gc();
	ll ret = 0;
	while(c>='0' && c<='9') {
		ret = 10 * ret + c - 48;
		c = gc();
	}
	return ret;		
}


int main()
{
	ll T;

	cin>>T;
	ll ans,midval,count=0,R,C,W,i,t=T;
	while(T--)
	{
		//cin>>R>>C>>W;
		R=rl();
		C=rl();
		W=rl();
		midval = C/W;
		ans = R*midval;
		if(C%W!=0)
		{
			ans++;
		}
		ans = ans + W - 1;
		cout<<"Case #"<<t-T<<": "<<ans<<endl;
	}

	return 0;
}