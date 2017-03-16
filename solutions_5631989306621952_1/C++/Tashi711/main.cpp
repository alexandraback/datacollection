#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

void work()
{
	string s;
	cin >> s;
	string ans;
	ans += s[0];
	for(int i = 1; i < (int)s.size(); ++i) {
		if(s[i] >= ans[0]) {
			ans = s[i] + ans;
		}
		else {
			ans = ans + s[i];
		}
	}
	cout << ans << endl;

}

int main()
{
	#define LOCAL_
	#ifdef LOCAL
	freopen("0.in", "r", stdin);
	freopen("0.out", "w", stdout);
	#endif

	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cout << "Case #" << i << ": ";
		work();
	}
	return 0;
}
