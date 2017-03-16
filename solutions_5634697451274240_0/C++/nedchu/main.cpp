#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
// head
char s[105];
vector<char> v;
int main() {
	int t, cas = 1;
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		int n = strlen(s);
		for (int i = 0; i < n; i++) {
			if (v.empty() || v.back() != s[i]) v.push_back(s[i]);
		}
		if (v.back() == '+') v.pop_back();
		printf("Case #%d: %d\n", cas++, v.size());
		v.clear();
	}
	return 0;
}
