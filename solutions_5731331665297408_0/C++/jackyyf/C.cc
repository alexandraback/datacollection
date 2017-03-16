#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <stack>

using namespace std;

struct Sorter {
	int id, val;
	Sorter() {}
	Sorter(const int &i, const int &v) : id(i), val(v) {}
	inline bool operator< (const Sorter &c) const {
		return val < c.val;
	}
} S[16];

bool hasEdge[16][16];
int idx[16], val[16], id[16];
int arr[16];
int ans[16];
int n, m;

inline void update_ans(int ans[], int cur[]) {
	register int i;
	if (ans[0] == -1) {
		for(i = 0; i < n; ++ i) ans[i] = cur[i];
		return ;
	}
	for(i = 0; i < n; ++ i) {
		if (idx[ans[i]] < idx[cur[i]]) return;
		if (idx[ans[i]] > idx[cur[i]]) {
			for(i = 0; i < n; ++ i) ans[i] = cur[i];
			return ;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++ t) {
		cin >> n >> m;
		register int i;
		memset(S, 0, sizeof S);
		memset(hasEdge, 0, sizeof hasEdge);
		memset(idx, 0, sizeof idx);
		memset(id, 0, sizeof id);
		memset(ans, -1, sizeof ans);
		memset(val, 0, sizeof val);
		for(i = 1; i <= n; ++ i) {
			cin >> val[i];
			S[i].id = i, S[i].val = val[i];
		}
		for(i = 0; i < m; ++ i) {
			int x, y;
			cin >> x >> y;
			hasEdge[x][y] = hasEdge[y][x] = true;
		}
		sort(S + 1, S + n + 1);
		for(i = 1; i <= n; ++ i) {
			idx[S[i].id] = i;
			id[i] = S[i].id;
		}
		for(i = 0; i < n; ++ i) {
			arr[i] = i + 1;
		}
		stack<int> S;
		do {
			while(S.size()) S.pop();
			S.push(arr[0]);
			bool flag = true;
			for(i = 1; i < n; ++ i) {
				while(S.size() && !hasEdge[S.top()][arr[i]]) S.pop();
				if(S.empty()) {
					flag = false;
					break;
				}
				S.push(arr[i]);
			}
			if (flag) {
				update_ans(ans, arr);
			}
		} while(next_permutation(arr, arr + n));
		cout << "Case #" << t << ": ";
		for(i = 0; i < n; ++ i)
			cout << val[ans[i]];
		cout << endl;
	}
	return 0;
}
