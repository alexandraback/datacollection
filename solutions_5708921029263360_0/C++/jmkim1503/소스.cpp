#include <stdio.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct state {
	int v1, v2, v3;
};

int main() {

	int T;
	scanf("%d", &T);

	for (int tt = 1; tt <= T; tt++) {

		int a, b, c, K;

		scanf("%d %d %d %d", &a, &b, &c, &K);

		map<pair<int, int>, int> L_ab, L_ac, L_bc;
		vector<state> ans;

		for (int C = 1; C <= c; C++) {
			for (int B = 1; B <= b; B++) {
				for (int A = 1; A <= a; A++) {

					map<pair<int, int>, int>::iterator FindIter;

					bool chk = true;

					//a,b
					FindIter = L_ab.find(make_pair(A, B));
					if (FindIter != L_ab.end()) {
						int val = FindIter->second;
						if (val >= K) chk = false;
					}
					if (chk == false) continue;

					//a,c
					FindIter = L_ac.find(make_pair(A, C));
					if (FindIter != L_ac.end()) {
						int val = FindIter->second;
						if (val >= K) chk = false;
					}

					if (chk == false) continue;

					//b,d
					FindIter = L_bc.find(make_pair(B, C));
					if (FindIter != L_bc.end()) {
						int val = FindIter->second;
						if (val >= K) chk = false;
					}


					if (chk == false) continue;


					//insert start
					state temp;
					temp.v1 = A; temp.v2 = B; temp.v3 = C;
					ans.push_back(temp);

					FindIter = L_ab.find(make_pair(A, B));
					if (FindIter != L_ab.end()) {
						FindIter->second++;
					}
					else L_ab.insert(make_pair(make_pair(A, B), 1));

					FindIter = L_ac.find(make_pair(A, C));
					if (FindIter != L_ac.end()) {
						FindIter->second++;
					}
					else L_ac.insert(make_pair(make_pair(A, C), 1));

					FindIter = L_bc.find(make_pair(B, C));
					if (FindIter != L_bc.end()) {
						FindIter->second++;
					}
					else L_bc.insert(make_pair(make_pair(B, C), 1));
				}
			}
		}
		printf("Case #%d: %d\n", tt, ans.size());
		for (int i = 0; i < ans.size(); i++) {
			printf("%d %d %d\n", ans[i].v1, ans[i].v2, ans[i].v3);
		}
	}
}