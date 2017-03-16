#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

int table[10000000];
int stable[10000000];
vector<pair<int, int> > vp;

int main() {
	char tmp[10];
	for (int i = 1; i <= 2000000; ++i) {
		sprintf(tmp, "%d", i);
		string S = tmp;
		vector<string> vs;
		for (int j = 0; j < S.size(); ++j) {
			if (S[0] != '0') vs.push_back(S);
			S = S.substr(1) + S[0];
		}
		sort(vs.begin(), vs.end());
		vs.erase(unique(vs.begin(), vs.end()), vs.end());
		for (int j = 0; j < vs.size(); ++j) {
			if (vs[j] == S) {
				table[i] = j;
				break;
			}
			int num;
			sscanf(vs[j].c_str(), "%d", &num);
			vp.push_back(make_pair(num, i));
		}
		stable[i] = stable[i - 1] + table[i];
	}
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		int A, B;
		scanf("%d%d", &A, &B);
		int ret = 0;
		for (int i = 0; i < vp.size(); ++i) {
			if (A <= vp[i].first && vp[i].first <= B &&
				A <= vp[i].second && vp[i].second <= B) {
				ret++;
			}
		}
		printf("Case #%d: %d\n", cn, ret);
	}
}
