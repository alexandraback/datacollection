#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
int arr[7];
int n,m,k;
int go(int a,int b,int c){
	map<int,int> ma;
	ma[1]=1;
	ma[a]=1;
	ma[b]=1;
	ma[c]=1;
	ma[a*b]=1;
	ma[b*c]=1;
	ma[a*c]=1;
	ma[a*b*c]=1;
	for(int i=0;i<k;i++) 
	if(ma[arr[i]]==0) {
		//printf("failed %d%d%d %d %d\n",a,b,c,arr[i],ma[arr[i]]);
		return 0;
	}
	return 1;
}
int main(){
	freopen("E:\\input.in","r",stdin);
	freopen("E:\\output.txt","w",stdout);
	//cout<<"ready";
	int T;
	scanf("%d",&T);	
	scanf("%d%d%d%d",&T,&n,&m,&k);
	//printf("%d\n",T);
	puts("Case #1:");
	for(int I=1;I<=T;I++) {				
		//guess1
		int done=0;
		for(int i=0;i<k;i++) cin>>arr[i];
		for(int i=2;i<=5 && !done;i++){
			for(int j=i;j<=5 && !done;j++){
				for(int k=j;k<=5 && !done;k++){
					if(go(i,j,k)) {
						printf("%d%d%d\n",i,j,k);
						done=1;
					}
				}
			}
		}		
	}
	return 0;
}
