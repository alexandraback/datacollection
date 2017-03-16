#include<cstdio>
#include<cstring>
using namespace std;
int n,m,T,TT,i,j,k,a[110][110];
bool flag,f1,f2;
int main(){
	//freopen("B-small-attempt0.in","r",stdin);
	//freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&TT);
	for(T=1;T<=TT;T++){
		printf("Case #%d: ",T);
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)scanf("%d",&a[i][j]);
		flag=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				f1=1;f2=1;
				for(k=1;k<=m;k++)
					if(a[i][k]>a[i][j]){
						f1=0;break;
					}
				for(k=1;k<=n;k++)
					if(a[k][j]>a[i][j]){
						f2=0;break;
					}
				if(f1==0&&f2==0){flag=0;break;}
			}
			if(flag==0)break;
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
}