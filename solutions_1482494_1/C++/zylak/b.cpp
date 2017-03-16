#include <cstdio>
using namespace std;

const int MAXN = 1000;

int n, r, a[MAXN], b[MAXN];


int main()
{
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		scanf("%d", &n); r = 0;
		for (int i=0; i<n; ++i) scanf("%d%d", &a[i], &b[i]);
		
		int star = 0;
		while (star != 2*n) {
			int what = 2, mx = -1, mxi;
			
			for (int i=0; i<n; ++i) {
				if (b[i]!=-1 && star>=b[i]) { what = 0; mxi = i; break; }
				if (a[i]!=-1 && star>=a[i] && b[i]>mx) {
					what = 1; mx = b[i]; mxi = i;
				}
			}
			
			if (what == 0) {
				if (a[mxi] != -1) ++star, a[mxi] = -1;
				++star; b[mxi] = -1;
				++r;
			} else if (what == 1) {
				++star; a[mxi] = -1;
				++r;
			} else goto death;
		}
		
		printf("Case #%d: %d\n", t, r); continue;
		death: printf("Case #%d: Too Bad\n", t);
	}
	
	return 0;
}
