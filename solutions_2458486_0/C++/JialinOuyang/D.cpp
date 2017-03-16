#include <algorithm>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define SIZE(v) ((int)(v).size())

#define BEGIN(v) ((v).begin())
#define END(v) ((v).end())
#define ALL(v) BEGIN(v),END(v)
#define SORT(v) sort(ALL(v))
#define UNIQUE(v) SORT(v);(v).erase(unique(ALL(v)),END(v))

#define FOR(i,l,r) for(int i=(l);i<(r);i++)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)

const int MAXN = 20;
const int MAXM = 201;

int k, n, chest[MAXN], answer[MAXN];
map<int, int> initKeyCnt, currentKeyCnt;
map<int, int> keyInChest[MAXN];
vector<int> chestLst[MAXM];
vector<int> edge[MAXN];
bool tag[MAXN];

struct State {
	int mask;
	map<int, int> keyCnt, chestCnt;
	bool updated;

	void open(int idx) {
		if (mask & (1 << idx)) return ;
//printf("open (%d)\n", idx);
		updated = true;
		mask |= 1 << idx;
		keyCnt[chest[idx]]--;
		if (!keyCnt[chest[idx]]) {
			keyCnt.erase(chest[idx]);
		}
		FOREACH(it, keyInChest[idx]) {
			keyCnt[it->first] += it->second;
			if (!keyCnt[it->first]) {
				keyCnt.erase(it->first);
			}
		}
		chestCnt[chest[idx]]--;
		if (!chestCnt[chest[idx]]) {
			chestCnt.erase(chest[idx]);
		}
	}

	State(int mask0 = 0) {
		this->mask = 0;
		keyCnt = initKeyCnt;
		chestCnt.clear();
		FOR(i, 0, n) {
			chestCnt[chest[i]]++;
			if (mask0 & (1 << i)) {
				open(i);
			}
		}
	}

	bool found;
	int openMask;

	void DFS(int openChest, int findKey) {
		if ((mask & (1 << openChest)) || tag[openChest]) return ;
		tag[openChest] = true;
		if (keyInChest[openChest].count(findKey)) {
			found = true;
			openMask |= 1 << openChest;
			return ;
		}
		FOREACH(it, edge[openChest]) {
			DFS(*it, findKey);
			if (found) {
				openMask |= 1 << openChest;
				return ;
			}
		}
	}

	bool isPossible() {
//printf("----------------start isPossible mask = %d----------------\n", mask);
//printf("keyState ="); FOREACH(it, keyCnt) printf(" (%d %d)", it->first, it->second); putchar('\n');
		FOREACH(it, keyCnt) {
			if (it->second < 0) {
				return false;
			}
		}
		while (true) {
			updated = false;
//printf("keyState ="); FOREACH(it, keyCnt) printf(" (%d %d)", it->first, it->second); putchar('\n');
			FOREACH(it, keyCnt) {
				if (chestCnt.count(it->first) && chestCnt[it->first] <= it->second) {
					int keyType = it->first;
					FOREACH(jt, chestLst[keyType]) {
//printf("try direct open=%d\n", *jt);
						open(*jt);
					}
					if (updated) break;
				}
			}
			FOREACH(it, keyCnt) {
				FOREACH(jt, chestLst[it->first]) {
					memset(tag, 0, sizeof(tag));
					found = false;
					openMask = 0;
					DFS(*jt, it->first);
					if (found) {
						updated = true;
//printf("found key=%d openMask=%d\n", it->first, openMask);
						FOR(i, 0, n) {
							if (openMask & (1 << i)) {
								open(i);
							}
						}
						break;
					}
				}
				if (updated) break;
			}
			if (!updated || mask == (1 << n) - 1) break;
		}
//puts("----------------end isPossible----------------");
		return mask == (1 << n) - 1;
	}
};

void init() {
	FOR(i, 0, MAXM) chestLst[i].clear();
	scanf("%d%d", &k, &n);
	initKeyCnt.clear();
	FOR(i, 0, k) {
		int v;
		scanf("%d", &v);
		initKeyCnt[v]++;
	}
	FOR(i, 0, n) {
		int m;
		scanf("%d%d", &chest[i], &m);
		chestLst[chest[i]].push_back(i);
		keyInChest[i].clear();
		FOR(j, 0, m) {
			int v;
			scanf("%d", &v);
			keyInChest[i][v]++;
		}
	}
	FOR(i, 0, n) {
		edge[i].clear();
		FOR(j, 0, n) {
			if (keyInChest[i].count(chest[j])) {
				edge[i].push_back(j);
			}
		}
	}
}

State state;

int main() {
	int taskNumber;
	scanf("%d", &taskNumber);
	for (int taskIdx = 1; taskIdx <= taskNumber; taskIdx++) {
		init();
		state = State(0);
		printf("Case #%d:", taskIdx);
		if (!state.isPossible()) {
			puts(" IMPOSSIBLE");
			continue;
		}
		currentKeyCnt = initKeyCnt;
		int mask = 0;
		memset(answer, 0xFF, sizeof(answer));
		FOR(i, 0, n) {
			FOR(j, 0, n) {
				if (mask & (1 << j)) continue;
//printf("i = %d j = %d\n", i, j);
				if (currentKeyCnt.count(chest[j])) {
					state = State(mask | (1 << j));
					if (state.isPossible()) {
						answer[i] = j;
						mask |= 1 << j;
						currentKeyCnt[chest[j]]--;
						if (!currentKeyCnt[chest[j]]) {
							currentKeyCnt.erase(chest[j]);
						}
						FOREACH(it, keyInChest[j]) {
							currentKeyCnt[it->first] += it->second;
						}
						break;
					}
				}
			}
		}
		FOR(i, 0, n) {
			printf(" %d", answer[i] + 1);
		}
		putchar('\n');
	}
	return 0;
}
