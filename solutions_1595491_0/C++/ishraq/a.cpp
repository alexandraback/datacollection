#include <cstdio>
#include <algorithm>

using namespace std;

bool m(int a, int b) {return a > b;}

int main() {
	int t;
	scanf("%d", &t);
	for (int rayge = 1; rayge <= t; rayge++) {
	
		int n, s, p, v[1000];
		scanf("%d %d %d", &n, &s, &p);
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}
		
		sort(v, v + n, m);
		
		int i;
		for (i = 0; i < n; i++) {
			//can be made non-special
			if (v[i] >= p + max(p - 1, 0) * 2);
			else {
				//can be made special?
				if (v[i]  >= p + max(p - 2, 0) * 2) {
					s--;
					if (s < 0) break;
				} else break;
			}
		}
		printf("Case #%d: %d\n", rayge, i);
	}
}