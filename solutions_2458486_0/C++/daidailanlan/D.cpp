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

const int MAXN = 22;
const int MAXM = 300;
const int MAXMASK = 1 << 21;

int k, n, keyCnt[MAXM], keyOpen[MAXN], answer[MAXN];
vector<int> keyInside[MAXN];
vector<int> validMove[MAXMASK];
bool validForward[MAXMASK], validBackward[MAXMASK];

void init() {
	memset(keyCnt, 0, sizeof(keyCnt));
	FOR(mask, 0, 1 << n) {
		validForward[mask] = validBackward[mask] = false;
		validMove[mask].clear();
	}
	FOR(i, 0, n) {
		keyInside[i].clear();
	}
}

int main() {
	int taskNumber;
	scanf("%d", &taskNumber);
	for (int taskIdx = 0; taskIdx < taskNumber; taskIdx++) {
		scanf("%d%d", &k, &n);
		init();
		FOR(i, 0, k) {
			int v;
			scanf("%d", &v);
			keyCnt[v]++;
		}
		FOR(i, 0, n) {
			scanf("%d", &keyOpen[i]);
			int m;
			scanf("%d", &m);
			FOR(j, 0, m) {
				int v;
				scanf("%d", &v);
				keyInside[i].push_back(v);
			}
		}
		validForward[0] = true;
		FOR(mask, 0, 1 << n) {
			if (validForward[mask]) {
				FOR(i, 0, n) {
					if (mask & (1 << i)) {
						keyCnt[keyOpen[i]]--;
						FOREACH(it, keyInside[i]) {
							keyCnt[*it]++;
						}
					}
				}
				FOR(i, 0, n) {
					if (mask & (1 << i)) continue;
					if (keyCnt[keyOpen[i]] > 0) {
						validForward[mask | (1 << i)] = true;
						validMove[mask].push_back(i);
					}
				}
				FOR(i, 0, n) {
					if (mask & (1 << i)) {
						keyCnt[keyOpen[i]]++;
						FOREACH(it, keyInside[i]) {
							keyCnt[*it]--;
						}
					}
				}
			}
		}
		printf("Case #%d:", taskIdx + 1);
		if (!validForward[(1 << n) - 1]) {
			puts(" IMPOSSIBLE");
			continue;
		}
		validBackward[(1 << n) - 1] = true;
		for (int mask = (1 << n) - 1; mask >= 0; mask--) {
			if (!validForward[mask]) continue;
			FOREACH(it, validMove[mask]) {
				if (validBackward[mask | (1 << *it)]) {
					validBackward[mask] = true;
					break;
				}
			}
		}
		int mask = 0;
		FOR(i, 0, n) {
			FOREACH(it, validMove[mask]) {
				if (validBackward[mask | (1 << *it)]) {
					answer[i] = *it;
					mask |= 1 << *it;
					break;
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
