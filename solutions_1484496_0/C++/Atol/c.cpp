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
typedef vector<int> vi;
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
	int n;
	cin >> n;
	vi v(n);
	FOR(i, n) cin >> v[i];

	map<int, vi> ja;
	FOR(i, (1<<n)) {
		if(!i) continue;
		vi at;
		int sum = 0;
		FOR(j, n) {
			if(i & (1<<j)) {
				sum += v[j];
				at.pb( v[j] );
			}
		}
		if(!ja.count(sum)) {
			ja[sum] = at;
		} else {
			cout << endl;
			FOR(i, sz(at)) {
				if(i) cout << " ";
				cout << at[i];
			}
			cout << endl;
			at = ja[sum];
			FOR(i, sz(at)) {
				if(i) cout << " ";
				cout << at[i];
			}
			cout << endl;
			return;
		}
	}

	cout << "Impossible" << endl;
}

