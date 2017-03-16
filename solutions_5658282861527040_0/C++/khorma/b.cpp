//In the name of God
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int test; cin >> test;
	for (int i = 1; i <= test; i++) {
		cout << "Case #" << i << ": ";
		int a, b, k;
		cin >> a >> b >> k;
		int ans = 0;
		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				if ((i & j) < k)
					ans++;
		cout << ans << '\n';
	}
	return 0;
}
