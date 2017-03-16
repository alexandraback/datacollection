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
using namespace std;

int n;
int pairs, mcirc;

int work(int x, unordered_set<int> &bad, vector<int> &nums) {
	int max = 0, aaa = -1;
	vector<int> t(n, -1);
	t[x] = 0;
	bool done = false;
	while (!done) {
		done = true;
		for (int i = 0; i < n; ++i) {
			if (bad.find(i) != bad.end()) continue;
			if (t[i] >= 0) continue;
			if (t[nums[i]] >= 0) {
				t[i] = t[nums[i]] + 1;
				if (t[i] > max) {
					max = t[i];
					aaa = i;
				}
				done = false;
			}
		}
	}
	return max;
}

int main() {
	FILE *fp = fopen("C-large.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int T;
	fscanf(fp, "%d", &T);
	for (int iii = 0; iii < T; ++iii) {
		fscanf(fp, "%d", &n);
		vector<int> buf;
		for (int i = 0; i < n; ++i) {
			int tmp;
			fscanf(fp, "%d", &tmp);
			buf.push_back(tmp - 1);
		}
		vector<int> backup = buf;
		pairs = 0;
		mcirc = 0;
		unordered_set<int> pairsins;
		unordered_set<int> pairends;
		for (int i = 0; i < n; ++i) {
			if (buf[i] >= 0 && buf[buf[i]] == i) {
				pairsins.insert(i);
				pairsins.insert(buf[i]);
				pairends.insert(i);
				pairends.insert(buf[i]);
				buf[buf[i]] = -1;
				buf[i] = -1;
				pairs += 2;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (buf[i] < 0) continue;
			int k = buf[i];
			vector<int> tmp;
			unordered_map<int, int> asdf;
			tmp.push_back(i);
			asdf[i] = 0;
			buf[i] = -1;
			while (asdf.find(k) == asdf.end() && k >= 0) {
				tmp.push_back(k);
				asdf[k] = tmp.size() - 1;
				int t = buf[k];
				buf[k] = -1;
				k = t;
			}
			if (asdf.find(k) != asdf.end()) {
				int a = tmp.size() - asdf[k];
				if (a > mcirc) mcirc = a;
			}
		}
		for (auto &x : pairends) pairs += work(x, pairsins, backup);
		int ans = max(pairs, mcirc);
		fprintf(fout, "Case #%d: %d\n", iii + 1, ans);
	}
	fclose(fp);
	fclose(fout);
	return 0;
}