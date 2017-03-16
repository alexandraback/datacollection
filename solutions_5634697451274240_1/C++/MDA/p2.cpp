#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <string>
#include <assert.h>
#include <set>

using namespace std;

char s[10000];

int solve() {
	int last = 0, cnt = 0;
	for (int i = 0; s[i]; ++i) {
		if (last != s[i])
			++cnt;
		last = s[i];
	}
	return last == '+' ? cnt - 1 : cnt;
}

int solve2() {
	set<string> front, newfront, seen;
	front.insert(s);
	string goal(strlen(s), '+');
	if (goal == s)
		return 0;
	for (int i = 0; ; ++i) {
		for (string t : front) {
			string a;
			for (int j = 0; j < goal.size(); ++j) {
				a = t;
				reverse(a.begin(), a.begin() + j + 1);
				for (int k = 0; k <= j; ++k)
					if (a[k] == '-')
						a[k] = '+';
					else
						a[k] = '-';
				if (a == goal)
					return i + 1;
				if (~seen.count(a))
					newfront.insert(a);
			}
		}
		front = std::move(newfront);
		newfront.clear();
	}
}

int main() {
	//freopen("input.txt", "rt", stdin);
	freopen("C:\\Users\\dmarin3\\Downloads\\B-large.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf("%s", s);
		//assert(solve() == solve2());
		printf("Case #%d: %d\n", i + 1, solve());
	}
}