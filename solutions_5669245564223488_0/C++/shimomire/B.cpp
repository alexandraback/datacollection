#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cctype>
#include <complex>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
using namespace std;


//common
using i32=int;using i64=long long;using ll =i64;
using uint=unsigned int;using ull=unsigned long long;
template<typename T> using matrix=vector<vector<T> >;

#define BR "\n"
#define ALL(c) (c).begin(),(c).end()
#define AALL( a, t ) (t*)a, (t*)a + sizeof( a ) / sizeof( t )
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,l,r) for(int i=(int)l;i<(int)(r);++i)
#define EACH(it,o) for(auto it = (o).begin(); it != (o).end(); ++it)
#define IN(l,v,r) ((l)<=(v) && (v)<(r))

//config
//#define NDEBUG

//debug
#ifdef NDEBUG
#define DUMP(x)
#define DUMPLN(x)
#define DEBUG(x)
#define DEBUGLN(x)
#define LINE()
#define LINELN()
#define CHECK(exp,act)
#define STOP(e)
#else
#define DUMP(x)  cerr << #x << " = " << (x)
#define DUMPLN(x)  DUMP(x) <<endl
#define DEBUG(x) DUMP(x) << LINE() << " " << __FILE__
#define DEBUGLN(x) DEBUG(x)<<endl
#define LINE()    cerr<< " (L" << __LINE__ << ")"
#define LINELN()    LINE()<<endl
#define CHECK(exp,act)  if(exp!=act){DUMPLN(exp);DEBUGLN(act);}
#define STOP(e)  CHECK(e,true);if(!(e)) exit(1);
#endif

template<class T> inline string toString(const vector<T>& x) {
	stringstream ss;
	REP(i,x.size()){
		if(i!=0)ss<<" ";
		ss<< x[i];
	}
	return ss.str();
}

template<class T> inline string toString(const vector<vector<T> >& map) {
	stringstream ss;
	REP(i,map.size()){
		if(i!=0)ss<<BR;
		ss<< toString(map[i]);
	}
	return ss.str();
}
template<class K,class V>  string toString(map<K,V>& x) {
	string res;stringstream ss;
	for(auto& p:x)ss<< p.first<<":" << p.second<<" ";
	return ss.str();
}

string BITtoString(int bit){
    stringstream ss;
    while(bit!=0){ss<<(bit%2);bit/=2;}
    string res=ss.str();reverse(ALL(res));
    return res;
}

template<typename T,typename V> inline T pmod(T v,V MOD){
	return (v%MOD+MOD)%MOD;
}
#define nextInt(n) scanf("%d",&n)
#define nextLong(n) scanf("%I64d",&n)
#define nextDouble(n) scanf("%lf",&n)


//#define INF 1<<30
//#define EPS 1e-8
//const ll MOD =100000007;
ll INF=1LL<<58;

namespace Sccs{
    struct Edge{
        int to;
        Edge(int to):to(to){};
    };
    using Graph= vector<vector<Edge> >;

    //O(V+E)
    class Scc{
    private:
        int V;
        Graph g,rg;
        vector<bool> used;
       
        void dfs(int v){
            used[v]=true;
            EACH(e,g[v])if(!used[e->to])dfs(e->to);
            vs.push_back(v);
        }
        void rdfs(int v,int k){
            used[v]=true;
            cmp[v]=k;
            EACH(e,rg[v])if(!used[e->to])rdfs(e->to,k);
        }
    public:
         vector<int> vs,cmp; //cmp...強連結成分を同一視したトポロジカルソート順序

        Scc(int V):V(V){
            g=Graph(V);rg=Graph(V);
            vs=vector<int>(V);cmp=vector<int>(V);used=vector<bool>(V);
        }
        void add_edge(int f,int t){
            g[f].push_back(t);rg[t].push_back(f);
        }
        int scc(){
            fill(ALL(used),false);
            vs.clear();
            REP(v,V)if(!used[v])dfs(v);

            fill(ALL(used),false);
            int k=0;
            for(int i=vs.size()-1;i>=0;i--)if(!used[vs[i]])rdfs(vs[i],k++);
            return k;
        }
        //sample
        bool same(int i,int j){
            return cmp[i]==cmp[j];
        }
    };
}
using namespace Sccs;

struct UnionFind{
    vector<int> par; // 親
    vector<int> rank; // 木の深さ
    vector<int> ss;//xの属する集合のサイズ:option
    int size;//集合の個数:option
    UnionFind(int n){
        REP(i,n) par.push_back(i);
        rank = vector<int>(n);
        ss=vector<int>(n,1);
        size=n;
    }
    int root(int x){
        if(par[x] == x)return x;
        return par[x] = root(par[x]);
    }
    bool same(int x,int y){
        return root(x) == root(y);
    }
    void unite(int x,int y){
        x = root(x);y = root(y);
        if(x==y)return;
        if(rank[x] < rank[y]){
            par[x] = y;
            ss[y]+=ss[x];
        }else{
            par[y] = x;
            ss[x]+=ss[y];
        }
        if(rank[x] == rank[y]) rank[x]++;
        size--;
    }
};

ll MOD=1000000007;
///mod utils
template <typename T>
class MU{
private:
	T M;
public:
	MU(T M=MOD):M(M){
		memo=vector<T>(200,-1);
	}
	T mod(T n){T r=n%M;return r<0?r+M:r;}
	T add(T a,T b){ return mod(mod(a)+mod(b));}
	T mul(T a,T b){ return mod(mod(a)*mod(b));}

	// verified by ACAC001 http://judge.u-aizu.ac.jp/onlinejudge/creview.jsp?rid=798506&cid=ACAC001
	//O(log N)
	T pow(T x, ll N){
		T res=1;
		while(N!=0){
			if(N%2==1)res=mul(res,x);
			x=mul(x,x);
			N/=2;
		}
		return res;
	}
	// O(log M)
	T inv(const T x){return pow(x,M-2);}
	// 1~nの逆元を求める O(log N)
	vector<T> inv_list(T N){
		vector<T> inv(N + 1);
		inv[1] = 1;
		for (int i = 2; i <= N; ++i)inv[i] = mul(inv[M % i],M - M / i);
		return inv;
	}
	vector<T> memo;
	// O(N)  
	T fact(const T N){if(memo[N]!=-1)return memo[N];else return memo[N]=(N==0?1:mul(N,fact(N-1)));}
	T nPr(const int N,const int r){return mul(fact(N),inv(fact(N-r)));}
	T nCr(const int N,const int r){return mul(nPr(N,r),inv(fact(r)));}     
};

class Main{
public:


	// void small(){
	// 	ifstream cin("in");
	// 	ofstream cout( "smallout" );

	// 	MU<ll> mu;
	// 	int T;cin >> T;
	// 	for(int tc=1;tc<=T;tc++){
	// 		DUMP(BR);DUMP(tc);
	// 		int N;cin >> N;
	// 		vector<string> ss(N);REP(i,N) cin >> ss[i];

	// 		//1文字につぶす．
	// 		REP(i,N){
	// 			string tmp=ss[i];
	// 			ss[i]="";
	// 			REP(j,tmp.size()){
	// 				if(ss[i].size()==0){
	// 					ss[i]+=tmp[j];
	// 				}else if(ss[i][ss[i].size()-1]!=tmp[j]){
	// 					ss[i]+=tmp[j];
	// 				}
	// 			}
	// 		}

	// 		ll res=0;
	// 		vector<int> per(N);
	// 		REP(i,N) per[i]=i;

	// 		do{
	// 			string tmp="";
	// 			REP(i,N)tmp+=ss[per[i]];
	// 			string s="";
	// 			REP(j,tmp.size()){
	// 				if(s.size()==0){
	// 					s+=tmp[j];
	// 				}else if(s[s.size()-1]!=tmp[j]){
	// 					s+=tmp[j];
	// 				}
	// 			}
	// 		//	DUMP(s);
	// 			//check
	// 			bool ok=true;
	// 			set<char> ex;
	// 			REP(i,s.size()){
	// 				if(ex.count(s[i])){
	// 					ok=false;break;
	// 				}
	// 				ex.insert(s[i]);
	// 			}
	// 			if(ok)res++;
	// 			res=mu.mod(res);
	// 		}while(next_permutation(ALL(per)));

	// 		cout <<res <<endl;
	// 	}
	// }

	void run(){
		ifstream cin("in");
		ofstream cout( "out" );

		MU<ll> mu;

		int T;cin >> T;
		for(int tc=1;tc<=T;tc++){
			bool ed=false;
			int N;cin >> N;
			vector<string> ss(N);REP(i,N) cin >> ss[i];

			//1文字につぶす．
			REP(i,N){
				string tmp=ss[i];
				ss[i]="";
				REP(j,tmp.size()){
					if(ss[i].size()==0){
						ss[i]+=tmp[j];
					}else if(ss[i][ss[i].size()-1]!=tmp[j]){
						ss[i]+=tmp[j];
					}
				}
			}
			map<int,int> lmap,mmap,rmap;
			REP(i,N)if(ss[i].size()!=1){
				lmap[ss[i][0]-'a']++;
				rmap[ss[i][ss[i].size()-1]-'a']++;
				set<int> ex; 
				for(int j=1;j+2<=ss[i].size();j++){
					ex.insert(ss[i][j]-'a');
				}
				REP(c,26)if(ex.count(c)){
					mmap[c]++;
				}
			}
			map<int,int> single;
			REP(i,N)if(ss[i].size()==1)single[ss[i][0]-'a']++;

			//check
			REP(c,26)if(mmap[c] >=1 && single[c]+lmap[c]+rmap[c]>=1){
				if(!ed){
					cout <<"Case #"<<tc<<": "<<0<<endl;ed=true;
				}
			}
			REP(c,26)if(lmap[c]>=2 || rmap[c]>=2){
				if(!ed){
					cout <<"Case #"<<tc<<": "<<0<<endl;ed=true;
				}
			}

			//lmapとrmapが1→サイクル or パス
			
			//結合にサイクルが必要か？
			Scc scc(N);
			REP(i,N)if(ss[i].size()!=1)REP(j,N)if(ss[j].size()!=1)
			if(i!=j  && ss[i][ss[i].size()-1]==ss[j][0]){
				scc.add_edge(i,j);
			}
			scc.scc();
			REP(i,N)if(ss[i].size()!=1)REP(j,N)if(ss[j].size()!=1)
			if(i!=j && scc.same(i, j)){
				if(!ed){
					cout <<"Case #"<<tc<<": "<<0<<endl;ed=true;
				}				
			}

			//作れる時
			ll res=1;			
			REP(c,26)res=mu.mod(res*mu.fact(single[c]));

			UnionFind uf(N);
			REP(i,N)REP(j,N){
				if(ss[i][0]==ss[j][ss[j].size()-1] || ss[i][ss[i].size()-1]==ss[j][0])uf.unite(i,j);
			}
			res=mu.mod(res*mu.fact(uf.size));
			if(!ed){
				cout <<"Case #"<<tc<<": "<<res<<endl;ed=true;
			}
		}
	}
};
 int main(){
	 cout <<fixed<<setprecision(15);
	ios::sync_with_stdio(false);
 //	Main().small();
 	Main().run();
 	return 0;
 }