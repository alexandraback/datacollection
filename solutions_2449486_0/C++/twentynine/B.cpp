#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int tc,n,m,i,j,k,a[103][103],jj,kk;
	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		int ans=1;
		scanf("%d %d",&n,&m);
		for(j=1;j<=n;j++)for(k=1;k<=m;k++)scanf("%d",&a[j][k]);
		for(j=1;j<=n;j++)for(k=1;k<=m;k++){
			int life=0;
			for(jj=1;jj<=n;jj++)if(a[jj][k]>a[j][k])life=1;
			if(life==1){
				for(kk=1;kk<=m;kk++)if(a[j][kk]>a[j][k])life=2;
				if(life==2)ans=0;
			}
		}
		printf("Case #%d: ",i);
		if(ans==0)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
				
		
