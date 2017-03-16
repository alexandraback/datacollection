#include <stdio.h>
#include <algorithm>

#define N 1010

using namespace std;

double a[N],b[N];
int t,n;

int main() {
	scanf("%d",&t);
	for(int Case = 1;Case <= t;Case++) {
		scanf("%d",&n);
		for(int i=0;i<n;i++) {
			scanf("%lf",&a[i]);
		}
		for(int i=0;i<n;i++) {
			scanf("%lf",&b[i]);
		}
		sort(a,a+n);
		sort(b,b+n);
		int A = 0,B = n;
		while(A < B) {
			int m = (A+B)/2 + 1;
			bool f = false;
			for(int i=n-m,j=0;i<n;i++,j++) {
				if(a[i] < b[j]) {
					f = true;
				}
			}
			if(f == true) {
				B = m-1;
			}else {
				A = m;
			}
		}
		int i,j;
		for(i=0,j=0;i < n && j < n;) {
			if(a[i] < b[j]) {
				i++;
				j++;
			}else {
				j++;
			}
		}
		printf("Case #%d: %d %d\n",Case,A,n-i);
	}
	return 0;
}
