#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include "BiGraph.h"
using namespace std;

int main() {
	FILE *fp = fopen("C-small-attempt0.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int T;
	fscanf(fp, "%d", &T);
	for (int iii = 0; iii < T; ++iii) {
		int n, kl = 0, kr = 0;
		fscanf(fp, "%d", &n);
		unordered_map<string, int> s2ileft, s2iright;
		vector<pair<int, int>> edges;
		for (int i = 0; i < n; ++i) {
			char tmp1[32], tmp2[32];
			fscanf(fp, "%s %s", tmp1, tmp2);
			string t1(tmp1), t2(tmp2);
			if (s2ileft.find(t1) == s2ileft.end()) s2ileft[t1] = kl++;
			if (s2iright.find(t2) == s2iright.end()) s2iright[t2] = kr++;
			edges.push_back({ s2ileft[t1], s2iright[t2] });
		}
		init(kl, kr);
		for (auto p : edges) addEdge(p.first, p.second);
		int x = maxMatching();
		fprintf(fout, "Case #%d: %d\n", iii + 1, n - kl - kr + x);
	}
	fclose(fp);
	fclose(fout);
	return 0;
}