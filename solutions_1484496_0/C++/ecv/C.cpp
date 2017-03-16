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
int a[20];
int S[10000000];
vi xtr(int n){
	vi res;
	for(int t = 0; t < 20; ++t){
		if( n& (1<<t) ){
			res.push_back(a[t]);
		}
	}
	return res;
}

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
		int N = getnum<int>();
		memset(S,0,sizeof(S));
		for(int i = 0; i < N; ++i){
			a[i] = getnum<int>();
		}
		sort(a,a+N);
		int n1 = -1, n2 = -1;
		for(int n = 1; n < (1<<20); ++n){
			int sum = 0;
			for(int t = 0; t < 20; ++t){
				if( n & (1<<t) ){
					sum += a[t];
				}
			}
			if( S[sum] != 0 ){
				vi x1 = xtr(n);
				vi x2 = xtr(S[sum]);
				if( x1 != x2 ){
					n1 = n, n2 = S[sum];
					break;
				}
			}
			S[sum] = n;
		}
		printf( "Case #%d:\n", j);
		if( n1 == -1){
			printf( "Impossible\n");
		} else {
			vi r = xtr(n1);
			for(int t = 0; t < r.size(); ++t){
				if( t >  0) printf(" ");
				printf("%d",r[t]);
			}
			printf("\n");
			r = xtr(n2);
			for(int t = 0; t < r.size(); ++t){
				if( t >  0) printf(" ");
				printf("%d",r[t]);
			}
			printf("\n");
		}
		fflush(stdout);
	}
	return 0;
}
