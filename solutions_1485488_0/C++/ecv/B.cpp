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
typedef std::pair<int,ii> iii;
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


int F[100][100];
int C[100][100];
int t1[100][100][4];
int t2[100][100];
int seen[100][100];
int seen2[100][100];
int bt[100][100];
int vert[] = {-1,0,1,0};
int horz[] = {0,1,0,-1};
int main(int argc, char *argv[]){
	bool out = true;
	#ifndef ONLINE_JUDGE
		freopen("d:/home/code/GCJ/Bb.txt","r",stdin);
		if( out){
			freopen("d:/home/code/GCJ/Out.txt","w",stdout);
		}
	#endif
	int nt = getnum<int>();
	for(int j = 1; j <= nt; ++j){
		int H = getnum<int>();
		int N = getnum<int>();
		int M = getnum<int>();
		memset(t1,0,sizeof(t1));
		memset(t2,0,sizeof(t2));
		for(int r = 0; r < N; ++r){
			for(int c = 0; c < M; ++c){
				C[r][c] = getnum<int>();
			}
		}
		for(int r = 0; r < N; ++r){
			for(int c = 0; c < M; ++c){
				F[r][c] = getnum<int>();
			}
		}

		for(int r = 0; r < N; ++r){
			for(int c = 0; c < M; ++c){
				for(int d = 0; d < 4; ++d){
					int r1 = r + vert[d];
					int c1 = c + horz[d];
					if( r1 < 0 || r1 >= N || c1 < 0 || c1 >= M ){
						t1[r][c][d] = -1;
						continue;
					}
					if( C[r1][c1] - F[r][c] < 50 || 
						C[r1][c1] - F[r1][c1] < 50 || 
						C[r][c]-F[r1][c1] < 50) {
							t1[r][c][d] = -1;
							continue;
					}
					if( C[r1][c1] - H < 50 )
						t1[r][c][d] = (H-(C[r1][c1]-50));
				}
				if( H >= F[r][c]+20 )
					t2[r][c] = H-F[r][c]-20;
			}
		}
		memset(seen,0,sizeof(seen));
		queue<ii> Q;
		Q.push(ii(0,0));
		seen[0][0] = 1;
		while( !Q.empty() ){
			int cr = Q.front().first, cc = Q.front().second;Q.pop();
			for(int d = 0; d < 4; ++d){
				if( t1[cr][cc][d] == 0 ){
					int cr1 = cr + vert[d], cc1 = cc + horz[d];
					if( ! seen[cr1][cc1] ){
						seen[cr1][cc1] = 1;
						Q.push(ii(cr1,cc1));
					}
				}
			}
		}

		/*
		vii ini;
		for(int r = 0; r < N; ++r){
			for(int c = 0; c < M; ++c){
				if( seen[r][c] ){
					ini.push_back(ii(r,c));
				}
			}
		}
		*/
		
		int bestt = 1000000000;
		for(int pr = 0; pr < N; ++pr){
			for(int pc = 0; pc < M; ++pc){
				if( seen[pr][pc] ){
					priority_queue<iii> QQ;
					QQ.push(iii(0,ii(pr,pc)));
					for(int r = 0; r < N; ++r){
						for(int c = 0; c < M; ++c){
							bt[r][c] = 1000000000;
						}
					}
					memset(seen2,-1,sizeof(seen2));
					while(!QQ.empty()){
						int cr = QQ.top().second.first;
						int cc = QQ.top().second.second;
						int tt = -QQ.top().first;
						QQ.pop();
						if( seen2[cr][cc]>= 0 ) continue;
						seen2[cr][cc] = tt;
						if( cr == N-1 && cc == M-1){
							if( bestt > tt ){
								bestt = tt;
							}
							break;
						}
						for(int d = 0; d < 4; ++d){
							int cr1 = cr + vert[d], cc1 = cc + horz[d];
							if( t1[cr][cc][d] >= 0 && seen2[cr1][cc1] == -1){
								int tt1 = tt;
								if( C[cr1][cc1] - (H-tt) < 50 ){
									tt1 = tt + 50 - C[cr1][cc1] + (H-tt);
								}
								if( F[cr][cc]+20 > H - tt1 )
									tt1 += 100;
								else
									tt1 += 10;
								if( tt1 < bt[cr1][cc1] ){
									bt[cr1][cc1] = tt1;
									QQ.push(iii(-tt1,ii(cr1,cc1)));
								}
							}
						}
					}
				}
			}
		}

		printf( "Case #%d: ", j);
		printf("%f\n", bestt/10.);
		fflush(stdout);
	}
	return 0;
}
