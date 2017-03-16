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

int ri() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
	ret = 10 * ret + c - 48;
	c = gc();
  }
  return ret;
}

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

string rs()
{
	char c = gc();
	while(c=='\n' || c==' ') c=gc();
	string ret="";
	while(c!=10 && c!=' ')
	{
		ret+=c;
		c=gc();
	}
	return ret;
}

char rc()
{
	char c = gc();
	while(c=='\n' || c==' ') c=gc();
	return c;
}

ll reversenum(ll n)
{
	ll reverse=0;
	 while (n > 0)
   {
      reverse = reverse * 10;
      reverse = reverse + n%10;
      n       = n/10;
   }
   //cout<<"reverse"<<reverse;
   return reverse;
}


int main()
{
	ll T;

	cin>>T;
	ll ans,midval,count=0,R,C,W,i,t=T;
	while(T--)
	{
		cin>>R>>C>>W;
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