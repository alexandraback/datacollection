#include<stdio.h>
#include<iostream>
#include<algorithm>


int main(){
	int T,t,n,i;
	int a[10000]={};
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d",&n);
		for(i=0;i<(2*n-1)*n;i++)
			scanf("%d",&a[i]);
		std::sort(a,a+i);
		n = i;
		printf("Case #%d:",t);
		for(i=0;i<n;i++){
			if(i+1<n&&a[i]==a[i+1]) i++;
			else printf(" %d",a[i]);
		}
		puts("");
	}
}
