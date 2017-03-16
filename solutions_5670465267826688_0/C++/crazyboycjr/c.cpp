#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
#define rep(i,l,r) for (int i=(l);i<=(r);i++)

typedef long long LL;
const int maxn=10300;
const int a[9][9]={
	{},
	{0,1,2,3,4,5,6,7,8},
	{0,2,5,4,7,6,1,8,3},
	{0,3,8,5,2,7,4,1,6},
	{0,4,3,6,5,8,7,2,1},
	{0,5,6,7,8,1,2,3,4},
	{0,6,1,8,3,2,5,4,7},
	{0,7,4,1,6,3,8,5,2},
	{0,8,7,2,1,4,3,6,5}
};
int s[maxn];
int L;
LL X;
bool ft;

int power(int S,LL n) {
	int t=1;
	for (;n;n>>=1) {
		if (n&1) t=a[t][S];
		S=a[S][S];
	}
	return t;
}

int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T;scanf("%d\n",&T);
	rep(t,1,T) {
		printf("Case #%d: ",t);
		ft=false;
		cin>>L>>X;
		scanf("\n");
		int S=1;
		rep(i,1,L) {
			char ch;
			scanf("%c",&ch);
			s[i]=ch-'i'+2;
			S=a[S][s[i]];
		}
		scanf("\n");
		int p=S;
		S=1;
		rep(j,1,X%4+4)
			S=a[S][p];
		if (S!=5) {
			puts("NO");
			continue;
		}
		int tS=1;
		LL k,l;
		k=X*L+1;l=0;
		rep(j,1,min(4LL,X)) {
			rep(i,1,L) {
				tS=a[tS][s[i]];
				if (tS==2) {
					k=(j-1)*L+i;
					break;
				}
			}
			if (tS==2) break;
		}
		tS=1;
		rep(j,1,min(4LL,X)) {
			for (int i=L;i>=1;i--) {
				tS=a[s[i]][tS];
				if (tS==4) {
					l=(X-j)*L+i;
					break;
				}
			}
			if (tS==4) break;
		}
		if (k<l) ft=true;
		else ft=false;
		puts(ft?"YES":"NO");
	}
	return 0;
}
