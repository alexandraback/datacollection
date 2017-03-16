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

void getRet(ull n,MLL M)
{
	FORLL2(i,1,n)
	{
		//cout<<endl<<i<<":"<<endl;
		VI visited(n,0);
		deque<ull> d;
		d.PB(i);
		while(d.size()>0)
		{
			//for(auto it=d.begin();it!=d.end();++it) cout<<*it<<","; cout<<endl;
			ull a=d.front();
			d.PF();
			//for(auto it=d.begin();it!=d.end();++it) cout<<*it<<","; cout<<endl;
			FORLL2(j,1,n)
			{
				if(j==i) continue;
				if(M[a][j]==1)
				{
					if(visited[j]==1)
					{
						cout<<"Yes";
						return;
					}
					d.PB(j);
					//for(auto it=d.begin();it!=d.end();++it) cout<<*it<<","; cout<<endl;
					visited[j]=1;
				}
			}
		}
	}
	cout<<"No";
	return;
}
 
int main()
{
    int nbCase;
    cin>>nbCase;
	//cout<<nbCase<<endl;
    FOR(i,nbCase)
    {
        ull n;
        cin>>n;
		//cout<<n<<endl;
		MLL M(n+1,VLL(n+1,0));
		FORLL2(j,1,n+1)
		{
			ll nj;
			cin>>nj;
			FORLL(k,nj)
			{
				ll tmp;
				cin>>tmp;
				M[j][tmp]=1;
			}
		}
		//printM(M);
        cout<<"Case #"<<i+1<<": ";
        getRet(n+1,M);
        cout<<endl;
    }
}