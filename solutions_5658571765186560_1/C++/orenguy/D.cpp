#include <bits/stdc++.h>

using namespace std;

typedef long long     LL;
typedef pair<int,int> pii;

double PI  = acos(-1);
double EPS = 1e-7;
int INF    = 1000000000;
LL INFLL   = 1000000000000000000LL;

#define fi            first
#define se            second
#define mp            make_pair
#define pb            push_back

#define input(in)     freopen(in,"r",stdin)
#define output(out)   freopen(out,"w",stdout)

#define MIN(a, b)     (a) = min((a), (b))
#define MAX(a, b)     (a) = max((a), (b))

#define RESET(a, b)   memset(a,b,sizeof(a))
#define ALL(a)        (a).begin(), (a).end()
#define SIZE(a)       (int)a.size()
#define SORT(a)       sort(ALL(a))
#define UNIQUE(a)     (a).erase( unique( ALL(a) ), (a).end() )
#define FOR(a, b, c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a, b, c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a, b)   for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); a++)

int mx[8] = {-1,1,0,0,-1,-1,1,1};
int my[8] = {0,0,-1,1,-1,1,-1,1};

// ----- //

int isi[21][21];
int x,y;
int X,R,C;

bool can(int R,int C,int px,int py) {
	return (0 <= px && px < R && 0 <= py && py < C && !isi[px][py]);
}

void put(int px,int py) {
	isi[px][py] = !isi[px][py];
}

vector<pii> current;
set< vector<pii> > nmino[7];

int vs[21][21];

int dfs(int R,int C,int r,int c) {
	if (!isi[r][c]) return 0;
	if (vs[r][c]) return 0;
	vs[r][c] = 1;
	int res = 1;
	if (r < R-1) res += dfs(R,C,r+1,c);
	if (c < C-1) res += dfs(R,C,r,c+1);
	if (0 < r) res += dfs(R,C,r-1,c);
	if (0 < c) res += dfs(R,C,r,c-1);
	return res;
}

int dfs2(int R,int C,int r,int c) {
	if (isi[r][c]) return 0;
	if (vs[r][c]) return 0;
	//cout << "D " << r << " " << c << endl;
	vs[r][c] = 1;
	int res = 1;
	if (r < R-1) res += dfs2(R,C,r+1,c);
	if (c < C-1) res += dfs2(R,C,r,c+1);
	if (0 < r) res += dfs2(R,C,r-1,c);
	if (0 < c) res += dfs2(R,C,r,c-1);
	return res;
}

void go(int R,int lim,int px,int py) {
	//cout << R << " " << lim << " " << px << " " << py << endl;
	if (lim == 0) {
		RESET(vs,0);
		if (dfs(R,R,current[0].fi, current[0].se) != R) return;
		vector<pii> lol = current;
		FORD(a,SIZE(lol)-1,0) {
			lol[a].fi -= lol[0].fi;
			lol[a].se -= lol[0].se;
		}
		nmino[R].insert(lol);
		return;
	}
	if (py == R) {
		go(R, lim, px+1,0);
		return;
	}
	if (px == R) {
		return;
	}
	go(R,lim, px, py+1);
	isi[px][py] = 1;
	current.pb(mp(px,py));
	go(R,lim-1, px, py+1);
	current.pop_back();
	isi[px][py] = 0;
}



int main() {
	FOR(a,1,6) {
		go(a,a,0,0);
		//cout << a << " " << SIZE(nmino[a]) << endl;
		
	}
	int tc;
	scanf("%d",&tc);
	FOR(T,1,tc) {
		printf("Case #%d: ",T);
		
		scanf("%d%d%d",&X,&R,&C);
		
		if (X >= 7) {
			puts("RICHARD");
		}
		else {
			bool ans = 1;
			FORIT(it, nmino[X]) {
				//cout << "COBA LAGI " << endl;
				vector<pii> u = (*it);
				bool allcannot = 1;
				FOR(a,0,R-1) {
					FOR(b,0,C-1) {
						bool fail = 0;
						RESET(isi,0);
						FOR(c,0,X-1) {
							if (!can(R,C,a+u[c].fi, b+u[c].se)) {
								fail = 1;
								break;
							}
						}
						if (!fail) {
							RESET(isi,0);
							FOR(c,0,X-1) {
								put(a+u[c].fi, b+u[c].se);
							}
							RESET(vs,0);
							bool cannot = 0;
							/*
							FOR(c,0,R-1) {
								FOR(d,0,C-1) {
									cout << isi[c][d];
								}
								cout << endl;
							}
							cout << endl;
							*/
							FOR(c,0,R-1) {
								FOR(d,0,C-1) {
									if (isi[c][d] == 0 && vs[c][d] == 0) {
										int res = dfs2(R,C,c,d);
										//cout << "DFS " << c << " " << d << " " << res << endl;
										if (res%X) {
											cannot = 1;
										}
									}
								}
							}
							/*
							cout << cannot << endl;
							*/
							if (!cannot) {
								allcannot = 0;
								break;
							}
						}
					}
					if (!allcannot) break;
				}

				FOR(a,0,C-1) {
					FOR(b,0,R-1) {
						bool fail = 0;
						RESET(isi,0);
						FOR(c,0,X-1) {
							if (!can(C,R,a+u[c].fi, b+u[c].se)) {
								fail = 1;
								break;
							}
						}
						if (!fail) {
							RESET(isi,0);
							FOR(c,0,X-1) {
								put(a+u[c].fi, b+u[c].se);
							}
							RESET(vs,0);
							bool cannot = 0;
							
							
							FOR(c,0,C-1) {
								FOR(d,0,R-1) {
									if (isi[c][d] == 0 && vs[c][d] == 0) {
										int res = dfs2(C,R,c,d);
										//cout << "DFS " << c << " " << d << " " << res << endl;
										if (res%X) {
											cannot = 1;
										}
									}
								}
							}
							/*
							cout << cannot << endl;
							*/
							if (!cannot) {
								allcannot = 0;
								break;
							}
						}
					}
					if (!allcannot) break;
				}
				if (allcannot) {
					ans = 0;
					break;
				} 
			}
			
			puts(!ans?"RICHARD":"GABRIEL");
		}
	}
}
