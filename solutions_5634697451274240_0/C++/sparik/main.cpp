#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker,"/STACK:256000000")
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <cassert>
#include <string>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <iomanip>
using namespace std;

#define INF 1000000000
#define lint long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define eps 0.0000001

int main() {
	
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tc;
	scanf("%d", &tc);

	int T = 1;

	while (tc--) {
		printf("Case #%d: ", T++);

		string s;
		cin >> s;

		int ans = 0;
		int st = 0;
		for (int i = s.size() - 1; i >= 0; --i) {
			if (s[i] == '-') {
				st = 1;
				++ans;
				while (i >= 0 && s[i] == '-') {
					--i;
				}

				++i;
				continue;
			}
			else {
				if (!st) continue;
				++ans;
				while (i >= 0 && s[i] == '+') {
					--i;
				}

				++i;
				continue;
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}