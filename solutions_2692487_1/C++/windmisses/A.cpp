#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int cases;

const int N = 111;
int size, n;
int num[N];

int main() {
	scanf("%d", &cases);
	for (int ca = 1; ca <= cases; ca++) {
		printf("Case #%d: ", ca);
			
		scanf("%d %d", &size, &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &num[i]);
		
		sort(num + 1, num + n + 1);
		int best = n;
		for (int k = n; k >= 0; k--) {
			long long v = size;
			
			int cnt = n - k;
			bool ok = true;
			for (int i = 1; i <= k; i++) 
				if (v > num[i]) {
					v += num[i];
				}
				else {
					if (v == 1) {
						ok = false;
						break;
					}
					while (v <= num[i]) {
						++cnt;
						v += v - 1;
					}
					v += num[i];
				}
			if (!ok) continue;
			
			if (cnt < best) best = cnt;
		}
		
		printf("%d\n", best);
	}
    
    return 0;
}
