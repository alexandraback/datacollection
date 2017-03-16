#include<stdio.h>
#include<stdlib.h>
#include<iostream>
struct ee{int x,y,e;}a[1010];
bool cmp(struct ee x,struct ee y){return x.y<y.y;}
int main(){
	freopen("B-large.in","r",stdin);
	freopen("B-large.txt","w",stdout);
	int t,T,n,i,ans,s,j;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%d%d",&a[i].x,&a[i].y);a[i].e=0;}
		std::sort(a,a+n,cmp);
		for(i=0,ans=0,s=0;i<n;i++,ans++){
			if(a[i].y<=s){if(a[i].e==0)s+=2;else s++;continue;}
			for(j=n-1;j>=i;j--)if(a[j].x<=s&&a[j].e==0){s++;a[j].e=1;break;}
			if(j<i)break;
			i--;
		}
		if(i==n)printf("Case #%d: %d\n",t,ans);
		else printf("Case #%d: Too Bad\n",t);
	}
	
} 
