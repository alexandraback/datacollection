#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i=0;i<n;++i)
typedef long long LL;
int T,Case,n,m,C,flag; char a[55][55];
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&n,&m,&C),flag=0;
		rep(i,n){rep(j,m) a[i][j]='.'; a[i][m]='\0';} a[0][0]='c';
		int u=n,v=m;
		while (C>=u || C>=v){
			if (C<v || C>=u && u<=v) {--v,C-=u; rep(i,n) a[i][v]='*';}
			else {--u,C-=v; rep(j,m) a[u][j]='*';}
		}
		if (u==1) flag=v!=1 && n!=1;
		else if (v==1) flag=m!=1;
		else if (u==2 || v==2) flag=C;
		else if (u==3 && u<=v) flag=v==3 && C==2;
		if (!flag){
			int p=u,q=v; --u,--v;
			if (C) a[--p][--q]='*',--C;
			while (C--)
				if (p>q) a[--p][v]='*';
				else a[u][--q]='*';
		}
		//rep(i,n) puts(a[i]); printf("%d %d %d\n",u,v,C);
		printf("Case #%d:\n",++Case);
		if (flag) puts("Impossible");
		else rep(i,n) puts(a[i]);
	}
	return 0;
}

