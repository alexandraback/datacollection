#include <cstdio>
#include <cstring>
#define oo 25
int a[oo];
int n;
int b[2000005];

inline void Readin() {
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", a+i);
}

inline void Solve() {
	memset(b, -1, sizeof b);
	b[0] =  0;
	for (int i=0; i<n; ++i)
		for (int j=2000000; j>=0; --j)
			if (b[j] >= 0) {
				if (b[j+a[i]] != -1) {
					int x = b[j+a[i]], y = b[j] | (1 << i);
					//printf("%d %d\n", x,y);
					for (int k=0; k <n; ++k)
						if (((x>>k)&1) && !((y>>k)&1)) printf("%d ", a[k]);
					puts("");
					
					for (int k=0; k <n; ++k)
						if (!((x>>k)&1) && ((y>>k)&1)) printf("%d ", a[k]);
					puts("");
					
					return;
				}
				b[j+a[i]] = b[j] | (1 << i);
				
				//printf("%d\n", i);
			}
}

int main() {
	int Test, Case = 0;	
	scanf("%d", &Test);
	while (Test --) {
		printf("Case #%d:\n", ++Case);
		Readin();
		Solve();
	}
	
	return 0;
}
