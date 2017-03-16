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

int S[201];

char buf[10000000];
int main(int argc, char *argv[]){
	bool out = true;
	#ifndef ONLINE_JUDGE
		freopen("d:/home/code/GCJ/Aa.txt","r",stdin);
		if( out){
			freopen("d:/home/code/GCJ/Out.txt","w",stdout);
		}
	#endif
	
	int nt = getnum<int>();
	for(int j = 1; j <= nt; ++j){
		int N = getnum<int>();
		int T = 0;
		for(int i = 0; i < N; ++i){
			S[i] = getnum<int>();
			T += S[i];
		}
		double U = (2.*T)/N;
		printf( "Case #%d:", j);
		for(int i = 0; i < N; ++i){
			double d = max(U-S[i],0.)/T;
			printf(" %.15f", 100.*d );
		}
		printf("\n");
			
		fflush(stdout);
	}
	return 0;
}
