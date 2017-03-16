#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int mat[105][105];
int main(){
int t,d=0;
scanf("%d",&t);
while(d++<t){
printf("Case #%d: ",d);
int n,m,i,j,k;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&mat[i][j]);
int f1,f2;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			f1=0;f2=0;
			for(k=0;k<n;k++)
				if(mat[k][j]>mat[i][j]){
					f1=1;
					break;
				}
			
			for(k=0;k<m;k++)
				if(mat[i][k]>mat[i][j]){
					f2=1;
					break;
				}
			if(f1&&f2)
				break;
		}
		if(f1&&f2)
			break;
	}
if(f1&&f2)
	printf("NO\n");
else
	printf("YES\n");
}
return 0;
}
