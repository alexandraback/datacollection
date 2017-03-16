/*{{{*/
/*includes e defines*/
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
#define sz(A) (int)(A).size()
#define FOR(A,B) for(int A=0; A < (int) (B);A++)
#define FOREACH(A,B) for((__typeof (B).begin) A = (B).begin(); A != (B).end(); A++)
#define pb push_back
#define all(x) x.begin() , x.end()
#define mp make_pair
/*}}}*/
/*{{{*/
/*main*/
void solveCase();
int main() {
	int TESTES; scanf("%d", &TESTES);
	for(int TESTE = 1; TESTE <= TESTES; TESTE++) {
		printf("Case #%d: ", TESTE);
		solveCase();
	}
    return 0;
}
/*}}}*/



void solveCase() {
	int k, n;
	cin >> k >> n;
	vector<double> p(k);
	FOR(i, k) cin >> p[i];

	double ans = n + 2;

//	cerr << "Comeca com " << ans << endl;

	FOR( back, k + 1 ) {
		double prob = 1;
		FOR(i, k - back) prob *= p[i];
		int totalBom = 2*back + (n-k) + 1;
		int totalRuim = 2*back + (n-k) + 1 + n + 1;
		double val = (prob * totalBom) + (1 - prob) * (totalRuim);
//		cerr << "Com " << back << " backs tenho " << totalBom << " * " << prob << " + " << totalRuim << endl;
		ans = min(ans, val);
	}

	printf("%.10f\n", ans);
}

