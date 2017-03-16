#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int main (){
	bool b[2100];
	char c[2100];
	int T,X,Y,A,B,total=0,cnt,diff,i,j;
	scanf("%d",&T);
	for (i=1;i<=T;i++){
		scanf("%d %d",&X,&Y);
		A=X;
		B=Y;
		total=abs(X)+abs(Y);
		cnt=0;
		j=0;
		while (j<total || j%2!=total%2){
			cnt++;
			j+=cnt;
		}
		diff=(j-total)/2;
		for (j=cnt;j>=1;j--){
			b[j]=0;
		}
		for (j=cnt;j>=1;j--){
			if (j<=diff){
				diff-=j;
				b[j]=1;
			}
		}
		if (X<0){
			X*=-1;
		}
		for (j=cnt;j>=1;j--){
			if (b[j]==0){
				if (X>=j){
					X-=j;
					c[j]='E';
				} else {
					c[j]='N';
				}
			} else {
				c[j]='S';
			}
			if (A<0){
				if (c[j]=='E'){
					c[j]='W';
				} else if (c[j]=='W'){
					c[j]='E';
				}
			}
			if (B<0){
				if (c[j]=='N'){
					c[j]='S';
				} else if (c[j]=='S'){
					c[j]='N';
				}
			}
    	}
    	printf("Case #%d: ",i);
    	for (j=1;j<=cnt;j++){
    		printf("%c",c[j]);
    	}
    	printf("\n");
    }
	return 0;
}
