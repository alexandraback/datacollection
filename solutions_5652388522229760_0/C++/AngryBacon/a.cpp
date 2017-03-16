#include <iostream>
#include <vector>
using namespace std;

void solve()
{
	long long n;
	cin >> n;
	if (n == 0) {
		puts("INSOMNIA");
		return;
	}
	vector<int> vis(10, 0);
	long long cur = n;
	for( ; ; ) {
		for(long long tmp = cur; tmp; tmp /= 10) vis[tmp % 10] = true;
		int flag = true;
		for(int i = 0; i < 10; ++ i) {
			if (! vis[i]) {
				flag = false;
			}
		}
		if (flag) break;
		cur += n;
	}
	cout << cur << endl;
}

int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++ i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
