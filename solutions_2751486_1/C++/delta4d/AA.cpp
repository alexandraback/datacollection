#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 1000000 + 86;
const int INF = 0x3f3f3f3f;

char s[MAXN];
int n, l;

vector <pair<int, int> > x;

bool V(const char x) {
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}

void init() {
	l = strlen(s);	
	x.clear();
	int cc = 0;
	for (int i=0; i<l; ++i) {
		if (V(s[i])) {
			if (cc >= n) x.push_back(make_pair(i-cc, i-1));
			cc = 0;	
		} else {
			++cc;	
		}
	}
	if (cc >= n) x.push_back(make_pair(l-cc, l-1));
}

int main() {
	int tc, cn = 0;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%s%d", s, &n);
		init();
		LL tot = 0;
		if (n == 0) {
			tot = (LL)l * (l + 1) / 2;
		} else {
			int sz = x.size();
			for (int i=0; i<l; ++i) {
				pair <int, int> a = make_pair(i, -1);
				int k = lower_bound(x.begin(), x.end(), a) - x.begin();	
//				if (k >= sz) printf("+++ %d\n", k);
//				else printf("[%d, %d]\n", x[k].first, x[k].second);
				if (k > 0 && x[k-1].first < i) {
					if (x[k-1].second - i + 1 >= n)	tot += l - i - n + 1;
					else if (k <= sz - 1) tot += l - x[k].first - n + 1;
				} else if (k <= sz - 1) {
					tot += l - x[k].first - n + 1;	
				}
//				printf("tot: %lld\n", tot);
			}
		}
		printf("Case #%d: %lld\n", ++cn, tot);
	}

	return 0;
}
