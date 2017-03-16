#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int n,x,y,m,k;
double a[2000];

void getnum(int n) {
	m=1;
	while ((m+3)*(m+2)/2<=n) m+=2;
	k=n-m*(m+1)/2;
}

void getans() {
	memset(a,0,sizeof(a));
	double b[2000];
	if (k!=0) {
		int i=k-1,j,p;
		a[0]=0.5;
		p=0;
		while ((i)&&(p<m)) {
			b[0]=a[0]+a[p]/2;
			for (j=0;j<=p;j++) {
				b[j+1]=a[j+1]+(a[j]-a[j+1])/2;
			}
			p++;
			for (j=0;j<=p;j++) {
				//printf("%lf ",a[j]);
				a[j]=b[j];
			}
			//printf("\n");
			i--;
		}
		p=0;
		while (i) {
			for (j=m;j>p;j--) {
				a[j]=a[j]+(a[j-1]-a[j])/2;
			}
			a[p]=1;
			p++;
			i--;
		}
	}
}

int main() {
	int t,tt;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++) {
		scanf("%d%d%d",&n,&x,&y);
		getnum(n);
		if ((y+x<m)&&(y-x<m)) {
			printf("Case #%d: 1\n",tt);
		} else if ((y+x>m+1)||(y-x>m+1)) {
			printf("Case #%d: 0\n",tt);
		} else {
			getans();
			printf("Case #%d: %.8lf\n",tt,a[y]);
		}
	}
	return 0;
}
