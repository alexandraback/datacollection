// =====================================================================================
//       Filename:  Cookie.cpp
//    Description:  
//        Created:  04/12/2014 11:20:59 AM
//         Author:  BrOkEN@!
// =====================================================================================

#include<fstream>
#include<iostream>
#include<sstream>
#include<bitset>
#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>
#include<cassert>
#include<cctype>
#include<climits>
#include<cmath>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>

using namespace std;

template< class T > inline T _maxOfThree(T a,T b,T c) {return max(max(a,b),c);}
template< class T > inline T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _square(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool in_range(T x, T i, T y) { return x<=i && i<=y; }

#define FOR(i,a,b) for(typeof((a)) i=(a); i <= (b) ; ++i)
#define REV_FOR(i,a,b) for(typeof((a)) i=(a); i >= (b) ; --i)
#define FOREACH(it,x) for(typeof((x).begin()) it=(x).begin(); it != (x).end() ; ++it)
#define REV_FOREACH(it,x) for(typeof((x).rbegin()) it=(x).rbegin(); it != (x).rend() ; ++it)
#define SET(p, v) memset(p, v, sizeof(p))
#define CLR(p) SET(p,0)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ARRAY_SIZE(array) (sizeof(array) / sizeof((array)[0]))
#define __int64 long long

typedef pair<int,int> PI;
typedef vector<PI> VI;


const double EPS = 1e-9;

double C,F,X;

int CompareDouble(double a, double b){
	if(a < b - EPS)	return -1;
	if(a > b + EPS)	return 1;
	return 0;
}


double solve(){

	double time = 0.0F;
	double R = 2.0F;

	while(CompareDouble( (X/R) , (C/R) + (X/(R+F)) ) > 0){
		time += C/R;
		R += F;
	}
	time += X/R;
		
	return time;
}


int main(){
	int T=0;
	scanf("%d",&T);
	FOR(t,1,T){
		scanf("%lf%lf%lf",&C,&F,&X);
		printf("Case #%d: %.7f\n",t,solve());
	}
	return 0;
}

