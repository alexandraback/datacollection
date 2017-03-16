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
typedef pair<int,int> pii;
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
	vector< pii > p(n);
	FOR(i, n) {
		cin >> p[i].first >> p[i].second;
	}

	int ans = 0;
	int tenho = 0;

	int inf = (1<<30);

	while( sz(p) ) {
		ans++;
		int pos = -1;
		FOR(i, sz(p)) {
			if( p[i].second <= tenho ) {
				pos = i;
				break;
			}
		}
		if(pos != -1) {
			if(p[pos].first == inf) tenho++;
			else tenho += 2;
			p.erase(p.begin() + pos);
		} else {
			
			FOR(i, sz(p)) {
				if(p[i].first <= tenho) {
					if(pos == -1 || p[i].second > p[pos].second) {
						pos = i;
					}
				}
			}

			if(pos == -1) break;

			p[pos].first = inf;
			tenho++;

		}
	}


	if(sz(p)) cout << "Too Bad" << endl;
	else cout << ans << endl;

}

