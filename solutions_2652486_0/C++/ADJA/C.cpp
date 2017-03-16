#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <utility>
#include <iomanip>

using namespace std;

int tn, best;
int r, n, m, k;
int p[1000];
map < vector <int>, int> ans; 
vector <int> cur;
vector <int> out;

void rec(int len) {
	if (len == n) {
		set<int> s;
		for (int i = 0; i < (1 << n); i++) {
			int pr = 1;
			for (int j = 0; j < n; j++) 
				if (i & (1 << j))
					pr *= cur[j];
			s.insert(pr);
		}
		for (int i = 1; i <= k; i++) 
			if (s.count(p[i]) == 0)
				return;
		ans[cur]++;
	}
	else {
		for (int i = 2; i <= m; i++) {
			cur.push_back(i);
			rec(len + 1);
			cur.pop_back();
		}
	}
}

int main() {
	freopen("C-small-1-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d", &tn);

	scanf("%d %d %d %d", &r, &n, &m, &k);

	printf("Case #1:\n");
	
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= k; j++) {
			scanf("%d", &p[j]);
		}
		
		cur.clear();
		ans.clear();
		rec(0);

		best = 0;

		for (map< vector<int>, int >::iterator it = ans.begin(); it != ans.end(); it++) {
			if (it->second > best) {
				best = it->second;
				out = it->first;
			}
		}

		for (int j = 0; j < n; j++) 
			printf("%d", out[j]);

		printf("\n");
	}

	return 0;
}