#include<stdio.h>
char S[1000],temp[3000];
int main(){
	int t,i,j,k,len,l,r;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%s",S);
		len = strlen(S);
		l = r = 1000;
		temp[l] = S[0];
		for(j=1;j<len;j++){
			if(S[j]<temp[l]){
				temp[++r] = S[j];
			}else{
				temp[--l] = S[j];
			}
		}
		printf("Case #%d: ",i+1);
		for(j=l;j<=r;j++){
			printf("%c",temp[j]);
		}
		printf("\n");
	}
	return 0;
}
