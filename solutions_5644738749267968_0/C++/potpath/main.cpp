#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int T,n,q[1000],w[1000];
	scanf("%d",&T);
	for (int iT=1; iT<=T; ++iT) {
		int war=0,dwar=0;
		scanf("%d",&n);
		for (int i=0; i<n; ++i) {
			scanf("%*c0.%d",&q[i]);
		}
		for (int i=0; i<n; ++i) {
			scanf("%*c0.%d",&w[i]);
		}
		sort(q,q+n);
		sort(w,w+n);
		int i=0,j=0;
		for (; i<n&&j<n; ++i) {
			while (j<n&&w[j]<q[i]) {
				++j;
			}
			if (j++==n) {
				break;
			}
		}
		war=n-i;
		for (i=0,j=0; i<n&&j<n; ++i) {
			while (j<n&&q[j]<w[i]) {
				++j;
			}
			if (j++==n) {
				break;
			}
		}
		dwar=i;
		printf("Case #%d: %d %d\n",iT,dwar,war);
	}
    return 0;
}