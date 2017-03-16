// =====================================================================================
//       Filename:  dwar.cpp
//    Description:  
//        Created:  04/12/2014 02:08:13 PM
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

const int NMAX = 1005;
int naomi[NMAX],ken[NMAX];
int N;

int fair(){
	int k_win=0,i=0,j=0;	
	
	while(i<N && j<N){
		if(naomi[i]<ken[j]){	//ken can beat naomi
			k_win++;
			i++;
			j++;
		}else{
			j++;	
		}
	}	
	
	return N-k_win;
}

int unfair(){
	int d_win=0,i=0,j=0;

	while(i<N && j<N){
		if(naomi[i]>ken[j]){//naomi can beat ken
			d_win++;
			i++;
			j++;
		}else{	// naomi can't beat ken, she fakes it for the highest of ken
			i++;
		}
	}

	return d_win;
}

void solve(int tc){
	sort(naomi,naomi+N);
	sort(ken,ken+N);
	printf("Case #%d: %d %d\n",tc,unfair(),fair());	
}


int main(){
	int T=0;
	scanf("%d",&T);
	int zero;
	FOR(t,1,T){
		CLR(naomi),CLR(ken);
		scanf("%d",&N);
		FOR(i,0,N-1)	scanf("%d.%d",&zero,&naomi[i]);
		FOR(i,0,N-1)	scanf("%d.%d",&zero,&ken[i]);
		solve(t);
	}
	return 0;
}

