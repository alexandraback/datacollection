#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[4];
int a[4][4];
int num,ans;

void clear() {
	memset(a,0,sizeof(a));
	num=16;
	ans=-1;
}

void cal() {
	int i,j,k;
	k=3;
	for (i=0;i<4;i++)
		k=k&a[i][i];
	if (k!=0) {
		ans=k;
		return;
	}
	k=3;
	for (i=0;i<4;i++)
		k=k&a[i][3-i];
	if (k!=0) {
		ans=k;
		return;
	}
	for (i=0;i<4;i++) {
		k=3;
		for (j=0;j<4;j++) {
			k=k&a[i][j];
		}
		if (k!=0) {
			ans=k;
			return;
		}
	}
	for (i=0;i<4;i++) {
		k=3;
		for (j=0;j<4;j++) {
			k=k&a[j][i];
		}
		if (k!=0) {
			ans=k;
			return;
		}
	}
}

int main() {
	int t,tt,i,j;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++) {
		clear();
		for (i=0;i<4;i++) {
			scanf(" %s",s);
			for (j=0;j<4;j++) {
				if (s[j]=='.') {
					a[i][j]=0;
					num--;
				} else if (s[j]=='O') a[i][j]=1;
				else if (s[j]=='X') a[i][j]=2;
				else if (s[j]=='T') a[i][j]=3;
			}
		}
		cal();
		printf("Case #%d: ",tt);
		if (ans==1) printf("O won\n");
		if (ans==2) printf("X won\n");
		if (ans==-1) {
			if (num==16) printf("Draw\n");
			else printf("Game has not completed\n");
		}
	}
	return 0;
}
