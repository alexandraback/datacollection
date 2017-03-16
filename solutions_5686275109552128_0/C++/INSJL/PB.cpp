#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	while(cin >> T){
		int num[1001],min=0;
		for(int i=1;i<=T;i++){
			int n;
			scanf("%d",&n);
			for(int j=1;j<=n;j++){
			   scanf("%d",&num[j]);
			   if(num[j]>min)min=num[j];			
			}
		int ans=min;
		for(int i=1;i<min;i++){
			int a=0;
			for(int j=1;j<=n;j++){
			   if(num[j]%i==0)a+=num[j]/i-1;
			   if(num[j]%i!=0)a+=num[j]/i;   }
			if(a+i<ans)ans=a+i;
		}
			printf("Case #%d: %d\n",i,ans);
		}
		
	}
	return 0;
}
