#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<math.h>

int main(){
	int k,i,c=0,j;
	freopen("pCout.txt","w",stdout);
	puts("Case #1:");
	for(k=1;k<=500;k++){
		i=k;
		printf("11");
		for(j=1;j<=14;j++){
			if(i%2) printf("11");
			else printf("00");
			i/=2;
		}
		printf("11 ");
		for(j=2;j<=10;j++) printf("%d ",j+1);
		puts("");
	}
}

