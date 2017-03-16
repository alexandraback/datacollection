#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int b[100][100];
int n;
int a[200][200];
map<int, int> m;
vector<int> ans;

void
solve()
{
	scanf("%d", &n);
	m.clear();
	ans.clear();
	for (int i = 0; i < 2 * n - 1; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
			m[a[i][j]] += 1;
		}
	}
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
		if (it->second % 2 == 1) {
			ans.push_back(it->first);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < n; ++i) {
		printf("%d%c", ans[i], " \n"[i == n - 1]);
	}
}

int
main()
{
    int t;
    scanf("%d\n", &t);
    for (int i = 0; i < t; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
        if (ans.size() != n) {
			fprintf(stderr, "Fail %d\n", i + 1);
		}
    }
}
