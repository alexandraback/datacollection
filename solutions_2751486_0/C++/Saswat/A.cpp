#include <cstdio>
#include <cstring>

int main() {
	char cons[256] = "";
	cons['a'] = cons['e'] = cons['i'] = cons['o'] = cons['u'] = 1;
	
	int tests;
	scanf("%d", &tests);
	
	for(int i = 1; i <= tests; ++i) {
		int l, n, ans = 0;
		char name[1000000];
		scanf("%s %d", name, &n);
		l = strlen(name);
		
		for(int j = 0; j <= l-n; ++j) {
			for(int k = n; k <= l-j; ++k) {
				int z = 0, m = 0;
				for(int p = j; p < j+k; ++p) {
					if(!cons[name[p]])
						++z;
					else
						z = 0;
					m = z > m ? z : m;
				}
				if(m >= n)
					++ans;
			}
		}
		
		printf("Case #%d: %u\n", i, ans);
	}
}
