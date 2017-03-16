#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	
	int array[100][100];
	int cases,i,yes,j,k,m,validrow,validcol,val,rows,cols;
	scanf("%d",&cases);
	for(i=1;i<=cases;i++){
		yes=1;
		scanf("%d",&rows);
		scanf("%d",&cols);
		for(j=0;j<rows;j++){
			for(k=0;k<cols;k++){
				scanf("%d",&array[j][k]);	
			}
		}
		for(j=0;j<rows;j++){
			for(k=0;k<cols;k++){
				val = array[j][k];
				validrow=1;validcol=1;
				//row
				for(m=0;m<cols;m++){
					if(array[j][m]>val)validrow=0;
				}
				//col
				for(m=0;m<rows;m++){
                                        if(array[m][k]>val)validcol=0;
                                }
				if(validcol==0 && validrow==0)yes=0;
				if(yes==0)break;
			}
			if(yes==0)break;
		}
		if(yes==1){
			printf("Case #%d: YES\n",i);
		}
		else if(yes==0){
			printf("Case #%d: NO\n",i);
		}
	}
	return 0;
}
