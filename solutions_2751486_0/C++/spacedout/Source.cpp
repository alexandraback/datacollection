#include <iostream>
#include <cstdio>
using namespace std;

	char s[1<<20];

void solve () {

	int k;

	getchar();
	scanf ("%s %d", s, &k);

	//printf("%s %d\n", s, k);

	string out = "aeiou";

	int n = (int)strlen(s);

	int cnt = 0;
	int pos = 0, i = 0;
	int flag = 0;
	int last = 0;

	long long ans = 0;

	char *p = s;
	for (; i < n; ++p) {
	
		//printf ("at char %c with cnt %d\n", *p, cnt);
		//cout << out.find (*p) << "\n";

		if (out.find(*p) == std::string::npos) {
			cnt++;
			if (cnt >= k) {flag = 1; pos = i - k + 1;}
		}
		else {
			cnt = 0;
		}

		if (flag) ans += pos + 1;
		++i;
	}

	static int testN = 1;
	cout << "Case #" << testN << ": " << ans <<"\n";
	testN++;
}

int main () {

	int t;
	scanf ("%d", &t);
	
	for (; t; t--)
		solve();

	return 0;
}
