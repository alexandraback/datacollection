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
char B[31][31];

template<typename T> T sqr(T t){ return t*t;}
int gcd(int a, int b){
	if( b == 0) return a;
	return gcd( b, a%b);
}


int main(int argc, char *argv[]){
	bool out = true;
	#ifndef ONLINE_JUDGE
		freopen("d:/home/code/GCJ/Dd.txt","r",stdin);
		if( out){
			freopen("d:/home/code/GCJ/Out.txt","w",stdout);
		}
	#endif
	int nt = getnum<int>();
	for(int j = 1; j <= nt; ++j){
		memset(B,0,sizeof(B));
		int H = getnum<int>();
		int W = getnum<int>();
		int D = getnum<int>();
		int fr=0, fc=0;
		int res = 0;
		REP(i,H){
			gets(B[i]);
		}
		REP(i,H)REP(j,W){
			if( B[i][j] == 'X' ){
				fr = i, fc = j;
			}
		}

		for( int xr = fr-D; xr <= fr+D; xr++){
			for( int xc = fc-D; xc <= fc+D; xc++){
				if( sqr(xr-fr) + sqr(xc-fc) > D*D )
					continue;
				int dr = xr-fr, dc = xc-fc;
				int d = gcd(abs(dr),abs(dc));
				if( d != 1 )
					continue;
				int sr = dr < 0 ? -1 : dr > 0 ? 1 : 0;
				int sc = dc < 0 ? -1 : dc > 0 ? 1 : 0;

				int step = dr *dc == 0 ? 1 : abs(dr*dc);

				int cr = (2*fr+1)*step, cc = (2*fc +1)*step;
				int nsteps = int(sqrt(sqr(2.*D*step) / ( sqr( dr)+sqr(dc) ))+1e-7);
				for(int ns = 1; ns <= nsteps; ++ns){
					cr += dr, cc +=dc;
					int yr = cr/step, yc = cc / step;
					int r = yr/2, c = yc/2;
					if( cr % step == 0 && cc % step == 0 && yr%2 == 1 && yc %2 == 1 ){
						if( B[r][c] == 'X' ){
							res++; break;
						}
					} else if(cr % step == 0 && cc % step == 0 && yr%2 == 0 && yc%2 == 0 ){
						ii diag, vert, horz;
						if( dr < 0 && dc < 0 ){
							diag = ii( r-1,c-1);
							vert = ii( r-1,c);
							horz = ii( r, c-1);
						} else if( dr < 0 && dc > 0 ){
							diag = ii( r-1,c );
							vert = ii( r-1,c-1 );
							horz = ii( r, c);
						} else if( dr > 0 && dc < 0 ){
							diag = ii( r,c-1 );
							vert = ii( r,c );
							horz = ii( r-1, c-1);
						} else if( dr > 0 && dc > 0 ){
							diag = ii( r,c );
							vert = ii( r,c-1 );
							horz = ii( r-1, c);
						}
					
						if( B[diag.first][diag.second] == '#' ){
							if( B[vert.first][vert.second] != '#' ){
								if( B[horz.first][horz.second] != '#' ){
									break; // ray dies. 
								} else {
									dc = -dc;
								}
							} else {
								if( B[horz.first][horz.second] != '#' ){
									dr = -dr;
								} else {
									dr = -dr, dc = -dc;
								}
							}
						}
					} else {
						if(cr % step == 0 && yr%2 == 0){
							if( dr < 0 ){ 
								if( B[r-1][c] == '#' ) 
									dr = -dr;
							} else if( dr > 0 ){
								if( B[r][c] == '#' ) 
									dr = -dr;
							}
						} 
						if(cc % step == 0 && yc%2 == 0){
							if( dc < 0 ){ 
								if( B[r][c-1] == '#' ) 
									dc = -dc;
							} else if( dc > 0 ){ 
								if( B[r][c] == '#' ) 
									dc = -dc;
							}
						}
					}
				}
			}
		}

		//for(int i = 0; i < 256; ++i){
		//	printf("%s\n",B[i]);
		//}
		printf( "Case #%d: ", j);
		printf("%d\n", res);
		fflush(stdout);
	}
	return 0;
}
