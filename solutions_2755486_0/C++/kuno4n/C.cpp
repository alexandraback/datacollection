#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>
#include <fstream>
//#include "cout.h"

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset(x, a, (int)sizeof(x))
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())

int case_number;
#define printg case_number++, printf("Case #%d: ",case_number), printf
#define gout case_number++, printf("Case #%d: ",case_number), cout

int N, d[10], n[10], w[10], e[10], s[10], dd[10], dp[10], ds[10];
int res;
VI h, D;
int ad[10][10], aw[10][10], ae[10][10], as[10][10];

void init() {
}

void input() {
	D.clear(); h.clear();
	
	cin >> N;
	REP(i, N){
		cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> dd[i] >> dp[i] >> ds[i];
		w[i] += 1000;
		e[i] += 1000;
	}
	REP(i, N){
		ad[i][0] = d[i];
		aw[i][0] = w[i];
		ae[i][0] = e[i];
		as[i][0] = s[i];
		D.PB(d[i]);
		for(int j = 1; j < n[i]; j++){
			ad[i][j] = ad[i][j-1] + dd[i];
			aw[i][j] = aw[i][j-1] + dp[i];
			ae[i][j] = ae[i][j-1] + dp[i];
			as[i][j] = as[i][j-1] + ds[i];
			D.PB(ad[i][j]);
		}
	}
	sort(ALL(D));
	D.erase(unique(ALL(D)), D.end());
//	REP(i, SZ(D)) OUT(D[i]);
	REP(i, 10000) h.PB(0);
	res = 0;
}

void solve() {
	REP(DD, SZ(D)){
		int day = D[DD];
		VI nxh = h;
		REP(i, N){
			REP(j, n[i]){
				if(ad[i][j] == day){
//					OUT(day); OUT(i);OUT(j);OUT(aw[i][j]);OUT(ae[i][j]);OUT(as[i][j]);
					bool can = false;
					for(int p = aw[i][j]; p < ae[i][j]; p++){
						if(h[p] < as[i][j]){
							can = true;
							nxh[p] = max(nxh[p], as[i][j]);
						}
					}
//					OUT(can); cout << endl;
					if(can) res++;
					break;
				}
			}
		}
		h = nxh;
	}
	gout << res << endl;
}

int main() {
	init();
	int number_of_test_cases;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases){
		input();
		solve();
	}
	return 0;
}
