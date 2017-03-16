#include <bits/stdtr1c++.h>

using namespace std;

typedef long long ll;

int ans[55][55];
int main() {
	#define int ll
    ios::sync_with_stdio(0);
    int t; cin >> t;
    for (int ca = 1; ca <= t; ca++) {
        cout << "Case #" << ca << ": ";
		
		memset(ans, 0, sizeof ans);
		
		//if B > 10 i can do w/e i want
		ll B, M; cin >> B >> M;
		for (int i = 1; i < B; i++) {
			for (int j = i+1; j < B-1; j++) {
				ans[i][j] = 1;
			}
			ans[0][i] = 1;
		}
		
		if (M > (1LL<<(B-2))) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			M--;
			ll m = 0;
			for (int i = 1; i < B-1; i++) {
				if ((1LL << (i-1)) & M) {
					ans[i][B-1] = 1;
					m += (1LL << (i-1));
				}
			}
			//cerr << M << " " << m << endl;
			
			cout << "POSSIBLE" << endl;
			for (int i = 0; i < B; i++) {
				for (int j = 0; j < B; j++) {
					cout << ans[i][j];
				}
				cout << endl;
			}
		}
    }
	return 0;
}