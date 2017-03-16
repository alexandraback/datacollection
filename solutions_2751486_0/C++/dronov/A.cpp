#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

#define MAXN 1000
#define INF 1000000000

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int TEST;
	scanf("%d", &TEST);
	map < int, int > mp;
	mp['a'] = 0;
	mp['e'] = 0;
	mp['i'] = 0;
	mp['o'] = 0;
	mp['u'] = 0;
	for (int test = 0; test < TEST; test++) {
		string s;
		int n;
		cin >> s >> n;
		int cnt = 0;
		for (int i = 0; i < s.length(); i++)
			for (int j = 0; j < s.length(); j++) {
				bool ok = true;
				int p = 0;
				int cur = 0;
				for (int k = i; k <= j; k++) {
					if (mp.find(s[k]) == mp.end())
						p++;
					else {
						cur = max(cur, p);
						p = 0;
					}
				}
				cur = max(cur, p);
				if (cur >= n)
					cnt++;
			}

		printf("Case #%d: %d\n", test + 1, cnt);
	}

	return 0;
}