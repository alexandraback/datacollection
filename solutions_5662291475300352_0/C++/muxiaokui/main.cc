#include <cstdio>
#include <algorithm>

using namespace std;

int n,ans;
int d1,m1,d2,m2;

int main() {
	int t,tt,h;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++) {
		scanf("%d",&n);
		scanf("%d%d%d",&d1,&h,&m1);
		if (n==1&&h==1) ans=0;
		else {
			ans=0;
			if (h==2) {
				d2=d1;
				m2=m1+1;
			} else {
				scanf("%d%d%d",&d2,&h,&m2);
				if (m2<m1) {
					swap(d1,d2);
					swap(m1,m2);
				}
			}
			if ((360ll-d1)*m1>=(720ll-d2)*m2) ans=1;
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}
