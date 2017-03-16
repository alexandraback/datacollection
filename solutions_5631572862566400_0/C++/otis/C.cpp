#include<stdio.h>
#include<iostream>
#include<algorithm>
int a[1010]={},two[1010]={},max[1010]={};
int v[1010]={},stamp=0;
int C(int x){
	int i=0,y=x;
	while(v[y]!=stamp){
		v[y] = stamp;
		y = a[y];
		i++;
	}
	if(y==x) return i;
	return 0;
}
int CH(int x){
	int i=0,y=x;
	while(v[y]!=stamp&&two[y]!=1){
		v[y] = stamp;
		y = a[y];
		i++;
	}
	if(two[y]&&max[y]<i)
		max[y] = i;
	return 0;
}
void DEL(int x){
	int y=x,t;
	while(a[y]!=-1){
		t = a[y];
		a[y] = -1;
		y = t;
	}
}
int main(){
	int T,t,n,i,ans=0,x,m,j,ans2;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		ans = 0;
		ans2 = 0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			a[i]--;
			two[i] = 0;
			max[i] = 0;
		}
		for(i=0;i<n;i++){
			stamp++;
			x = C(i);
			if(x==2){
				two[i] = 1;
				two[a[i]] = 1;
			}
			if(ans<x) ans = x;
		}
		for(i=0;i<n;i++){
			stamp++;
			CH(i);
		}
		for(i=0;i<n;i++){
			if(two[i]) ans2+=max[i]+1;
		}
		
		if(ans2>ans) ans=ans2;
		
		
		printf("Case #%d: %d\n",t,ans);
	}
}
