#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int tt;
int n,m,c;
char f[50][50];

int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	scanf("%d",&tt);

	for (int ii=1;ii<=tt;++ii) {
		printf("Case #%d:\n",ii);
		bool flag=false;
		scanf("%d%d%d",&n,&m,&c);
		if (n>m) {
			swap(n,m);
			flag=true;
		}
		memset(f,0,sizeof(f));
		c=n*m-c;
		if (n==1) for (int i=0;i<c;++i) f[0][i]='.';
		if (n>=2) {
			bool ff=false;
			int pi=-1,pj=-1;
			for (int i=2;i<=n;++i)
				for (int j=2;j<=m;++j)
					if (c>=2*i+2*j-4 && c<=i*j) {
						ff=true;
						pi=i,pj=j;
						break;
					}
			if (c==1) ff=true;
			if (!ff) {
				puts("Impossible");
				continue;
			}
			c-=2*pi+2*pj-4;
			for (int i=0;i<pi;++i)
				for (int j=0;j<pj;++j)
					if (i<2 || j<2 || c>0) {
						f[i][j]='.';
						if (i>=2 && j>=2) c--;
					}
		}
		for (int i=0;i<n;++i)
			for (int j=0;j<m;++j)
				if (f[i][j]!='.') f[i][j]='*';
		f[0][0]='c';
		if (flag) swap(n,m);
		for (int i=0;i<n;++i) {
			for (int j=0;j<m;++j)
				if (flag) printf("%c",f[j][i]);
				else printf("%c",f[i][j]);
			puts("");
		}
	}
}
