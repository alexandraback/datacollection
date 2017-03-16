#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main(){
	int T,I;
	scanf("%d",&T);
	for(I=1;I<=T;I++){
		int c,d,v,a[200]={},t[200]={};
		scanf("%d %d %d",&c,&d,&v);
		int i,j;
		for(i=0;i<d;i++){
			scanf("%d",&a[i]);
		}
		printf("Case #%d: ",I);
		int ans=0;
		t[0]=1;
		if(c==1){
			for(i=0;i<d;i++){
				int b[200]={};
				for(j=0;j<=v-a[i];j++){
					if(t[j]==1)b[j+a[i]]=1;
				}
				for(j=0;j<=v;j++){
					t[j]=t[j]|b[j];
				}
			}
			int nd=d;
			while(1){
				int tt=1;
				for(i=0;i<=v;i++){
					if(t[i]==0){
						tt=0;
						break;
					}
				}
				if(tt==1){
					printf("%d\n",nd-d);
					break;
				}
				int max=-1,mi,tv;
				for(j=0;j<=v;j++){
					if(t[j]==0){
						tv=j;
						break;
					}
				}
				for(i=1;i<=tv;i++){
					for(j=0;j<nd;j++){
						if(a[j]==i){
							break;
						}
					}
					if(j==nd){
						int b[100]={},nall=0;
						for(j=0;j<=v;j++)b[j+i]=t[j];
						for(j=0;j<=v;j++){
							if(b[j]==1||t[j]==1)nall++;
						}
						if(nall>max){
							max=nall;
							mi=i;
						}
					}
				}
				int b[100]={};
				for(i=0;i<=v;i++){
					b[i+mi]=t[i];
				}
				for(i=0;i<=v;i++){
					t[i]=t[i]|b[i];
				}
				a[nd]=mi;
				nd++;
				sort(a,a+nd);
				/*
				printf("\n");
				printf("mi: %d\n",mi);
				for(i=0;i<=v;i++)printf("%d ",t[i]);
				printf("\n");*/
			}
		}
	}
	return 0;
}