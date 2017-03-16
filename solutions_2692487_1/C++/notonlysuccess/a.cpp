#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[111];
int main() {
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T , cas = 1;
	cin >> T;
	while (T --) {
		int a , n;
		cin >> a >> n;
		for (int i = 0 ; i < n ; i ++) {
			cin >> arr[i];
		}
		sort(arr,arr+n);
		int ans = n;
		int add = 0;
		for (int i = 0 ; i < n ; i ++) {
			if (a == 1) break;
			while (a <= arr[i]) {
				a += a - 1;
				add ++;
			}
			a += arr[i];
			ans = min(ans , add + n - i - 1);
		}
		cout << "Case #" << cas ++ << ": " << ans << endl;
	}
	return 0;
}
