
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <sstream>
#include <limits>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <string.h>

using namespace std;
#define ALL(x) x.begin(),x.end()
// Typedefs
typedef long long llint;
// Vector typedefs
typedef vector<int> intv; typedef vector<llint> llintv; typedef vector<double> doublev;

template<typename T> struct V2T { T x, y; bool operator!=(const V2T&o)const{return o.x!=x || o.y!=y;} }; typedef V2T<int> V2; typedef V2T<llint> V2LL;
template<typename T> ostream & operator<<( ostream & o, V2T<T> v ) { o << v.x << "," << v.y; return o; }

// for(int i:Range(n)) doIt(i);

template<typename T> struct IterT{ T i; IterT(T _i): i(_i){} IterT<T> & operator++() {++i;return *this;} bool operator!=(const IterT<T> & o) { return o.i!=i; } T operator*() const {return i;} };
typedef IterT<int> Iter;
template<typename T> struct RangeT{ T b=0,e; RangeT(T _e):e(_e){} RangeT(T _b,T _e):b(_b),e(_e){} IterT<T> begin(){return b;} IterT<T> end(){return e;}};
typedef RangeT<llint> LLRange; typedef RangeT<int> Range;

template<typename T> T vnext(const T & v, const T & lim) { T ret(v); if(++ret.x>=lim.x&&++ret.y<lim.y){ret.x = 0;} return ret;}
typedef IterT<int> Iter;
template<typename T> struct V2RangeT{
	struct I{ V2RangeT & r; T v; I(V2RangeT &_r,T _v):r(_r),v(_v){} I & operator++() { v=vnext(v,r.e); return *this; }
	bool operator!=(const I & o)const{ return o.v!=v; } T operator*() const {return v;} };
	T b={0,0},e; V2RangeT(T _e):e(_e){} V2RangeT(T _b,T _e):b(_b),e(_e){} I begin(){return I(*this,b);} I end(){return I(*this,e);}};
typedef V2RangeT<V2> V2Range; typedef V2RangeT<V2LL> V2LLRange;

// intv v(10); set_range(v); // 0..9
template<typename T,typename I=typename T::value_type> void set_range( T & c, I i=0 ) { for(auto & v:c) v=i++; }
//	for(V2LL n:Adj8LL({1,1},{2,2})) cout << n.x << n.y << endl;
struct AdjBase {static int XO[], YO[];};  int AdjBase::XO [] = { 0, 0, 1, -1, 1, -1, -1, 1,0 }; int AdjBase::YO [] = { -1, 1, 0, 0, -1, 1, -1, 1, 0 };
template<typename T,int CNT=4> struct AdjT : AdjBase {
	T start, high, low;
	struct I:Iter{AdjT a;I(AdjT&_a,int pos=0):Iter(pos),a(_a){while(!a.has(i))i++;} T operator*() const {return a.at(i);} Iter & operator++() { while(!a.has(++i)){}return *this;}};
	AdjT(const T&s,const T&h,const T&l=T{0,0}):start(s),high(h),low(l){}
	I begin() { return I(*this); } I end() { return I(*this,CNT); }
	bool has(int i) { if(i>=CNT) return true; T chk=at(i); return (low.x <= chk.x) && (chk.x < high.x) && (low.y <= chk.y) && (chk.y < high.y); }
	T at(int i) const { if(i>=CNT) return start; return T{start.x+XO[i],start.y+YO[i]}; }
}; typedef AdjT<V2> Adj; typedef AdjT<V2,8> Adj8; typedef AdjT<V2LL> AdjLL; typedef AdjT<V2LL,8> Adj8LL;

void nextline( istream & s ) { if( s.peek() == '\n' ) s.ignore(); }
string rdline( istream & s ) { nextline(s); string l; getline(s,l); return l; }

template<typename C,typename T=typename C::value_type> int lnpushvals( istream & s, C & c )
{ string l = rdline(s); istringstream ss(l); int sz = c.size(); copy( istream_iterator<T>(ss), istream_iterator<T>(), back_inserter(c) ); return c.size()-sz; }
template<typename C,typename T=typename C::value_type> void lnreadvals( istream & s, typename C::iterator & it )
{ string l = rdline(s); istringstream ss(l); copy( istream_iterator<T>(ss), istream_iterator<T>(), it ); }
//readvals(fin,ALL(vals));
template<typename C,typename T=typename C::value_type> void readvals( istream & s, C it, C end ){ for(;it!=end;++it) s >> *it; }
//	writevals(fout,vals);
template<typename C> void writevals( ostream & s, const C & c ) { copy(ALL(c), ostream_iterator<typename C::value_type>(s, " ")); }
template<typename T> ostream & operator << ( ostream & o, const vector<T> & v ) { writevals(o,v); return o; }

llint _binom(int,int);
#define BINOM_C 100
inline llint binom(int n, int k)
{
	static llint cache[BINOM_C][BINOM_C];
	llint ph=0; llint & c = (n<BINOM_C&&k<BINOM_C) ? cache[n][k] : ph;
	return c ? c : c=_binom(n,k);
}

llint _binom(int n, int k)
{
	if( n < 0 ) return 0;
	if( n==k || k == 0 ) return 1;
	return binom(n-1,k-1) + binom(n-1,k);
}

void run(istream &, ostream &);
int main(int argc,char * argv[])
{
	ifstream fin(argc > 1 ? argv[1] : 0);
	ofstream fout(argc > 2 ? argv[2] : 0);
	run(fin.good() ? fin : cin, fout.good() ? fout : cout);
}


void run(istream & fin, ostream & fout)
{
	int cases;
	fin >> cases;
	fin.ignore();
	for(int t:Range(cases)) {
		double ck=0.0, ps=2.0, c, f, x;
		fin >> c >> f >> x;
		double ttw = x / ps;
		double time_last_farm=0.0;
		do {
			time_last_farm += c / ps;
			ps += f;
			double nttw = x / ps + time_last_farm;
			if( nttw > ttw ) break;
			ttw = nttw;
		} while(true);
		fout.setf( ios::fixed );
		fout << "Case #" << (t+1) << ": " << setprecision(7) << ttw << endl;
	}
}

