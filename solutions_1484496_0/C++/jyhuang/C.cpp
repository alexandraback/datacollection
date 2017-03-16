#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <numeric>
#include <utility>
#include <functional>
#include <algorithm>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
	int nc;
	scanf("%d", &nc);
	static long long a[1024];
	for (int ci = 1; ci <= nc; ci++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
		sort(a, a + n);
		
		map<long long, vector<int> > m;
		map<long long, vector<int> >::iterator it;
		bool found = false;
		vector<int> s1, s2;
		for (int i = 0; i < n; i++) {
			vector<pair<long long, vector<int> > > add;
			if (m.count(a[i]) > 0) {
				found = true;
				s1 = m[a[i]];
				s2.clear();
				s2.push_back(i);
				break;
			} else {
				vector<int> v;
				v.push_back(i);
				add.push_back(make_pair(a[i], v));
			}
			
			for (it = m.begin(); it != m.end(); ++it) {
				long long x = it->first + a[i];
				if (m.count(x) > 0) {	// found
					found = true;
					s1 = it->second;
					s1.push_back(i);
					s2 = m[x];
					break;
				} else {
					vector<int> v = it->second;
					v.push_back(i);
					add.push_back(make_pair(x, v));
				}
			}
			for (int i = 0; i < add.size(); i++)
				m[add[i].first] = add[i].second;

			if (found) break;
		}
		
		if (found) {
			printf("Case #%d:\n", ci);
			for (int i = 0; i < s1.size(); i++)
				printf("%s%lld", i ? " " : "", a[s1[i]]);
			printf("\n");
			for (int i = 0; i < s2.size(); i++)
				printf("%s%lld", i ? " " : "", a[s2[i]]);
			printf("\n");
		} else {
			printf("Case #%d: Impossible\n", ci);
		}		
		
	}

	return 0;
}
