#pragma warning(disable : 4996)
#include <cstdio>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int,int> ii;
typedef std::vector<ii> vii;
typedef std::vector<string> vs;
typedef std::vector<double> vd;

#define sz(a) int(a.size())
#define REP(i,n) for(int i = 0; i < n; ++i)
#define FOR(i,a) for(int i = 0; i < sz(a); ++i)

inline bool isdig(int a){return unsigned(a-'0') < 10;}
template<class T> static inline T getnum(){
   unsigned i; T j;
   do i = getchar(); while(!isdig(i));
   j = i-'0';  i=getchar() ;
   while(isdig(i)){ j = (j<<1)+(j<<3)+(i-'0'); i = getchar(); }
   return j;
}

int N, T;
vi G;


int main(int argc, char *argv[]){
	bool out = true;
	#ifndef ONLINE_JUDGE
		freopen("d:/home/code/GCJ/Cc.txt","r",stdin);
		if( out){
			freopen("d:/home/code/GCJ/Out.txt","w",stdout);
		}
	#endif
	int nt = getnum<int>();
	for(int j = 1; j <= nt; ++j){
		int A = getnum<int>();
		int B = getnum<int>();
		int d = 0; 
		int M = 1;
		while( M <= B ){
			++d, M *= 10; 
		}
		int res = 0;
		if( d > 1 ) {
			for(int n = A; n <= B; ++n){
				set<int> P; P.insert(n);
				int m1 = n;
				for(int i = 1; i < d; ++i){
					m1 = m1/10 + (M/10)*(m1%10);
					if( A <= m1 && m1 <= B){
						P.insert(m1);
					}
				}
				if( n  == *P.begin()){
					int inc = (P.size()*(P.size()-1))/2;
					res += inc;
				}
			}
		}

		printf( "Case #%d: ", j);
		printf("%d\n", res);
		fflush(stdout);
	}
	return 0;
}
