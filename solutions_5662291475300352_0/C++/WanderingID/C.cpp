#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0; i<int(n); ++i)
#define out(x) cout<<#x"="<<x<<endl
int d[100], h[100], m[100];
int main() {
	int T;
	scanf("%d",&T);
	REP(tt,T){
		int n, d0, d1, m0, m1;
		scanf("%d", &n);
		int cnt = 0;
		REP(i,n){
			scanf("%d%d%d", d+i, h+i, m+i);
			if(h[i]>1){
				cnt += 2;
				d0 = d[i]; d1 = d[i];
				m0 = m[i]; m1 = m[i] + 1;
			} else {
				cnt ++;
				if(cnt==1){
					d0 = d[i];
					m0 = m[i];
				} else {
					d1 = d[i];
					m1 = m[i];
				}
			}
		}
		int ans = 0;
		if (cnt == 2) {
			if (m0 < m1) {
				swap(m0, m1);
				swap(d0, d1);
			}
			// m0 >= m1
			if (m0 != m1) {
				if (d1 <= d0) { //first slow
					ans = (360 - d1) * LL(m0 - m1) >= (360 - d0 + d1) * LL(m1);
				} else { //first fast
					//(d1-d0)/(m0-m1) >= (360-d0)/m0
					if ( (d1-d0)*LL(m0) >= (360-d0)*LL(m0-m1) ) {
						ans = 0;
					} else {
						ans = (360 - d1) * LL(m0 - m1) >= (360 + d1 - d0) * LL(m1);
					}
				}
			}
		}
		printf("Case #%d: %d\n", tt+1, ans);
	}
}