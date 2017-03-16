#include <iostream>
using namespace std;

const int N = 100 + 10;

int n;
char s[N];

void solve()
{
	scanf("%s", s);
	n = strlen(s);
	int cur = 1;
	for(int i = 1; i < n; ++ i) {
		if (s[i] != s[i - 1]) ++ cur;
	}
	if (s[n - 1] == '+') -- cur;
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
