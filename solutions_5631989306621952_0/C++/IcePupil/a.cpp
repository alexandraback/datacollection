#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
char s[1000];

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int test, nCase = 0;
	scanf("%d", &test);
	while (test --) {
		scanf("%s", s);
		string ans = "";
		for (int i = 0; s[i]; i ++) {
			if (ans + s[i] > s[i] + ans) {
				ans = ans + s[i];
			} else {
				ans = s[i] + ans;
			}
		}
		nCase ++;
		printf("Case #%d: ", nCase);
		cout << ans << endl;
	}
	return 0;
}
