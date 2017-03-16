#define _CRT_SECURE_NO_DEPRECATE
//#define _CRT_RAND_S

//#include <windows.h>
//#include <tchar.h>
//#include <atlbase.h>
//#include <winerror.h>

#include <stdint.h>
#include <climits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <string>
#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int64_t isq(int32_t x) { return int64_t(x)*x; }
int64_t isq(int64_t x) { return int64_t(x)*x; }
int32_t isqrt(int64_t x) { if (x <= 0) return 0; int32_t q = int32_t(floor(sqrt(double(x)))); while (isq(q) > x) q--; while (isq(q+1) <= x) q++; return q; }
int32_t isqrtc(int64_t x) { if (x <= 0) return 0; int32_t q = int32_t(ceil(sqrt(double(x)))); while (isq(q) < x) q++; while (q > 0 && isq(q-1) >= x) q--; return q; }

int mk[256];
set<int> s;
vector<int> vl;
vector<vector<int>> vk;
vector<map<int, int>> vmk;
vector<int> vr;
int rec() {
	if (s.empty()) return 1;
	for (auto it = s.begin(); it != s.end(); it++) {
		int i = *it;
		if (mk[vl[i]] > 0) {
			s.erase(i);
			vr.push_back(i);
			mk[vl[i]]--;
			for (int j = 0; j < (int) vk[i].size(); j++)
				mk[vk[i][j]]++;
			if (rec()) return 1;
			for (int j = 0; j < (int) vk[i].size(); j++)
				mk[vk[i][j]]--;
			mk[vl[i]]++;
			vr.pop_back();
			s.insert(i);
			it = s.find(i);
			// if the chest contains key which could unlock itself, no key is lost after opening it
			// hence if there is no solution now, there is no solution whatsoever in this branch
			if (vmk[i][vl[i]] > 0) return 0;
			// unrolling one level: if the unlockable descendant of this chest contains this key, there is no solution
			for (auto it2 = s.begin(); it2 != s.end(); it2++) {
				if (*it2 != i && vmk[i][vl[*it2]] > 0 && vmk[*it2][vl[i]] > 0) return 0;
			}
			// if there is no other chest that require this key, there is also no solution in this branch
			int req = 0;
			for (auto it2 = s.begin(); it2 != s.end(); it2++)
				if (*it2 != i && vl[*it2] == vl[i]) req = 1;
			if (!req) return 0;
		}
	}
	return 0;
}

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int k, n; scanf("%d %d", &k, &n);
		for (int i = 0; i < 256; i++)
			mk[i] = 0;
		for (int i = 0; i < k; i++) {
			int a; scanf("%d", &a);
			mk[a]++;
		}
		s.clear();
		vl.assign(n, 0);
		vk.assign(n, vector<int>());
		vmk.assign(n, map<int, int>());
		for (int i = 0; i < n; i++) {
			s.insert(i);
			int k; scanf("%d %d", &vl[i], &k);
			for (int j = 0; j < k; j++) {
				int a; scanf("%d", &a);
				vk[i].push_back(a);
				vmk[i][a]++;
			}
		}
		vr.clear();
		rec();
		printf("Case #%d: ", t);
		if (vr.size() > 0) {
			for (int i = 0; i < (int) vr.size(); i++)
				printf("%d ", vr[i] + 1);
			printf("\n");
		}
		else {
			printf("IMPOSSIBLE\n");
		}
		fprintf(stderr, "%d ms\n", clock());
	}
	return 0;
}
