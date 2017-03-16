/** Google Codejam 2015
  * Qualification Round
  * Problem A: Standing Ovation
  * Author: spyder21er
  */

#include <bits/stdc++.h>
using namespace std;

#define fileName "A-small-attempt0"
int caseNum = 0;

void solve() {
    printf("Case #%d: ", ++caseNum);
	int smax;
	string slvl;
	scanf("%d", &smax);
	cin >> slvl;
	int total = 0;
	int res = 0;
	for(int i = 0; i < smax + 1; i++) {
		if(total < i) {
			int addis;
			addis = i - total;
			res += addis;
			total += addis;
		}
		total += (int) (slvl[i] - '0');
	}
	printf("%d\n", res);
}

int main() {
    freopen(fileName ".in", "r", stdin);
    freopen(fileName ".txt", "w", stdout);
    
    int T;
    scanf("%d", &T);
	while(T--) {
        solve();
    }
    return 0;
}