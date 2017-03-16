// Problem C. Technobabble
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++) {
		static char s1[1024], s2[1024];
		int n, ans = 0;
		scanf("%d", &n);
		map<string, int> m1, m2;
		map<string, vector<string> > m;
		for (int i = 0; i < n; i++) {
			scanf("%s %s", s1, s2);
			m1[s1]++;
			m2[s2]++;
			m[s1].push_back(s2);
		}

		/*
		for (map<string, int>::iterator it = m1.begin(); it != m1.end(); it++) {
			if (it->second == 1) continue;
			vector<string> &v = m[it->first];
			for (int i = 0; i < v.size(); i++)
				printf("%s %s (%d)\n", it->first.c_str(), v[i].c_str(), m2[v[i]]);
		}
		*/

		for (map<string, int>::iterator it = m1.begin(); it != m1.end(); it++) {
			if (it->second <= 1) continue;
			vector<string> &v = m[it->first];
			int c = 0;
			for (int i = 0; i < v.size(); i++)
				if (m2[v[i]] > 1) {
					c++;
					m2[v[i]]--;
				}
			ans += min(c, (int) v.size() - 1);
		}
		printf("Case #%d: %d\n", ti, ans);
	}

	return 0;
}
