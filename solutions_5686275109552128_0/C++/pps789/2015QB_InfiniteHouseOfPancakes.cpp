#include<iostream>
#include<algorithm>
using namespace std;

int pan[1111];

int main(){
	freopen("small.in", "r", stdin);
	freopen("small.txt", "w", stdout);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> pan[i];

		int ans = 1000;
		for (int i = 1; i <= 1000; i++){
			int here = i;
			for (int j = 0; j < n; j++)
				here += (pan[j] - 1) / i;
			ans = min(ans, here);
		}
		cout << "Case #" << tc << ": " << ans << endl;
	}
}