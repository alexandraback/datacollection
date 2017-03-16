#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 1000;

int a[N];

int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);

	int t, n, s, p, cas = 0;
	int x, y, i, tp, cnt;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &n, &s, &p);
		cnt = 0;
		for(i = 0; i < n; ++i) {
			scanf("%d", &x);
			if(x == 0) {
				if(p <= 0)	cnt++;
			} else if(x == 1) {
				if(p <= 1)	cnt++;
			} else if(x == 2) {
				if(p <= 1)	cnt++;
				else if(p <= 2 && s > 0)	{cnt++; --s;}
			} else {
				y = x/3;
				tp = x%3;
				if(tp == 0) {
					if(y >= p)	cnt++;
					else if(y + 1 >= p && s > 0)	{cnt++; --s;}
				} else if(tp == 1){
					if(y + 1 >= p)	cnt++;
				} else if(tp == 2) {
					if(y + 1 >= p)	cnt++;
					else if(y + 2 >= p && s > 0)	{cnt++; --s;}
				}
			}
		}
		printf("Case #%d: %d\n", ++cas, cnt);
	}
	return 0;
}
