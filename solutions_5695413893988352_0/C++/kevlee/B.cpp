#include <bits/stdc++.h>
using namespace std;
int T;
char s[20], t[20], a[20], b[20];
int main () {
	freopen("B-small.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
	scanf("%d", &T);
	for (int test=1; test<=T; test++) {
		scanf("%s %s", s, t);
		int n=strlen(s), m=strlen(t), s1, s2, s3, s4;
		if (n==1) s1=0, s2=9;
		if (n==2) s1=0, s2=99;
		if (n==3) s1=0, s2=999;
		if (m==1) s3=0, s4=9;
		if (m==2) s3=0, s4=99;
		if (m==3) s3=0, s4=999;
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		int ab=INT_MAX, x, y;
		for (int i=s1; i<=s2; i++) {
			for (int j=s3; j<=s4; j++) {
				if (n==1) {
					a[0]=i+'0';
				} else if (n==2) {
					a[0]=i/10+'0';
					a[1]=i%10+'0';
				} else {
					a[0]=i/100+'0';
					a[1]=(i/10)%10+'0';
					a[2]=i%10+'0';
				}
					if (m==1) {
					b[0]=j+'0';
				} else if (m==2) {
					b[0]=j/10+'0';
					b[1]=j%10+'0';
				} else {
					b[0]=j/100+'0';
					b[1]=(j/10)%10+'0';
					b[2]=j%10+'0';
				}
				bool ok=true;
				for (int k=0; k<n; k++) {
					if (s[k]!='?'&&s[k]!=a[k]) ok=false;
				}
				for (int k=0; k<m; k++) {
					if (t[k]!='?'&&t[k]!=b[k]) ok=false;
				}
				if (!ok) continue;
				if (abs(i-j)<ab) {
					ab=abs(i-j);
					x=i;
					y=j;
				} else if (abs(i-j)==ab) {
					if (i<x) x=i, y=j;
					else if (i==x&&j<y) x=i, y=j;
				}
			}
		}
		printf("Case #%d: ", test);
		if (n==1) printf("%d", x);
		else if (n==2) printf("%d%d", x/10, x%10);
		else printf("%d%d%d", x/100, (x/10)%10, x%10);
		printf(" ");
		if (m==1) printf("%d", y);
		else if (m==2) printf("%d%d", y/10, y%10);
		else printf("%d%d%d", y/100, (y/10)%10, y%10);
		printf("\n");
	}
}
