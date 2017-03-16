#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int main (void) {
	int t, c;
	scanf ("%d", &t);
	for (c = 1; c <= t; c++) {
		char s[1001];
		scanf ("%s", s);
		int len = strlen(s);
		char beg = s[0];
		int b = -1, e = 1;
		vector<pair<int, char> > ans;
		ans.push_back(make_pair(0, s[0]));
		for (int i = 1; i < len; i++) {
			if (s[i] >= beg) {
				ans.push_back(make_pair(b--, s[i]));
				beg = s[i];
			} else {
				ans.push_back(make_pair(e++, s[i]));
			}
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)	s[i] = ans[i].second;
		printf ("Case #%d: %s\n", c, s);
	}
}