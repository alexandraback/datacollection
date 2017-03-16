#include <cstdio>
#include <cstring>
using namespace std;

int r,n,m,k,w,a[1111];
bool f[1111111];

void Work() {
	for (int i=2;i<=5;++i)
		for (int j=2;j<=5;++j)
			for (int k=2;k<=5;++k) {
				memset(f,0,sizeof(f));
				f[1]=true;
				f[i]=f[j]=f[k]=true;
				f[i*j]=f[i*k]=f[j*k]=true;
				f[i*j*k]=true;
				bool flag=true;
				for (int p=1;p<=w;++p)
					if (!f[a[p]]) flag=false;
				if (!flag) continue;
				printf("%d%d%d",i,j,k);
				return ;
			}
}

int main() {
	freopen("C-small-1-attempt2.in","r",stdin);
	freopen("1.txt","w",stdout);
	int t;
	scanf("%d",&t);
	puts("Case #1:");
	scanf("%d%d%d%d",&r,&n,&m,&w);
	while (r--) {
		for (int i=1;i<=w;++i) scanf("%d",&a[i]);
		Work();
		puts("");
	}
	return 0;
}
