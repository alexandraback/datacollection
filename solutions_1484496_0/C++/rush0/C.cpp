/*
 * Author: rush
 * Filename: C.cpp
 * Timestamp: 06/05/2012 01:22:13 CST
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#define OUT(x) cerr << #x << ": " << (x) << endl
#define SZ(x) ((int)x.size())
#define FOR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long LL;

#define TWO(x) (1 << (x))

int T, N, S[25];
map<int, vector<int> > mp;
map<int, vector<int> >::iterator it;

int main() {
	scanf("%d", &T);
	for (int id = 1; id <= T; ++id) {
		scanf("%d", &N);
		FOR(i, N) scanf("%d", &S[i]);
		mp.clear();
		for (int i = 1; i < TWO(N); ++i) {
			int sum = 0;
			FOR(j, N) if (i & TWO(j))
				sum += S[j];
			mp[sum].push_back(i);
		}
		int a = -1, b = -1;
		for (it = mp.begin(); it != mp.end(); ++it) {
			if (it->second.size() >= 2) {
				a = it->second[0];
				b = it->second[1];
				break;
			}
		}
		
		printf("Case #%d:\n", id);
		if (a == -1) {
			printf("Impossible\n");
		} else {
			FOR(j, N) if (a & TWO(j)) printf("%d ", S[j]);
			printf("\n");
			FOR(j, N) if (b & TWO(j)) printf("%d ", S[j]);
			printf("\n");
		}
	}
	return 0;
}
