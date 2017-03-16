#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
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


int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	ll t=rl(),i,j,k,l,temp,x,y,caseno=0,ans,r,w,c,pr,v,d,sum,one,two,lim;
	vector<ll> a;
	while(t--)
	{
		caseno++;
		a.resize(0);
		ans=0;one=0;two=0;lim=0;
		c=rl();d=rl();v=rl();
		loop(i,0,d)
		{
			ll temp=rl();
			if(temp==1)
				one=1;
			if(temp==2)
				two=2;
			a.pb(temp);
		}
		if(one==0)
		{
			a.pb(1);
			//cout<<"inserted=1"<<endl;
			ans++;
		}
		sort(a.begin(),a.end());
		sum=0;lim=1*c;
		loop(i,1,a.size())
		{
			//cout<<"ai="<<a[i]<<endl;
			if (lim>=v)
				break;
			if(a[i]<=lim+1)
				lim+=a[i]*c;
			else
			{
				ans++; // add lim+1 in set
				//cout<<"inserted="<<lim+1<<endl;
				lim+=(lim+1)*c;
				i--;		
			}
			//cout<<"new lim="<<lim<<endl;
		}
		while(lim<v)
		{
			//cout<<"inserted="<<lim+1<<endl;
			lim+=(lim+1)*c;
			ans++;
		}
		cout<<"Case #"<<caseno<<": "<<ans<<endl;
	}
}