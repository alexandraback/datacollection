#include <cstdio>
#define min2(x,y)(x<y?x:y)
#define max2(x,y)(x>y?x:y)
int test,e,r,n,a[99],dy[99][99];

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&test);
	int t,mx;
	for(t=1;t<=test;t++){
		scanf("%d %d %d",&e,&r,&n);
		int i,j,k; mx=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			for(j=0;j<=e;j++){
				dy[i][j]=0;
			}
		}
		for(i=1;i<=n;i++){
			for(j=0;j<=e;j++){
				for(k=j;k<=e;k++){
					dy[i][min2(j+r,e)]=max2(dy[i][min2(j+r,e)],dy[i-1][k]+(k-j)*a[i]);
				}
			}
		}
		for(i=0;i<=e;i++){
			if(mx<dy[n][i]){ mx=dy[n][i]; }
		}
		printf("Case #%d: %d\n",t,mx);
	}
}
