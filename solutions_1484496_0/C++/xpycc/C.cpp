#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

inline int lowbit(int x) {
	return x & -x;
}

typedef vector<int> VI;
typedef pair<int, int> PII;

int a[100];
int f[1 << 20];
map<int, VI> mp;

int main() {
	int test; scanf("%d", &test);
	for (int cas = 1; cas <= test; ++cas) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", f + (1 << i));
		mp.clear();
		f[0] = 0;
		int s1 = 0, s2 = 0;
		for (int s = 1; s < (1 << n); ++s) {
			f[s] = f[s - lowbit(s)] + f[lowbit(s)];
			mp[f[s]].push_back(s);
		}
		//puts("ppp");
		printf("Case #%d:\n", cas);
		try {
			for (map<int, VI>::iterator it = mp.begin(); it != mp.end(); ++it) {
				VI& v = it->second;
				for (int i = 0; i < v.size(); ++i)
					for (int j = 1; j < v.size(); ++j)
						if ((v[i] & v[j]) == 0)
							throw PII(v[i], v[j]);
			}
		} catch (PII& p) {
			bool fg = false;
			for (int i = 0; i < n; ++i)
				if ((1 << i) & p.first) {
					if (fg) putchar(' ');
					else fg = true;		
					printf("%d", f[1 << i]);
				}
			puts("");
			fg = false;
			for (int i = 0; i < n; ++i)
				if ((1 << i) & p.second) {
					if (fg) putchar(' ');
					else fg = true;		
					printf("%d", f[1 << i]);
				}
			puts("");
			continue;
		}
		puts("Impossible");
	}
	return 0;
}
