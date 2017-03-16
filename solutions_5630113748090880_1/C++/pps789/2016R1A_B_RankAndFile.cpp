#include<iostream>
#include<algorithm>
using namespace std;

const int HMAX = 2555;
int cnt[HMAX];

int main(){
	freopen("large.in", "r", stdin);
	freopen("large.out", "w", stdout);

	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++){
		cout << "Case #" << tc << ": ";
		int n; cin >> n;
		for (int i = 0; i < HMAX; i++) cnt[i] = 0;
		for (int i = 0; i < 2 * n - 1; i++){
			for (int j = 0; j < n; j++){
				int t; cin >> t;
				cnt[t]++;
			}
		}
		for (int i = 1; i < HMAX; i++){
			if (cnt[i] % 2) cout << i << ' ';
		}
		cout << endl;
	}
}