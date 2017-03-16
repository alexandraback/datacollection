#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	//freopen("B-small-attempt0.in","r",stdin)
	//freopen("B-small-attempt0.out","w",stdout)
	//freopen("B-large.in","r",stdin)
	//freopen("B-large.out","w",stdout)
	int nCase;
	scanf("%d", &nCase);
	for(int iCase = 1; iCase <= nCase; iCase++) {
		int d;
		vector<int> p;
		scanf("%d", &d);
		for(int i = 0; i < d; i++) {
			int x;
			scanf("%d", &x);
			p.push_back(x);
		}
		sort(p.begin(), p.end());

		int res = p[d-1];
		for(int k = res-1; k > 0; k--) {
			int cnt = 0;
			for(int i = d-1; i >= 0 && p[i] > k; i--) {
				cnt += (p[i]+k-1)/k - 1;
			}
			if(k+cnt < res)
				res = k+cnt;
			else if(cnt >= res)
				break;
		}
		printf("Case #%d: %d\n", iCase, res);
	}
	return 0;
}
