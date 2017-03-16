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


namespace _double_tmpl{
	typedef long double D;
	D M_PI = acos(-1);
	static constexpr D Ae=0;
	D A(D a,D b){return a+b;}D Ainv(D a){return -a;}
	D S(D a,D b){return A(a,Ainv(b));}

	static constexpr D Me=1;
	D M(D a,D b){return a*b;}D Minv(D a){return 1.0/a;};

	int sig(D a,D b=0){return a<b-EPS<D>()?-1:a>b+EPS<D>()?1:0;}
	template<typename T> bool eq(const T& a,const T& b){return sig(abs(a-b))==0;}

	D pfmod(D v,D MOD=2*M_PI){return fmod(fmod(v,MOD)+MOD,MOD);}

	//[0,PI)
	D AbsArg(D a){
		D ret=pfmod(max(a,-a),2*M_PI);return min(ret,2*M_PI-ret);
	}
}
using namespace _double_tmpl;
namespace Matrix{
	#define H(mat) mat.size()
	#define W(mat) mat[0].size()

	class Inconsistent{//none
	};
	class Ambiguous{//many
	};

	class NoSolution{
	};
	template <typename T> class Mat :public vector<vector<T>> {
		public:

		// tropical
		// static const T Ae=INF;
		// T A(T a,T b){return min(a,b);}
		// static const T Me=0;
		// T M(T a,T b){return a+b;}

		// double
		static constexpr T Ae=0.0;
		T A(T a,T b){return a+b;}T Ainv(T a){return -a;}
		static constexpr T Me=1.0;
		T M(T a,T b){return a*b;}T Minv(T a){return 1/a;}

		Mat(int H,int W) : vector<vector<T>>(H){
			REP(y,H)this->at(y)=vector<T>(W);
		}
		Mat(int H,int W,int v) : vector<vector<T>>(H){
			REP(y,H)this->at(y)=vector<T>(W,v);
		}
		const Mat I(int H,int W){
			Mat A(H,W);
			REP(y,H)REP(x,W)A[y][x]=Ae;
			REP(i,min(H,W))A[i][i]=Me;
			return A;
		}
		//O(n^2)
		Mat operator+(const Mat& r){
			const Mat& l=*this;
			assert(H(r)==H(l) && W(l)==W(r));
			Mat res(H(l),W(r));
			REP(y,H(l))REP(x,W(r)) res[y][x]=A(l[y][x],r[y][x]);
			return res;
		}
		//O(n^2)
		Mat operator-(const Mat& r){
			const Mat& l=*this;
			assert(H(r)==H(l) && W(l)==W(r));
			Mat res(H(l),W(r));
			REP(y,H(l))REP(x,W(r)) res[y][x]=S(l[y][x],r[y][x]);
			return res;
		}
	    //O(LH*N*RW) O  (n^3)
		Mat operator*(const Mat& r){
			const Mat& l=*this;
			assert(H(r)==W(l));
			Mat res(H(l),W(r));
			REP(y,H(l))REP(x,W(r))
				REP(k,H(r)) res[y][x]=A(res[y][x],M(l[y][k],r[k][x]));
			return res;
		}

		//O(n^2)
		vector<T> operator*(const vector<T>& r){
			const Mat& l=*this;
			vector<T> res(r.size());
			REP(y,H(l))REP(x,W(l))res[y]=A(res[y],M(l[y][x],r[x]));
			return res;
		}

		// O(n^3*log(v))
		// Mat x must be n*n size
		Mat pow(T v){
			Mat x=*this,res=I(H(x),W(x));

			while(v!=0){
				if(v%2)res=res*x;
				x=x*x;
				v/=2;
			}
			return res;
		}

		// //連立方程式
		// const int gf=2;
		// T mod(T v){return mod(v,gf);}
		// T inv(T v){return invs[v];}

		//O(n^3)
		//Ax = b
		void gauss(vector<T>& b){
			Mat A=*this;
			const int H = H(A),W=W(A);
			int py =0,px = 0;
			while(py < H && px < W){
				for(int y=py+1;y<H;y++){ // pivot
					if(sig(abs(A[y][px]),abs(A[py][px]))> 0){
						swap(A[y],A[py]);swap(b[y],b[py]);
					}
				}
				if(sig(A[py][px]) != 0){
					T d = Minv(A[py][px]);
					for(int x=0;x<W;x++) A[py][x] =M(A[py][x],d);
					b[py] = M(b[py],d);
					for(int y=py+1;y<H;y++){
						T k = A[y][px];
						for(int x=0;x<W;x++) A[y][x] = A[y][x]-k*A[py][x];
						b[y] = b[y]-k*b[py];
					}
					py++;
				}
				px++;
			}
			for(int y=py;y<H;y++)if(sig(b[y]) != 0)throw NoSolution();
			if(py < W || px < W)throw Ambiguous();

			for(int x=W-1;x>=0;x--)for(int y=0;y<x;y++){
				b[y] = b[y] -b[x]*A[y][x];
			}
		}

	};
}
using namespace Matrix;

class Main{
	public:
	void run(){
		int T;cin >> T;
		vector<string> words = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
		vector<map<char,int>> wmap(10);
		for(int i:range(10)){
			for(char c:words[i])wmap[i][c]++;
		}
		Mat<D> mat(26,10);
		for(char c ='A';c<='Z';c++)for(int i:range(10))mat[c-'A'][i] = wmap[i][c];

		for(int q:range(T)){
			string s;cin >> s;
			map<char,int> cs;
			for(char c:s)cs[c]++;
			vector<D> bs(26);
			for(char c ='A';c<='Z';c++)bs[c-'A'] = cs[c];
			mat.gauss(bs);
			string r="";
			for(int i:range(10))for(int j:range((ll)(bs[i]+0.5)))r += i+'0';
			cout << make_tuple("Case","#"+to_string(q+1)+":",r)<<endl;
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
