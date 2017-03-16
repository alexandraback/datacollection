#include <stdio.h>

int main(){
	int i,j,k,r,cases,lawn[100][100],clear,rowmax[100],colmax[100],row,col;
	//freopen("b.in","r",stdin);
	//freopen("b.out","w+",stdout);
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		scanf("%d %d",&row,&col);
		for(r=0;r<row;r++) rowmax[r] = 0;
		for(r=0;r<col;r++) colmax[r] = 0;
		for(j=0;j<row;j++){
			for(k=0;k<col;k++){
				scanf("%d",&lawn[j][k]);
				if(lawn[j][k]>rowmax[j]){
					rowmax[j] = lawn[j][k];
				}
				if(lawn[j][k]>colmax[k]){
					colmax[k] = lawn[j][k];
				}
			}
		}
		
		clear = 1;
		for(j=0;j<row;j++){
			for(k=0;k<col;k++){
				if(lawn[j][k]<rowmax[j] && lawn[j][k]<colmax[k]){
					clear = 0;
					break;
				}
			}
			if(clear == 0) break;
		}
		
		if(clear == 0){
			printf("Case #%d: NO\n",i+1);
		}
		else{
			printf("Case #%d: YES\n",i+1);
		}
	}
	return 0;
}
