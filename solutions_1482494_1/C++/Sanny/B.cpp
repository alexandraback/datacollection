#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define rep(i,n) for(i=0;i<(n);i++)
#define MAXN 1005

struct Level {
	int a, b;
};

int n;
Level l[MAXN];
int f[MAXN];

void solve() {
	memset(f, 0, sizeof(f));
	int cur = 0, i, rem =2*n, res =0;
	int mx, pos;

	while(rem) {
		rep(i, n) if(f[i] == 0) {
			if(l[i].b <= cur) {
				rem -= 2;
				res++;
				cur += 2;
				f[i] = 2;
				goto LAST;
			}
		}
		rep(i, n) if(f[i] == 1) {
			if(l[i].b <= cur) {
				rem--;
				res++;
				cur++;
				f[i] = 2;
				goto LAST;
			}
		}
		mx = -1; pos = -1;
		rep(i, n) if(f[i] == 0) {
			if(l[i].a <= cur) {
				if(l[i].b > mx) {
					mx = l[i].b;
					pos = i;
				}
			}
		}
		if(mx > -1) {
			rem--;
			res++;
			cur++;
			f[pos] = 1;
			goto LAST;
		}
		break;
LAST:;
	}
	if(rem) printf("Too Bad\n");
	else printf("%d\n",res);
}

int main() {
	int T, kase=1;
	int i;
	scanf(" %d",&T);
	while(T--) {
		printf("Case #%d: ",kase++);
		scanf(" %d",&n);
		rep(i, n) {
			scanf(" %d %d", &l[i].a, &l[i].b);
		}
		solve();
	}
	return 0;
}
