#include<iostream>
using namespace std;

int main() {
	int tc; scanf("%d",&tc);
	for(int t=1;t<=tc;t++) {
		int n,s,p,k; scanf("%d%d%d",&n,&s,&p);
		int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]);
		if(p==0) printf("Case #%d: %d\n", t, n);
		else if(p==1) {
			int count = 0;
			for(int i=0;i<n;i++) if(a[i]>0) count++;
			printf("Case #%d: %d\n", t, count);
		} else {
			int minn = 3*p-3;
			int gcount = 0;
			int count = 0;
			for(int i=0;i<n;i++) {
				if(a[i] == minn || a[i] == minn-1) count++;
				else if(a[i] > minn) gcount++;
			}
			printf("Case #%d: %d\n", t, gcount+min(s,count));
			//printf("   , count = %d\n", count);
		}
	}
}
