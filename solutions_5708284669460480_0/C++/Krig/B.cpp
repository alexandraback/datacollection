#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <algorithm>
//#include <iostream>
#include <numeric>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
//#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b);i>=(e);--i)

#define PB push_back
#define ALL(V) (V).begin(),(V).end()
#define SIZE(V) ((int)(V).size())

#define MP make_pair
#define ST first
#define ND second

#define DBG

#ifdef DBG
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
	#define debug(...)
#endif

int __stmp;
#define scanf __stmp=scanf


const int INF = 1000000001;
const int MAX = 100000;

#define PARALLEL 0

/* UWAGA NA PAMIEC!
   Moze byc potrzebne nawet Z razy wiecej pamieci w trakcie dzialania,
   chyba ze bedzie sie ja alokowac i zwalniac w solve() wtedy moze byc
   potrzebne do <liczba rdzeni> razy wiecej.
   Kompilowac z --openmp
 */

class solver {
	public:
		// wczytujemy caly input dla jednego zestawu danych
		void input() {
			int k, l;
			scanf("%d %d %d", &k, &l, &s);
			REP(i,26) PK[i] = 0.;
			REP(i,k)
			{
				char c;
				scanf(" %c", &c);
				PK[c-'A'] += 1./k;
			}
			char t[111];
			scanf("%s", t);
			T = string(t);
			assert(SIZE(T) == l);
		}
		
		// skminiamy rozwiazanie
		void solve() {
			int n = T.size();
			int ps = 0;
			FORD(i,n-1,1)
				if(T.substr(0, i) == T.substr(n-i, i)) {
					ps = i;
					break;
				}
			
			double dp[s+1][s+1][n];
			memset(dp, 0, sizeof dp);
			memset(mem, -1, sizeof mem);
			dp[0][0][0] = 1.0;
			REP(i,s)
			{
				REP(j,i+1)
				{
					REP(k,n)
					{
						if(dp[i][j][k] == 0.0) continue;
						REP(c,26)
						{
							if(PK[c] == 0.0) continue;
							int nextk = f(k, c);
							if(nextk == n) {
								dp[i+1][j+1][ps] += dp[i][j][k] * PK[c];
							} else {
								dp[i+1][j][nextk] += dp[i][j][k] * PK[c];
							}
						}
					}
				}
			}
			int m = 0;
			REP(j,s+1)
				REP(k,n)
					if(dp[s][j][k] > 0.0)
						m = max(m, j);
			
			res = m;
			REP(j,s+1)
				REP(k,n)
					res -= dp[s][j][k] * j;
		}
		
		// wypisujemy output
		void output() {
			printf("%.9lf\n", res);
		}
	private:
		int s;
		string T;
		double PK[26];
		double res;
		int mem[111][26];
		
		int f(int pref, int c) {
			if(mem[pref][c] != -1) return mem[pref][c];
			string p = T.substr(0, pref) + char(c+'A');
			while(T.substr(0, p.size()) != p)
			{
				p = p.substr(1, SIZE(p)-1);
			}
			mem[pref][c] = SIZE(p);
			return SIZE(p);
		}
};

int main(int argc, char *argv[]) {
	int case_id = argc == 2 ? atoi(argv[1])-1 : -1;
	int Z;
	scanf("%d", &Z);
	vector<solver> S(Z);
	REP(z,Z) S[z].input();
	if(case_id == -1) {
		#if PARALLEL == 1
			#pragma omp parallel for schedule(dynamic)
		#endif
		REP(z,Z) S[z].solve();
	} else {
		S[case_id].solve();
	}
	REP(z,Z)
	{
		if(case_id == -1 || z == case_id) {
			printf("Case #%d: ", z+1);
			S[z].output();
		}
	}
	return 0;
}
