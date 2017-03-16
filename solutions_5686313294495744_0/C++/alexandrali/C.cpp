#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <vector>
#include <time.h>
#include <complex>
#include <map>
using namespace std;

const int MXL = 25, MXN = 25;

struct node {
	int x, y;
}a[MXN];
int T, n, Mytime;
bool flag[MXN], flag4[MXN];
bool flag2[MXN], flag3[MXN];
map <string, int> mm;
inline bool BFS() {
	for(int i = 1; i <= n * 2; i++) flag2[i] = flag3[i] = 0; //
	for(int i = 0; i < n; i++) flag4[i] = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++) if(flag[i]) {
		flag4[i] = 1;
		cnt++;
		flag2[a[i].x] = flag3[a[i].y] = 1;
	}
	while(cnt < n) { //
		bool ok = 0;
		for(int i = 0; i < n; i++) if(!flag4[i] && flag2[a[i].x] && flag3[a[i].y]) {
			ok = 1;
			flag2[a[i].x] = flag3[a[i].y] = 1;
			flag4[i] = 1;
			cnt++;
		}
		if(!ok) return 0;
	}
	return 1;
}
inline void solve() {
	char ch[MXL], ch2[MXL];
	scanf("%d", &T);
	for(int ii = 1; ii <= T; ii++) {
		scanf("%d\n", &n);
		mm.clear(); //
		Mytime = 0; //
		for(int i = 0; i < n; i++) {
			scanf("%s %s\n", ch, ch2);
			map<string, int> ::iterator iter = mm.find(ch);
			if(iter == mm.end()) {
				mm.insert(make_pair <string, int> (ch, ++Mytime));
				a[i].x = Mytime;
			}
			else {
				a[i].x = iter -> second;
			}
			iter = mm.find(ch2);
			if(iter == mm.end()) {
				mm.insert(make_pair <string, int> (ch2, ++Mytime));
				a[i].y = Mytime;
			}
			else {
				a[i].y = iter -> second;
			}
		}
		//for(int i = 0; i < n; i++) printf("%d %d\n", a[i].x, a[i].y);
		int maxn = 0;
		for(int i = 1; i <= (1 << n) - 1 ; i++) {
			int tmp = i, cnt = 0;
			for(int j = 0; j < n; j++) flag[j] = 0;
			int cnt2 = 0;
			while(tmp) {
				if(tmp & 1) {flag[cnt] = 1;cnt2++;}
				cnt++; tmp >>= 1;
			}
			//for(int j = 0; j < n; j++) printf("%d ", flag[j]);printf("\n");
			if(BFS()) maxn = max(maxn, n - cnt2);
		}
		printf("Case #%d: %d\n", ii, maxn);
	}
}
int main() {
	freopen("C.in","r",stdin);freopen("C.out","w",stdout);
	solve();
	return 0;
}
