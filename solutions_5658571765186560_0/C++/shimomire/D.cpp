#include <cassert>// c
#include <iostream>// io
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>// container
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <algorithm>// other
#include <complex>
#include <numeric>
#include <functional>
#include <random>
#include <regex>
using namespace std;

typedef long long ll;typedef unsigned long long ull;typedef long double ld;

#define ALL(c) c.begin(),c.end()
#define IN(l,v,r) (l<=v && v < r)
template<class T> void UNIQUE(T v){v.erase(unique(ALL(v)),v.end());}
//debug
#define DUMP(x) cerr << #x <<" = " << (x)
#define LINE() cerr<< " (L" << __LINE__ << ")"

struct range{
	struct Iter{
		int v,step;
		Iter& operator++(){v+=step;return *this;}
		bool operator!=(Iter& itr){return v<itr.v;}
		int& operator*(){return v;}
	};
	Iter i, n;
	range(int i, int n,int step):i({i,step}), n({n,step}){}
	range(int i, int n):range(i,n,1){}
	range(int n):range(0,n){}
	Iter& begin(){return i;}
	Iter& end(){return n;}
};
struct rrange{
	struct Iter{
		int v,step;
		Iter& operator++(){v-=step;return *this;}
		bool operator!=(Iter& itr){return v>itr.v;}
		int& operator*(){return v;}
	};
	Iter i, n;
	rrange(int i, int n,int step):i({i-1,step}), n({n-1,step}){}
	rrange(int i, int n):rrange(i,n,1){}
	rrange(int n) :rrange(0,n){}
	Iter& begin(){return n;}
	Iter& end(){return i;}
};

//input
template<typename T1,typename T2> istream& operator >> (istream& is,pair<T1,T2>& p){return is>>p.first>>p.second;}
template<typename T1> istream& operator >> (istream& is,tuple<T1>& t){return is >> get<0>(t);}
template<typename T1,typename T2> istream& operator >> (istream& is,tuple<T1,T2>& t){return is >> get<0>(t) >> get<1>(t);}
template<typename T1,typename T2,typename T3> istream& operator >> (istream& is,tuple<T1,T2,T3>& t){return is >>get<0>(t)>>get<1>(t)>>get<2>(t);}
template<typename T1,typename T2,typename T3,typename T4> istream& operator >> (istream& is,tuple<T1,T2,T3,T4>& t){return is >> get<0>(t)>>get<1>(t)>>get<2>(t)>>get<3>(t);}
template<typename T> istream& operator >> (istream& is,vector<T>& as){for(int i:range(as.size()))is >>as[i];return is;}
//output
template<typename T> ostream& operator << (ostream& os, const set<T>& ss){for(auto a:ss){if(a!=ss.begin())os<<" "; os<<a;}return os;}
template<typename T1,typename T2> ostream& operator << (ostream& os, const pair<T1,T2>& p){return os<<p.first<<" "<<p.second;}
template<typename K,typename V> ostream& operator << (ostream& os, const map<K,V>& m){bool isF=true;for(auto& p:m){if(!isF)os<<endl;os<<p;isF=false;}return os;}
template<typename T1> ostream& operator << (ostream& os, const tuple<T1>& t){return os << get<0>(t);}
template<typename T1,typename T2> ostream& operator << (ostream& os, const tuple<T1,T2>& t){return os << get<0>(t)<<" "<<get<1>(t);}
template<typename T1,typename T2,typename T3> ostream& operator << (ostream& os, const tuple<T1,T2,T3>& t){return os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t);}
template<typename T1,typename T2,typename T3,typename T4> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4>& t){return os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t);}
template<typename T> ostream& operator << (ostream& os, const vector<T>& as){for(int i:range(as.size())){if(i!=0)os<<" "; os<<as[i];}return os;}
template<typename T> ostream& operator << (ostream& os, const vector<vector<T>>& as){for(int i:range(as.size())){if(i!=0)os<<endl; os<<as[i];}return os;}

// values
template<typename T> inline T INF(){assert(false);};
template<> inline int INF<int>(){return 1<<28;};
template<> inline ll INF<ll>(){return 1LL<<58;};
template<> inline double INF<double>(){return 1e16;};
template<> inline long double INF<long double>(){return 1e16;};

template<class T> inline T EPS(){assert(false);};
template<> inline int EPS<int>(){return 1;};
template<> inline ll EPS<ll>(){return 1LL;};
template<> inline double EPS<double>(){return 1e-8;};
template<> inline long double EPS<long double>(){return 1e-8;};

// min{2^r | n < 2^r}
template<typename T> T upper_pow2(T n){ T res=1;while(res<n)res<<=1;return res;}
// max{d | 2^d  <= n}
template<typename T> T msb(T n){ int d=62;while((1LL<<d)>n)d--;return d;}

template<typename T,typename U> T pmod(T v,U M){return (v%M+M)%M;}


class Main{
	public:

	void run(){
		int T;cin >> T;

		for(int q:range(T)){
			int X,R,C;cin >> X >> R >> C;

			if(X>=4){
				cout << make_tuple("Case","#"+to_string(q+1)+":","RICHARD")<<endl;
				continue;
			}
			if(X==1){
				cout << make_tuple("Case","#"+to_string(q+1)+":",(R*C)%1!=0?"RICHARD":"GABRIEL")<<endl;
				continue;
			}
			if(X==2){
				cout << make_tuple("Case","#"+to_string(q+1)+":",(R*C)%2!=0?"RICHARD":"GABRIEL")<<endl;
				continue;
			}
			if(X==3){
				// 2 x 3 ではれる
				bool ok=true;
				ok&=(R*C)%6==0;
				ok&=(R%3==0 && C%2==0) || (R%2==0 && C%3==0);
				cout << make_tuple("Case","#"+to_string(q+1)+":",!ok?"RICHARD":"GABRIEL")<<endl;
				continue;
			}
		}
	}
};

int main(){
	cout <<fixed<<setprecision(20);
	cin.tie(0);
	ios::sync_with_stdio(false);
	Main().run();
	return 0;
}