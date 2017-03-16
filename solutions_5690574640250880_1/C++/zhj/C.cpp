#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int i,j,n,m,a[55][55],T,tim,k;
void P(){
	int i,j;
	printf("c");
	for(i=1;i<=n;++i){
		for(j=(i==1)?2:1;j<=m;++j)printf("%c",a[i][j]?'.':'*');
		puts("");
	}
}
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	for(scanf("%d",&T),tim=1;tim<=T;++tim){
		scanf("%d%d%d",&n,&m,&k);
		printf("Case #%d:\n",tim);
		memset(a,0,sizeof(a));
		if(n*m-k==1){
			P();
			continue;
		}
		if(n==1){
			if(m-k<2){
				printf("Impossible\n");
				continue;
			}
			printf("c");
			for(i=2;i<=m;++i)printf(i<=m-k?".":"*");
			puts("");
		}else
		if(m==1){
			if(n-k<2){
				printf("Impossible\n");
				continue;
			}
			printf("c\n");
			for(i=2;i<=n;++i)printf(i<=n-k?".\n":"*\n");
		}else
		if((n*m-k)&1){
			if(n==2 || m==2 || n*m-k<9){
				printf("Impossible\n");
				continue;
			}
			int d=n*m-k-9;
			for(i=1;i<=3;++i)
				for(j=1;j<=3;++j)a[i][j]=1;
			for(i=4;i<=m && d>1;++i){
				a[1][i]=a[2][i]=1;
				d-=2;
			}
			for(i=4;i<=n && d>1;++i){
				a[i][1]=a[i][2]=1;
				d-=2;
			}
			for(i=3;i<=n && d;++i)
				for(j=3;j<=m && d;++j){
					if(a[i][j])continue;
					a[i][j]=1;
					d--;
				}
			if(d)for(;;);
			P();
		}else{
			if(n*m-k<4){
				printf("Impossible\n");
				continue;
			}
			int d=n*m-k-4;
			a[1][1]=a[1][2]=a[2][1]=a[2][2]=1;
			for(i=3;i<=m && d;++i){
				a[1][i]=a[2][i]=1;
				d-=2;
			}
			for(i=3;i<=n && d;++i){
				a[i][1]=a[i][2]=1;
				d-=2;
			}
			for(i=3;i<=n && d;++i)
				for(j=3;j<=m && d;++j){
					if(a[i][j])continue;
					a[i][j]=1;
					d--;
				}
			P();
			if(d)for(;;);
		}
	}
}
