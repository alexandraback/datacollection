#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[100][100],b[100][100];
int n,m;

void clear() {
	int i,j;
	for (i=0;i<100;i++) {
		for (j=0;j<100;j++) {
			a[i][j]=0;
			b[i][j]=100;
		}
	}
	return;
}

void change(int k) {
	int i,j;
	bool can;
	for (i=0;i<n;i++) {
		can=true;
		for (j=0;j<m&&can;j++) {
			if (a[i][j]>k) can=false;
		}
		if (can==true) {
			for (j=0;j<m;j++) {
				b[i][j]=k;
			}
		}
	}
	for (j=0;j<m;j++) {
		can=true;
		for (i=0;i<n&&can;i++) {
			if (a[i][j]>k) can=false;
		}
		if (can==true) {
			for (i=0;i<n;i++) {
				b[i][j]=k;
			}
		}
	}
}

int main() {
	int t,tt,i,j;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++) {
		clear();
		scanf("%d%d",&n,&m);
		for (i=0;i<n;i++) {
			for (j=0;j<m;j++) {
				scanf("%d",&a[i][j]);
			}
		}
		for (i=100;i>0;i--) {
			change(i);
		}
		bool ans=true;
		for (i=0;i<n&ans;i++) {
			for (j=0;j<m&ans;j++) {
				if (a[i][j]!=b[i][j]) ans=false;
			}
		}
		if (ans) printf("Case #%d: YES\n",tt);
		else printf("Case #%d: NO\n",tt);
	}
	return 0;
}
