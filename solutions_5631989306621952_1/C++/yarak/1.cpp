#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define X first
#define Y second
#define endl '\n'
#define gcd __gcd
#define lcm(x,y) ((x)*(y)/gcd(x,y))
#define smin(x,y) (x=min(x,y))
#define smax(x,y) (x=max(x,y))
#define sgcd(x,y) (x=gcd(x,y))
#define slcm(x,y) (x=lcm(x,y))
#define obt __builtin_popcount
#define pb push_back
#define pob pop_back
#define mkp make_pair
#define rsort(x,y) sort(x,y),reverse(x,y);
#define dbg(x) cerr<<#x<<": "<<x<<endl
using namespace std;
vector<pair<char,int> > v;
bool b[1010];
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int ts;
	cin>>ts;
	for(int _=0;_<ts;_++)
    {
        v.clear();
        string s,t;
        cin>>s;
        for(int i=0;i<s.size();i++)
            v.pb(mkp(s[i],i)),b[i]=0;
        rsort(v.begin(),v.end());
        int f=s.size();
        for(int i=0;i<v.size();i++)
            if(f>v[i].Y)
                t+=v[i].X,b[v[i].Y]=1,f=v[i].Y;
        for(int i=0;i<s.size();i++)
            if(!b[i])
                t+=s[i];
        cout<<"Case #"<<_+1<<": "<<t<<endl;
    }
    return 0;
}
