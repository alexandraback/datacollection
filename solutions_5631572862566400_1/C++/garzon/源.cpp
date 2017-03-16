#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#define DIR "D:\\codejam\\"

#define REP(i, n) for(int i=0; i<(n); i++)

using namespace std;

map<int, int> mem;
map<int, int> visited;
map<int, int> pairs;
map<int, int> steps;
map<int, int> endWithPairSmallId;
map<int, int> depth;

int dfs(int st, int step, int &thisEndWithPairSmallId) {
	visited[st] = step;
	steps[st] = step;
	int next = mem[st];
	if (visited[next]) {
		if (steps[next]) {
			int loopLen = step - steps[next] + 1;
			if (loopLen == 2)
				thisEndWithPairSmallId = next;
			else
				thisEndWithPairSmallId = -1;
			depth[st] = 1;
			endWithPairSmallId[st] = thisEndWithPairSmallId;
			return loopLen;
		}
		else {
			thisEndWithPairSmallId = endWithPairSmallId[next];
			depth[st] = depth[next] + 1;
			if (mem[mem[next]] == next) {
				thisEndWithPairSmallId = next;
				depth[st] = 3;
			}
			endWithPairSmallId[st] = thisEndWithPairSmallId;
			return -1;
		}
	}
	else {
		int res = dfs(next, step + 1, thisEndWithPairSmallId);
		endWithPairSmallId[st] = thisEndWithPairSmallId;
		depth[st] = depth[next] + 1;
		return res;
	}
}

int main() {
	ifstream is(DIR"C-large (1).in");
	ofstream os(DIR"csmall_out3.txt");

	int t, n;
	is >> t;
	REP(i, t) {
		is >> n;
		mem.clear();
		visited.clear();
		endWithPairSmallId.clear();
		pairs.clear();
		depth.clear();
		REP(j, n) {
			int tmp;
			is >> tmp;
			mem[j] = tmp-1;
		}
		REP(j, n) {
			if (mem[mem[j]] == j) {
				pairs[mem[j]] = j;
				pairs[j] = mem[j];
			}
		}
		int res = 0;
		REP(j, n) {
			if (visited[j]) continue;
			steps.clear();
			int dummy;
			int tmp = dfs(j, 1, dummy);
			if (tmp > res) res = tmp;
		}

		map<int, int> pairloopsmaxlen;
		REP(j, n) {
			if (endWithPairSmallId[j] != -1) {
				pairloopsmaxlen[endWithPairSmallId[j]] = max(pairloopsmaxlen[endWithPairSmallId[j]], depth[j]);
			}
		}
		int tmp2 = 0;
		map<int, bool> calc;
		for (const auto &p : pairloopsmaxlen) {
			if (!calc[p.first] && !calc[mem[p.first]]) {
				tmp2 += p.second;
				calc[p.first] = true;
				calc[mem[p.first]] = true;
			}
			else {
				tmp2 += p.second - 2;
			}
		}
		res = max(res, tmp2);

		os << "Case #" << (i + 1) << ": ";
		os << res;
		os << endl;
	}

	return 0;
}