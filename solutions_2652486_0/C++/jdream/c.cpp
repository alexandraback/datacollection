#include<cstdio>
#include<cstring>
using namespace std;
int f[10],a[10],r,n,m,k,T;
bool flag;
bool check(){
	int j,i,s,x,y;
for(j=1;j<=k;j++){
	x=1<<n;
	for(y=0;y<x;y++){
		s=1;
		for(i=1;i<=n;i++)if(y&(1<<(i-1)))
			s*=f[i];
		if(s==a[j])break;
	}
	if(y==x)return 0;
}
return 1;
}
void dfs(int i){
	int j;
	if(i>n){
		if(check()){
			flag=1;
			for(j=1;j<=n;j++)printf("%d",f[j]);
			printf("\n");
		}
		return;
	}
	for(j=2;j<=m;j++){
		f[i]=j;
		dfs(i+1);
		if(flag)return;
	}
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&T);
	printf("Case #%d:\n",1);
	scanf("%d%d%d%d",&r,&n,&m,&k);
while(r--){
	for(int i=1;i<=k;i++)scanf("%d",&a[i]);
	flag=0;
	dfs(1);
}
}