#include<stdio.h>
void DO(char c[]){
	int i,l_len=1,r_len=0;
	char l[1010]={},r[1010]={};
	l[0] = c[0];
	for(i=1;c[i]!=0;i++){
		if(c[i]>=l[l_len-1]) l[l_len++] = c[i];
		else r[r_len++] = c[i];
	}
	for(i=l_len-1;i>=0;i--) putchar(l[i]);
	puts(r);
}

int main(){
	int T,t,n;
	char c[1010];
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%s",c);
		printf("Case #%d: ",t);
		DO(c);
	}
}
