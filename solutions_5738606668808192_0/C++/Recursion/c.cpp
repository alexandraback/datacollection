#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int task,n,tot,a[50];
int main() {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	scanf("%d",&task);
	scanf("%d%d",&n,&tot);
	a[1]=a[n]=1;
	printf("Case #1:\n");
	for (int i=1;i<=tot;i++) {
		for (int i=1;i<=n;i++) printf("%d",a[i]);
		for (int i=2;i<=10;i++) printf(" %d",i+1);
		printf("\n");
		int j=n-1;
		while (a[j]) {
			a[j]=a[j-1]=0;
			j-=2;
		}
		a[j]=a[j-1]=1;
	}
	return 0;
}
