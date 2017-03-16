#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <cstring>
using namespace std;
#define ALL(x) x.begin(),x.end()

int N;
int key_type[211];
vector<int> keys[211];
vector<int> adj[211];

bool vis[211];
int stk[211], stk_ptr = 0;
bool find_cyc(int box, int ktype, const vector<char>& used)
{
	if (vis[box]) return false;
	vis[box] = true;
	stk[stk_ptr++] = box;
	for (int i = 0; i < keys[box].size(); i++) {
		if (keys[box][i] == ktype) {
			return true;
		}
	}
	for (int i = 0; i < adj[box].size(); i++) {
		if (!used[adj[box][i]] && find_cyc(adj[box][i], ktype, used)) {
			return true;
		}
	}
	stk_ptr--;
	return false;
}

bool possible(int open, vector<char> used, multiset<int> cur_keys)
{
	while (open < N) {
		int abox = -1;
		for (int i = 0; i < N; i++) {
			if (!used[i] && cur_keys.count(key_type[i])) {
				abox = i;
				memset(vis, 0, sizeof vis);
				stk_ptr = 0;
				if (find_cyc(i, key_type[i], used)) {
					// open all of these guys
					for (int j = 0; j < stk_ptr; j++) {
						cur_keys.erase(cur_keys.find(key_type[stk[j]]));
						cur_keys.insert(ALL(keys[stk[j]]));
						used[stk[j]] = true;
						open++;
					}
					abox = -2;
					break;
				}
			}
		}

		if (abox == -1) break;
		if (abox >= 0) {
			cur_keys.erase(cur_keys.find(key_type[abox]));
			cur_keys.insert(ALL(keys[abox]));
			used[abox] = true;
			open++;
		}
	}

	return open == N;
}

int main()
{
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		int SK;
		cin >> SK >> N;

		multiset<int> cur_keys;
		while (SK--) {
			int key; cin >> key;
			cur_keys.insert(key);
		}

		for (int i = 0; i < N; i++) {
			keys[i].clear();
			int K; cin >> key_type[i] >> K;
			while (K--) {
				int key; cin >> key;
				keys[i].push_back(key);
			}
		}

		for (int i = 0; i < N; i++) {
			adj[i].clear();
			for (int j = 0; j < keys[i].size(); j++) {
				for (int k = 0; k < N; k++) {
					if (key_type[k] == keys[i][j]) {
						adj[i].push_back(k);
					}
				}
			}
		}

		vector<int> seq;
		vector<char> used(N);
		if (possible(0, used, cur_keys)) {
			for (int rounds = 0; rounds < N; rounds++) {
				for (int i = 0; i < N; i++) {
					if (!used[i] && cur_keys.count(key_type[i])) {
						multiset<int> new_keys = cur_keys;
						new_keys.erase(new_keys.find(key_type[i]));
						new_keys.insert(ALL(keys[i]));
						used[i] = true;
						if (possible(rounds+1, used, new_keys)) {
							cur_keys = new_keys;
							seq.push_back(i);
							break;
						}
						used[i] = false;
					}
				}
			}
		}

		printf("Case #%d:", tt);
		if (seq.empty()) {
			puts(" IMPOSSIBLE");
		} else {
			for (int i = 0; i < seq.size(); i++) {
				printf(" %d", seq[i]+1);
			}
			puts("");
		}
	}
}
