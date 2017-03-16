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
typedef long long int Int;

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
char buf[1000002];
int B[1000002];
int main(int argc, char *argv[]){
	bool out = true;
	#ifndef ONLINE_JUDGE
		freopen("A.txt","r",stdin);
		if( out){
			freopen("Out.txt","w",stdout);
		}
	#endif
	int nt;
	scanf( "%d ", &nt);
	for(int numt = 1; numt <= nt; ++numt){
		int n;
		scanf("%s %d ", &buf, &n);
		int m = strlen(buf);
		int c = 0;
		int lst = -1;
		vi D;
		memset(B,0,sizeof(B));
		int u;
		for(int j = 0; j < m; ++j){
			bool v =  (buf[j] == 'a') | (buf[j] == 'e') | (buf[j] == 'i') | (buf[j] == 'o') | (buf[j] == 'u');
			if(v) c = 0; else c++;
			if( c>=n){
				u = j;
				if(lst != -1)
					u = j-lst+n-2;
				if( u >=n){
					D.push_back(u);
				}
				lst = j;
			}
		}
		u = m;
		if(lst!=-1){
			u = m-lst+n-2;
		}
		if( u >=n){
			D.push_back(u);
		}
		for(int k = 0; k < sz(D); ++k){
			B[D[k]]++;
		}
		Int a = Int(m-n+1)*Int(m-n+2)/2;
		for(int j = n; j <= m; ++j){
			Int b = Int(j-n+1)*Int(j-n+2)/2;
			a-=b*B[j];
		}



		printf( "Case #%d: ", numt);
		printf( "%lld\n", a);
		fflush(stdout);
	}
	return 0;
}
