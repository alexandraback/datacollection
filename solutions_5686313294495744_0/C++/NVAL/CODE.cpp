#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <complex>
#include <queue>

using namespace std;

#pragma comment(linker, "/STACK:100000000")

#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()

string mas1[20];
string mas2[20];

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		int N;
		scanf("%d", &N);
		for(int i = 0; i < N; i++) cin >> mas1[i] >> mas2[i];
		int res = 0;
		for(int mask = 0, mm = 1 << N; mask < mm; mask++) {
			int cnt = 0;
			for(int i = 0; i < N; i++) {
				if(mask & (1 << i)) cnt++;
			}
			if(cnt <= res) continue;
			vector<string> t1, t2;
			for(int i = 0; i < N; i++) {
				if(mask & (1 << i)) {

				}
				else {
					t1.pb(mas1[i]);
					t2.pb(mas2[i]);
				}
			}
			int wtf = 0;
			for(int i = 0; i < N; i++) {
				if(mask & (1 << i)) {
					bool ok1 = false;
					bool ok2 = false;
					for(int j = 0; j < sz(t1); j++) {
						if(t1[j] == mas1[i]) ok1 = true;
						if(t2[j] == mas2[i]) ok2 = true;
					}
					if(ok1 && ok2) wtf++;
				}
			}

			if(wtf > res) res = wtf;
		}
		printf("Case #%d: %d\n", t, res);
	}


	return 0;
}