// g++ -std=c++0x
#include <iostream> // cout, endl
#include <iomanip> // setprecision
#include <iterator> // ostream_iterator
#include <vector>
#include <algorithm> // sort
#include <cstring> // memset
#include <deque>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Node
{
    ll v,d;
};

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<ll> VLL;
typedef vector<vector<ll> > MLL;
typedef vector<ull> VULL;
typedef vector<vector<ull> > MULL;
typedef vector<Node> VNode;
typedef vector<vector<Node> > MNode;
#define MAX(a,b) ((a)>(b)?(a):(b))
#define FOR(i,N) for(int i=0;i<(N);++i)
#define FORLL(i,N) for(ll i=0;i<(N);++i)
#define FORULL(i,N) for(ull i=0;i<(N);++i)
#define FOR2(i,A,B) for(int i=(A);i<(B);++i)
#define FORLL2(i,A,B) for(ll i=(A);i<(B);++i)
#define FORULL2(i,A,B) for(ull i=(A);i<(B);++i)
#define SORT(v) sort((v).begin(),(v).end())
#define PB push_back
#define PF pop_front
#define X first
#define Y second
#define MATRIX(m,T,size,init) vector<vector<T> > m(size,vector<T>(size,init));

#define FILE __FILE__ << " "
#define LINE "line " << __LINE__ << " : "
#define FUNC "(function " << __FUNCTION__ << ") "
#define log cout<<endl<<FILE<<LINE<<FUNC; 
#define printL(l) for(auto it=l.begin();it!=l.end();++it) cout<<*it<<","; cout<<endl;
#define printM(m) for(auto it=m.begin();it!=m.end();++it){ auto l=*it; for(auto it2=l.begin();it2!=l.end();++it2) cout<<*it2<<","; cout<<endl;} cout<<endl;
#define printLNode(lNode) for(auto it=lNode.begin();it!=lNode.end();++it){ Node node=*it; printNode(node); }
#define printNode(node) cout<<"("<<node.v<<","<<node.d<<")"<<", ";
#define copy(v,T,s) copy((v).begin(),(v).end(),ostream_iterator<T>(cout,s)); cout << endl;
#define copyn(v,T,s,n) copy((v).begin(),(v).begin()+n,ostream_iterator<T>(cout,s)); cout << endl;

VD getRet(ll n,VLL v)
{
	vector<ll> u(v);
	SORT(u);
	VD f(n,1.0);
	ll X=0;
	FORLL(j,n) X+=v[j];
	FORLL(j,n)
	{
		ll sumj=0,meet=false,nb=0,vj=v[j];
		FORLL(k,n)
		{
			if(u[k]==v[j] and meet==false)
			{
				meet=true;
				continue;
			}
			++nb;
			sumj+=u[k];
			double tmp=(X+sumj-nb*vj)*1.0/(nb+1.0)/X;
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
    FOR(i,nbCase)
    {
        ull n;
		VLL v;
        cin>>n;
		FORLL(j,n)
		{
			ll tmp;
			cin>>tmp;
			v.push_back(tmp);
			//cout<<tmp<<" ";
		}
		//cout<<endl;
        cout<<"Case #"<<i+1<<": ";
        VD ret = getRet(n,v);
		FORLL(j,n)
		{
			cout<<setprecision(7)<<ret[j]*100;
			if(j<n-1) cout<<" ";
		}
        cout<<endl;
    }
}