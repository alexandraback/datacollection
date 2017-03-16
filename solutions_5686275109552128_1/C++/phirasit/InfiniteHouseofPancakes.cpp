#include <iostream>
#include <vector>

#define N 1010
#define INF (-1u/2)

using namespace std;

int arr[N];
int n;

int main() {
	
	freopen("Blarge.in", "r", stdin);
	freopen("Blarge.out", "w", stdout);
	
	int t;
	cin >> t;
	for(int C = 1;C <= t;C++) {
		cin >> n;
		int mx = 0;
		for(int i = 1;i <= n;i++) {
			cin >> arr[i];
			mx = max(mx, arr[i]);
		}
		int ans = INF;
		for(int i = 1;i <= mx;i++) {
			int cnt = i;
			for(int j = 1;j <= n;j++) {
				cnt += (arr[j] - 1) / i;
			}
			if(cnt < ans) {
				ans = cnt;
			}
		}
		cout << "Case #" << C << ": " << ans << endl;
	}
	return 0;
}
