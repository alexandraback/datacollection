#include <iostream>
#include <cstdio>
using namespace std;
#define eps 1e-9

int a[222];
int n,S;

bool jg(int x,double m) {
	double y=0;
	for(int i=0;i<n;++i) if(i!=x) {
		if(a[i]>a[x]+S*m) continue;
		y+=(a[x]+S*m-a[i])/S;
	}
	return y>1.0-m;
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	int T,ka=0;
	scanf ("%d", &T);

	while (T--)
	{
		scanf ("%d", &n);
		S=0;
		for(int i=0;i<n;++i) scanf("%d",a+i),S+=a[i];

		printf("Case #%d:",++ka);
		for(int i=0;i<n;++i) {
			double l=0,r=1;
			while(l+eps<r) {
				double m=(l+r)/2;
				if(jg(i,m)) {
					r=m;
				} else {
					l=m;
				}
			}
			printf(" %.6lf",l*100);
		}
		puts("");
	}

	return 0;
}
