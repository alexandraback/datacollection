#include "iostream"
#include "cstring"
#include "cstdio"
using namespace std;
const int N = 110;
int a[N][N];
int check(int n,int m)
{
	int sum=n*m;
	while(1){
		if(sum==0) return true;
		int minval=111;
		int mx,my;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]==0) continue;
				if(minval>a[i][j]){
					minval=a[i][j];
					mx=i;my=j;
				}
			}
		}
		bool flag=0;
		for(int j=1;j<=m;j++){
			if(a[mx][j]>minval){
				flag=1;
				break;
			}
		}
		if(!flag){
			for(int j=1;j<=m;j++){
				if(a[mx][j]!=0){
					a[mx][j]=0;
					sum--;
				}
			}
		}else{
			for(int j=1;j<=n;j++){
				if(a[j][my]>minval) return false;
				if(a[j][my]!=0){
					a[j][my]=0;sum--;
				}
			}
		}
	}
}
int main(void)
{
	freopen("B-small-attempt3.in","r",stdin);
	int T,g=0,n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
			}
		}
		printf("Case #%d: ",++g);
		if(check(n,m)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}