#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <cctype>
#include <vector>
#include <queue>
#include <tr1/unordered_map>
#include <cmath>
#include <map>
#include <bitset>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define IN0(x, n) ((x) > -1 && (x) < n)
#define IN(x, a, b) ((x) >= a && (x) <= b)
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
#define REPDP(i,a,n) for(int i = n-1; i>=a; i--)
#define pb push_back
#define pf push_front
#define sz size()
#define mp make_pair
/////////////////////////////NUMERICAL//////////////////////////////
#define INCMOD(a,b,c) (((a)+b)%c)
#define DECMOD(a,b,c) (((a)+c-b)%c)
#define ROUNDINT(a) (int)((double)(a) + 0.5)
#define INF 0x3f3f3f3f
#define EPS 1e-9
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S))  //PRECISA DE UMA TABELA PARA TRANSFORMAR EM INDICE
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  //J PRIMEIROS
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL  //J PRIMEIROS
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//__builtin_popcount(m)
//scanf(" %d ", &t);

char grid[360][360];
bool vis[360][360];
int t, M, R, C, tVis;

bool nMines(int r, int c){
	int ans = 0;
	for(int ar = -1; ar<2; ar++)
	for(int ac = -1; ac<2; ac++)
	if(ac || ar){
		int nr = r+ar, nc = c+ac;
		if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
		ans += (grid[nr][nc] == '*');
	}
	return ans;
}

void checkfill(int r, int c){
	//cout << " CHECKFILL " << r << " " << c << endl;
	if(r < 0 || r >= R || c < 0 || c >= C || vis[r][c] || grid[r][c] == '*') return;
	//cout << " CHECKFILL PASSOU " << r << " " << c << endl;
	vis[r][c] = true;
	tVis++;
	int mines = nMines(r,c);
	//cout << " MINAS " << mines << endl;
	if(mines > 0) return;
	 
	for(int ar = -1; ar<2; ar++)
	for(int ac = -1; ac<2; ac++)
	if(ac || ar ) checkfill(r+ar, c+ac);
}

bool check(int r, int c){
	CLEAR0(vis);
	tVis = 0;
	checkfill(r,c);
	//cout << " TOTAL " << r << " " << c << " EH " << tVis << endl;
	return (tVis == ((R*C)-M));
}

bool cmp(pair< double, ii > const &a, pair< double, ii > const &b){
	return (fabs(a.first - b.first) > EPS && a.first < b.first);
}

int main(){
	cin >> t;
	REP(ca, t){
		cin >> R >> C >> M;
		
		bool pos = false;
		
		int tot = R*C;
		REP(msk, (1 << tot)){
			if(__builtin_popcount(msk) == M){
				REP(i, R) REP(j, C) grid[i][j] = CHECK(msk, i*C+j) ? '*' : '.';
				
				REP(i, R){
					if(pos) break;
					REP(j, C){
						if(check(i, j)){
							pos = true;
							grid[i][j] = 'c';
							break;
						}
					}
				}
				if(pos) break;
			}
		}
		
		printf("Case #%d: \n", ca+1);
		if(pos){
			REP(i, R){
				REP(j, C) printf("%c", grid[i][j]);
				printf("\n");
			}
		}
		else printf("Impossible\n");
	}
}
