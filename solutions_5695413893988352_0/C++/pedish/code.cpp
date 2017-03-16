#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <string>
#include <queue>
#include <functional>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <string.h>
using namespace std;

namespace{
	#define		CAST( T, val )		( (T)( val ) )
	#define		CASE( lb )			break; case lb:
	#define		CASE_CONTINUE( lb )	case lb:
	#define		CASE_DEFAULT		break; default:
	#define		For( i, s )			for(int i= 0, forEnd##i= CAST( int, s ); i< forEnd##i; i++)
	#define		ForA( i, a, s )		for(int i= CAST( int, a ), forEnd##i= CAST( int, s ); i< forEnd##i; i++)
	#define		ForItr( itr, con )	for(auto itr= con.begin(), forEnd##itr= con.end(); itr!= forEnd##itr; itr++)
	#define		ForStr( i, str )	for(int i= 0; str[i]; i++)
	#define		GOTO( lb )			goto lb
	#define		LABEL( lb )			lb:
	#define		ALL( con )			con.begin(), con.end()

	typedef		long long			Lint;
	typedef		unsigned long long	ULint;
	typedef		unsigned int		Uint;
	typedef		unsigned char		Uchar;
	typedef		unsigned short		Ushort;

	const int Ten5 = 100000;		//	10^5
	const int Ten6 = 1000000;	//	10^6
	const double EPS = 0.00000000023283064365386962890625;	//	2^-32
}
namespace c{
	//	合同式
	class Mod{public:
		typedef	int	Type;	//	型
		static Type N;	//	法
		
		const Mod operator +(const Mod& m) const{ return Mod(x+m.x); }
		const Mod& operator +=(const Mod& m){ return *this= Mod(x+m.x); }
		Mod operator -(const Mod& m) const{ return Mod(x-m.x+N); }
		const Mod& operator -=(const Mod& m){ return *this= Mod(x-m.x+N); }
		Mod operator *(const Mod& m) const{ return Mod(x*m.x); }
		const Mod& operator *=(const Mod& m){ return *this= Mod(x*m.x); }
		Mod operator /(const Mod& m) const{ //	フェルマーの小定理より, m.x の逆元は m.x^( HOU-2 )
			const Type n= N-2; Type p= m.x, r= x; for(Type b= 1; b< n; b<<= 1){ if( n & b ) r= r*p%N; p= p*p%N; } return r;
		}
		const Mod& operator /=(const Mod& m){ return *this= *this /m; }
		operator const Type&() const{return x;}
		Mod(){}
		Mod(Type v):x(v%N){}
	private:Type x;}; Mod::Type Mod::N= 1000000007;
	//	最大値
	template <typename T> class Max{public:
		//	何回更新したか
		int cnt() const{return c;}

		//	更新したときに true を返す
		bool operator =(const T&v){if(!c){c=1;x=v;return true;}if(x<v){c++;x=v;return true;}return false;}

		operator const T&() const{return x;}
		Max():x(0),c(0){}
		Max(const T&v):x(v),c(1){}
		Max(const T*f,const T*l):x(*f++),c(1){while(f<l){*this=*f++;}}
		Max(const T*a,int n):x(0),c(0){For(i,n)*this=*a++;}
	private:T x;int c;};
	//	最小値
	template <typename T> class Min{public:
		//	何回更新したか
		int cnt() const{return c;}

		//	更新したときに true を返す
		bool operator =(const T&v){if(!c){c=1;x=v;return true;}if(v<x){c++;x=v;return true;}return false;}

		operator const T&() const{return x;}
		Min():x(0),c(0){}
		Min(const T&v):x(v),c(1){}
		Min(const T*f,const T*l):x(*f++),c(1){while(f<l){*this=*f++;}}
		Min(const T*a,int n):x(0),c(0){For(i,n)*this=*a++;}
	private:T x;int c;};
	istream& operator >>(istream&in,Mod&m){Mod::Type t;in>>t;m=Mod(t);return in;}
	ostream& operator <<(ostream&ot,const Mod&m){return ot<<CAST(Mod::Type,m);}
	template <typename T> istream& operator >>(istream&in,Max<T>&m){T t;in>>t;m=Max<T>(t);return in;}
	template <typename T> ostream& operator <<(ostream&ot,const Max<T>&m){return ot<<CAST(T,m);}
	template <typename T> istream& operator >>(istream&in,Min<T>&m){T t;in>>t;m=Min<T>(t);return in;}
	template <typename T> ostream& operator <<(ostream&ot,const Min<T>&m){return ot<<CAST(T,m);}

	//	素数判定
	bool isPrime(const int x){ if( x <= 1 ) return false; for(int i= 2, s= CAST( int, sqrt( x ) ); i<= s; i++) if( x%i== 0 ) return false; return true; }
	//	v の p 乗を高速に計算
	template <typename T, typename U> T power(T v, U p){ T r= 1; while(p){ if( p & 1 ) r*= v; p>>= 1; v*= v; } return r; }
}
namespace c{
	//	2D int Vector
	class Pint{
	public:
		int x, y;
		static const Pint dir[8];

		//	util
		static void fldWH(const int width, const int height){ Width= width; Height= height; }
		inline bool isInFld() const{ return 0 <= x && x < Width && 0 <= y && y < Height; }
		inline void swap(){ int t= x; x= y; y= t; }

		//	vector
		inline double len() const{ return sqrt( sq() ); }
		inline double len(const Pint& p) const{ return sqrt( sq(p) ); }
		inline int sq() const{ return x*x+y*y; }
		inline int sq(const Pint& p) const{ return (x-p.x)*(x-p.x) +(y-p.y)*(y-p.y); }
		inline int manhattan() const{ return abs(x) +abs(y); }
		inline int manhattan(const Pint& p) const{ return abs(x-p.x) +abs(y-p.y); }
		inline int dot(const Pint& p) const{ return x*p.x+y*p.y; }
		inline int crs(const Pint& p) const{ return x*p.y-y*p.x; }

		//	opr, cst
		inline Pint operator +(){ return Pint( x, y ); }
		inline Pint operator -(){ return Pint( -x, -y ); }
		inline Pint operator +(const Pint& p) const{ return Pint( x+p.x, y+p.y ); }
		inline const Pint& operator +=(const Pint& p){ x+= p.x; y+= p.y; return *this; }
		inline Pint operator -(const Pint& p) const{ return Pint( x-p.x, y-p.y ); }
		inline const Pint& operator -=(const Pint& p){ x-= p.x; y-= p.y; return *this; }
		inline Pint operator *(const Pint& p) const{ return Pint( x*p.x, y*p.y ); }
		inline const Pint& operator *=(const Pint& p){ x*= p.x; y*= p.y; return *this; }
		inline Pint operator /(const Pint& p) const{ return Pint( x/p.x, y/p.y ); }
		inline const Pint& operator /=(const Pint& p){ x/= p.x; y/= p.y; return *this; }
		inline Pint operator *(const int k) const{ return Pint( x*k, y*k ); }
		inline const Pint& operator *=(const int k){ x*= k; y*= k; return *this; }
		inline Pint operator /(const int k) const{ return Pint( x/k, y/k ); }
		inline const Pint& operator /=(const int k){ x/= k; y/= k; return *this; }
		inline bool operator <(const Pint& p) const{ return x== p.x ? y<p.y : x<p.x; }
		inline bool operator >(const Pint& p) const{ return x== p.x ? y>p.y : x>p.x; }
		inline bool operator ==(const Pint& p) const{ return x==p.x && y==p.y; }
		inline bool operator !=(const Pint& p) const{ return x!=p.x || y!=p.y; }
		Pint(){}
		Pint(const int x, const int y) : x(x), y(y){}
		
	private:
		static int Width, Height;
	};
	istream& operator >>(istream& in, Pint& p){
		return in>> p.x>> p.y;
	}
	ostream& operator <<(ostream& out, const Pint& p){
		return out<< "( "<< p.x<< ", "<< p.y<< " )";
	}
	int Pint::Width, Pint::Height;
	const Pint Pint::dir[8]= { Pint(0,1),Pint(1,0),Pint(0,-1),Pint(-1,0),Pint(1,1),Pint(1,-1),Pint(-1,1),Pint(-1,-1) };

	//	2D double Vector
	class Pdouble{
	public:
		double x, y;

		//	vector
		inline double len() const{ return sqrt( sq() ); }
		inline double len(const Pdouble& p) const{ return sqrt( sq(p) ); }
		inline double sq() const{ return x*x+y*y; }
		inline double sq(const Pdouble& p) const{ return (x-p.x)*(x-p.x) +(y-p.y)*(y-p.y); }
		inline Pdouble norm(const double l= 1.0){ return *this * l /len(); }
		inline double dot(const Pdouble& p) const{ return x*p.x+y*p.y; }
		inline double crs(const Pdouble& p) const{ return x*p.y-y*p.x; }
		inline Pdouble proj(const Pdouble& v) const{
			const double s= v.sq();
			if( s < EPS*EPS ) return Pdouble( 0, 0 );
			return v *dot( v ) /s;
		}
		inline Pdouble rot(const double rad) const{ const double c= cos( rad ), s= sin( rad ); return Pdouble( c*x-s*y, s*x+c*y ); }

		//	opr, cst
		inline Pdouble operator +(){ return Pdouble( x, y ); }
		inline Pdouble operator -(){ return Pdouble( -x, -y ); }
		inline Pdouble operator +(const Pdouble& p) const{ return Pdouble( x+p.x, y+p.y ); }
		inline const Pdouble& operator +=(const Pdouble& p){ x+= p.x; y+= p.y; }
		inline Pdouble operator -(const Pdouble& p) const{ return Pdouble( x-p.x, y-p.y ); }
		inline const Pdouble& operator -=(const Pdouble& p){ x-= p.x; y-= p.y; }
		inline Pdouble operator *(const Pdouble& p) const{ return Pdouble( x*p.x, y*p.y ); }
		inline const Pdouble& operator *=(const Pdouble& p){ x*= p.x; y*= p.y; }
		inline Pdouble operator /(const Pdouble& p) const{ return Pdouble( x/p.x, y/p.y ); }
		inline const Pdouble& operator /=(const Pdouble& p){ x/= p.x; y/= p.y; }
		inline Pdouble operator *(const double k) const{ return Pdouble( x*k, y*k ); }
		inline const Pdouble& operator *=(const double k){ x*= k; y*= k; }
		inline Pdouble operator /(const double k) const{ return Pdouble( x/k, y/k ); }
		inline const Pdouble& operator /=(const double k){ x/= k; y/= k; }
		inline bool operator <(const Pdouble& p) const{ return x== p.x ? y<p.y : x<p.x; }
		inline bool operator >(const Pdouble& p) const{ return x== p.x ? y>p.y : x>p.x; }
		inline bool operator ==(const Pdouble& p) const{ return x==p.x && y==p.y; }
		inline bool operator !=(const Pdouble& p) const{ return x!=p.x || y!=p.y; }
		Pdouble(){}
		Pdouble(const double x, const double y) : x(x), y(y){}
		Pdouble(const Pint& p) : x(p.x), y(p.y){}
	};
	istream& operator >>(istream& in, Pdouble& p){
		return in>> p.x>> p.y;
	}
	ostream& operator <<(ostream& out, const Pdouble& p){
		return out<< "( "<< p.x<< ", "<< p.y<< " )";
	}

	//	( lP, lQ ) と ( nP, nQ ) の線分の交差判定
	bool CollisionLine(const Pdouble lP, const Pdouble lQ, const Pdouble nP, const Pdouble nQ){
		auto sign= [](double d){ return d < 0 ? -1 : d > 0 ? 1 : 0; };
		Pdouble v= lQ-lP; if( sign( v.crs( nP -lP ) )== sign( v.crs( nQ -lQ ) ) ) return false;
		v= nQ -nP; return sign( v.crs( lP -nP ) ) * sign( v.crs( lQ -nP ) ) <= 0;
	}
}
namespace c{
	//	Union Find
	class UnionFind{
	public:
		//	x, y は同じ
		void uniom(int x, int y){ mP[ find(x) ]= find(y); }
		//	x の親を取得
		int find(int x){ return mP[x]== x ? x : mP[x]= find( mP[x] ); }
		//	x が属する集合の親を x にする
		void toBeParent(int x){ mP[ find( x ) ]= x; mP[x]= x; }

		//	要素数 N, [ 0, N )
		UnionFind(int N) : mP(N){ For( i, N ) mP[i]= i; }
	private:
		std::vector<int> mP;
	};
}

void pushAll(vector<int>& vec, const char* c, int x){
	if( *c ){
		if( *c== '?' ){
			For( k, 10 ) pushAll( vec, c+1, x*10+k );
		}else{
			pushAll( vec, c+1, x*10+*c-'0' );
		}
	}else{
		vec.push_back( x );
	}
}

void init(){}
void solve(){
	char C[24], J[24];
	cin>> C>> J;
	int len= strlen( C );

	vector<int> c, j;
	pushAll( c, C, 0 );
	pushAll( j, J, 0 );

	c::Min<int> Abs;
	int out1, out2;
	ForItr( i, c ) ForItr( k, j ){
		if( Abs = abs( *i- *k ) ){
			out1= *i;
			out2= *k;
		}else if( Abs== abs( *i -*k ) ){
			bool up= false;
			if( *i > *k ){
				if( out1 > out2 ){
					up= true;
				}
			}else{
				up= true;
			}

			if( up ){
				if( out1 + out2 > *i +*k ){
					out1= *i;
					out2= *k;
				}
			}
		}
	}

	char fmt[256];
	sprintf( fmt, "%%0%dd", len );
	printf( fmt, out1 );
	printf( " " );
	printf( fmt, out2 );
}
int main(){
	init();
	int cnt;
	cin>> cnt;
	For( i, cnt ){
#ifndef	_DEBUG
		fprintf( stderr, "#%d\n", i+1 );
#endif
		printf( "Case #%d: ", i+1 );
		solve();
		puts("");
	}

	return 0;
}
