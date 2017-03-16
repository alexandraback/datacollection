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

typedef long long ll;
typedef unsigned long long ull;

#define ALL(c) c.begin(),c.end()
#define REP(i,n) FOR(i,0,n)
#define REPr(i,n) FORr(i,0,n)
#define FOR(i,l,r) for(int i=(int)(l);i<(int)(r);++i)
#define FORr(i,l,r) for(int i=(int)(r)-1;i>=(int)(l);--i)
#define EACH(it,o) for(auto it = (o).begin(); it != (o).end(); ++it)
#define IN(l,v,r) ((l)<=(v) && (v)<(r))
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end())
//debug
#define DUMP(x)  cerr << #x << " = " << (x)
#define LINE()    cerr<< " (L" << __LINE__ << ")"

class range {
private:
	struct Iter{
		int v;
		int operator*(){return v;}
		bool operator!=(Iter& itr) {return v < itr.v;}
		void operator++() {++v;}
	};
	Iter i, n;
public:
	range(int n) : i({0}), n({n}) {}
	range(int i, int n) : i({i}), n({n}) {}
	Iter& begin() {return i;}
	Iter& end() {return n;}
};

//input
template<typename T1,typename T2> istream& operator >> (istream& is,pair<T1,T2>& p){return is>>p.first>>p.second;}
template<typename T1> istream& operator >> (istream& is,tuple<T1>& t){return is >> get<0>(t);}
template<typename T1,typename T2> istream& operator >> (istream& is,tuple<T1,T2>& t){return is >> get<0>(t) >> get<1>(t);}
template<typename T1,typename T2,typename T3> istream& operator >> (istream& is,tuple<T1,T2,T3>& t){return is >>get<0>(t)>>get<1>(t)>>get<2>(t);}
template<typename T1,typename T2,typename T3,typename T4> istream& operator >> (istream& is,tuple<T1,T2,T3,T4>& t){return is >> get<0>(t)>>get<1>(t)>>get<2>(t)>>get<3>(t);}
template<typename T1,typename T2,typename T3,typename T4,typename T5> istream& operator >> (istream& is, const tuple<T1,T2,T3,T4,T5>& t){return is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t) >> get<4>(t);}
template<typename T1,typename T2,typename T3,typename T4,typename T5,typename T6> istream& operator >> (istream& is, const tuple<T1,T2,T3,T4,T5,T6>& t){return is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t) >> get<4>(t) >> get<5>(t);}
template<typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7> istream& operator >> (istream& is, const tuple<T1,T2,T3,T4,T5,T6,T7>& t){return is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t) >> get<4>(t) >> get<5>(t) >> get<6>(t);}
template<typename T> istream& operator >> (istream& is,vector<T>& as){for(int i:range(as.size()))is >>as[i];return is;}

//output
template<typename T> ostream& operator << (ostream& os, const set<T>& ss){for(auto a:ss){if(a!=ss.begin())os<<" "; os<<a;}return os;}
template<typename T1,typename T2> ostream& operator << (ostream& os, const pair<T1,T2>& p){return os<<p.first<<" "<<p.second;}
template<typename K,typename V> ostream& operator << (ostream& os, const map<K,V>& m){bool isF=true;for(auto& p:m){if(!isF)os<<endl;os<<p;isF=false;}return os;}
template<typename T1> ostream& operator << (ostream& os, const tuple<T1>& t){return os << get<0>(t);}
template<typename T1,typename T2> ostream& operator << (ostream& os, const tuple<T1,T2>& t){return os << get<0>(t)<<" "<<get<1>(t);}
template<typename T1,typename T2,typename T3> ostream& operator << (ostream& os, const tuple<T1,T2,T3>& t){return os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t);}
template<typename T1,typename T2,typename T3,typename T4> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4>& t){return os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t);}
template<typename T1,typename T2,typename T3,typename T4,typename T5> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4,T5>& t){return os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t)<<" "<<get<4>(t);}
template<typename T1,typename T2,typename T3,typename T4,typename T5,typename T6> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4,T5,T6>& t){return os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t)<<" "<<get<4>(t)<<" "<<get<5>(t);}
template<typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4,T5,T6,T7>& t){return os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t)<<" "<<get<4>(t)<<" "<<get<5>(t)<<" "<<get<6>(t);}
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
template<typename T> T upper_pow2(T n){
	T res=1;while(res<n)res<<=1;return res;
}
// max{d | 2^d  <= n}
template<typename T> T msb(T n){
	int d=30;while((1<<d)>n)d--;return d;
}

template<typename T,typename U> T pmod(T v,U M){return (v%M+M)%M;}

class Main{
	public:
	void run(){
		int T;cin >> T;
		for(int q:range(T)){
			string a,b;cin >> a >> b;int n = a.size();

			tuple<ll,string,string> res = make_tuple(1LL<<62,"-","-");
			for(int k:range(n+1))for(int k2:range(n+1))for(int p:range(2)){
				string at = a,bt = b;
				if(p){
					for(int j:range(k,n)) if(at[j]=='?') at[j] = '9';
					for(int j:range(k2,n)) if(bt[j]=='?') bt[j] = '0';
				}else{
					for(int j:range(k,n)) if(at[j]=='?') at[j] = '0';
					for(int j:range(k2,n)) if(bt[j]=='?') bt[j] = '9';
				}
				for(int i = n-1;i>=0;i--){
					if(at[i]=='?' && bt[i]=='?'){
						tuple<ll,int,int> mv = make_tuple((ll)1e19,9,9);
						for(int v1:range(2))for(int v2:range(2)){
							at[i] = v1 + '0'; bt[i] = v2+ '0';
							if(mv > make_tuple(abs(stoll(at.substr(i)) - stoll(bt.substr(i))),v1,v2)){
								mv =make_tuple(abs(stoll(at.substr(i)) - stoll(bt.substr(i))),v1,v2);
							}
						}
						at[i] = get<1>(mv)+'0';
						bt[i] = get<2>(mv)+'0';
					}else if(at[i] == '?'){
						tuple<ll,int> mv = make_tuple((ll)1e19,9);
						for(int v2 = max(bt[i]-1-'0',0);v2 <= min(bt[i]+1-'0',9);v2++){
							at[i] = v2 + '0';
							if(mv > make_tuple(abs(stoll(at.substr(i)) - stoll(bt.substr(i))),v2)){
								mv =make_tuple(abs(stoll(at.substr(i)) - stoll(bt.substr(i))),v2);
							}
						}
						at[i] = get<1>(mv)+'0';
					}else if(bt[i] == '?'){
						tuple<ll,int> mv = make_tuple((ll)1e19,9);
						for(int v2 = max(at[i]-1-'0',0);v2 <= min(at[i]+1-'0',9);v2++){
							bt[i] = v2 + '0';
							if(mv > make_tuple(abs(stoll(at.substr(i)) - stoll(bt.substr(i))),v2)){
								mv =make_tuple(abs(stoll(at.substr(i)) - stoll(bt.substr(i))),v2);
							}
						}
						bt[i] = get<1>(mv)+'0';
					}
				}
				auto t = make_tuple(abs(stoll(at) - stoll(bt)),at,bt);
				res = min<tuple<ll,string,string>>(res,t);
			}

			// ? -> 0
			// ? -> 0

			// ? 5 -> 5 5
			// 4 9 -> 4 9

			// 1 ? -> 1 9
			// 2 ? -> 2 0

			cout << make_tuple("Case","#"+to_string(q+1)+":",get<1>(res),get<2>(res))<<endl;
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
