#include<stdio.h>
#include<iostream>
using namespace std;
typedef long long ll;
int e,r,n;
int arr[10];
int go(int i, int en){
	if(i==n) return 0;
	int ret=0;
	for(int j=0;j<=en;j++){
		int num=arr[i]*j+go(i+1,min(en-j+r,e));
		ret=max(ret,num);	
	}
	return ret;
}
int main(){
	freopen("F:\\inputB.in","r",stdin);
	freopen("F:\\output.txt","w",stdout);
	//cout<<"ready";
	int T;
	scanf("%d",&T);	
	for(int I=1;I<=T;I++) {		
		cin>>e>>r>>n;		
		for(int i=0;i<n;i++) cin>>arr[i];
		int ans=go(0,e);
		printf("Case #%d: %lld\n",I,ans);
	}
	return 0;
}
