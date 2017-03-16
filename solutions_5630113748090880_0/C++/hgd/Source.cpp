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

void work(list<vector<int>> &nums, int l, int r, vector<vector<int>> &board) {
	if (l == r) {
		board.push_back(nums.front());
		return;
	}
	int min = INT_MAX, mincnt = 0, max = INT_MIN, maxcnt = 0;
	for (auto &x : nums) {
		if (x[l] < min) {
			min = x[l];
			mincnt = 1;
		}
		else if (x[l] == min) ++mincnt;
		if (x[r] > max) {
			max = x[r];
			maxcnt = 1;
		}
		else if (x[r] == max) ++maxcnt;
	}
	if (mincnt == 2) {
		vector<int> a, b;
		for (auto x = nums.begin(); x != nums.end(); ) {
			if ((*x)[l] == min) {
				if (a.empty()) a = *x;
				else b = *x;
				x = nums.erase(x);
			}
			else ++x;
		}
		vector<vector<int>> tboard;
		work(nums, l + 1, r, tboard);
		int i = 0, j = l + 1;
		for (; i < tboard.size(); ++i, ++j) {
			if (tboard[i][l] != a[j]) break;
		}
		if (i == tboard.size()) board.push_back(b);
		else board.push_back(a);
		for (auto &x : tboard) board.push_back(x);
	}
	else {
		vector<int> a, b;
		for (auto x = nums.begin(); x != nums.end(); ) {
			if ((*x)[r] == max) {
				if (a.empty()) a = *x;
				else b = *x;
				x = nums.erase(x);
			}
			else ++x;
		}
		vector<vector<int>> tboard;
		work(nums, l, r - 1, tboard);
		int i = 0, j = l;
		for (; i < tboard.size(); ++i, ++j) {
			if (tboard[i][r] != a[j]) break;
		}
		for (auto &x : tboard) board.push_back(x);
		if (i == tboard.size()) board.push_back(b);
		else board.push_back(a);
	}
}

int main() {
	FILE *fp = fopen("B-small-attempt1.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int T;
	fscanf(fp, "%d", &T);
	for (int iii = 0; iii < T; ++iii) {
		fscanf(fp, "%d", &n);
		list<vector<int>> nums;
		for (int i = 0; i < n + n - 1; ++i) {
			nums.push_back(vector<int>());
			for (int j = 0; j < n; ++j) {
				int tmp;
				fscanf(fp, "%d", &tmp);
				nums.back().push_back(tmp);
			}
		}
		list<vector<int>> tmp = nums;
		vector<vector<int>> board;
		work(nums, 0, n - 1, board);
		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			bool f = false;
			for (auto iter = tmp.begin(); iter != tmp.end(); ++iter) {
				if (*iter == board[i]) {
					tmp.erase(iter);
					f = true;
					break;
				}
			}
			if (!f) {
				ans = board[i];
				break;
			}
		}
		if (ans.empty()) {
			for (int j = 0; j < n; ++j) {
				vector<int> temp;
				for (int i = 0; i < n; ++i) temp.push_back(board[i][j]);
				bool f = false;
				for (auto iter = tmp.begin(); iter != tmp.end(); ++iter) {
					if (*iter == temp) {
						tmp.erase(iter);
						f = true;
						break;
					}
				}
				if (!f) {
					ans = temp;
					break;
				}
			}
		}
		fprintf(fout, "Case #%d:", iii + 1);
		for (int x : ans) fprintf(fout, " %d", x);
		fprintf(fout, "\n");
	}
	fclose(fp);
	fclose(fout);
	return 0;
}