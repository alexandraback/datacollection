#include <iostream> // cout, endl
#include <iomanip> // setprecision
#include <vector>
#include <algorithm> // sort
#include <cstring> // memset
#include <deque>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define max(a,b) ((a)>(b)?(a):(b))

struct Node
{
    ll v,d;
};

struct PtSet
{
    ll A1,B1,A2,B2;
};

#define FILE __FILE__ << " "
#define LINE "line " << __LINE__ << " : "
#define FUNC "(function " << __FUNCTION__ << ") "
#define log cout<<endl<<FILE<<LINE<<FUNC; 
#define printL(l) for(auto it=l.begin();it!=l.end();++it) cout<<*it<<","; cout<<endl;
#define printM(m) for(auto it=m.begin();it!=m.end();++it){ auto l=*it; for(auto it2=l.begin();it2!=l.end();++it2) cout<<*it2<<","; cout<<endl;} cout<<endl;
#define printLNode(lNode) for(auto it=lNode.begin();it!=lNode.end();++it){ Node node=*it; printNode(node); }
#define printNode(node) cout<<"("<<node.v<<","<<node.d<<")"<<", ";

vector<float> getRet(ll n,vector<ll> v)
{
	vector<ll> u(v);
	sort(u.begin(),u.end());
	vector<float> f(n,1.0);
	ll X=0;
	for(ll j=0;j<n;++j)
	{
		X+=v[j];
	}
	for(ll j=0;j<n;++j)
	{
		ll sumj=0,meet=false,nb=0,vj=v[j];
		for(ll k=0;k<n;++k)
		{
			if(u[k]==v[j] and meet==false)
			{
				meet=true;
				continue;
			}
			++nb;
			sumj+=u[k];
			float tmp=(X+sumj-nb*vj)*1.0/(nb+1.0)/X;
			if(tmp<f[j]) f[j]=tmp;
			if(f[j]<=0) f[j]=0.0;
			//cout<<nb<<","<<X<<","<<sumj<<","<<tmp<<","<<f[j]<<","<<j<<endl;
		}
	}
	return f;
}
 
int main()
{
    int nbCase;
    cin>>nbCase;
    for(int i=0;i<nbCase;++i)
    {
        ull n;
		vector<ll> v;
        cin>>n;
		for(ll j=0;j<n;++j)
		{
			ll tmp;
			cin>>tmp;
			v.push_back(tmp);
			//cout<<tmp<<" ";
		}
		//cout<<endl;
        cout<<"Case #"<<i+1<<": ";
        vector<float> ret = getRet(n,v);
		for(ll j=0;j<n;++j)
		{
			cout<<setprecision(7)<<ret[j]*100;
			if(j<n-1) cout<<" ";
		}
        cout<<endl;
    }
}