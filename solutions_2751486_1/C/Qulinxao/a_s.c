#include<stdio.h>
#include<string.h>
int isV(int a){
	switch(a){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return 1;
	}
	return 0;
}
int main(){
	char s[1000010];
	long T,i,o,n,j,k,l,r;
	scanf("%ld\n",&T);
	for(i=1;i<=T;i++){
		scanf("%s %ld",s,&n);
		l=(int)strlen(s);
		o=0;r=0;j=0;k=0;
		while((j<l)&&(k<l)){
			//printf("%ld %ld %ld %ld \n",j,k,r,o);
			if(isV(s[k]))r=0;else {
				r++;
			//printf("\t%ld %ld %ld %ld \n",j,k,r,o);
				if(r==n){
					o+=(l-k)*(k+1-n-j+1);
					j=(k-n+2);
			//printf("\t\t%ld %ld %ld %ld \n",j,k,r,o);
					r--;
				}
			}
			k++;
		}
		printf("Case #%ld: %ld\n",i,o);
	}

	return 0;
}

