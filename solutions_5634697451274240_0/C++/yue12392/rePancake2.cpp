#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int T,ans,tot,j;
char arr[12];

int main(){
	freopen("revPancake.in","r",stdin);
	freopen("revPancake.out","w",stdout);
	
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf(" %s",arr);
		tot=strlen(arr);
		
		j=0; ans=0;
		while(j<tot){
			while((arr[j]==arr[j+1])&&(j<tot)) j++;
			ans++;
			j++;
		}
		
		if (arr[tot-1]=='+') ans--;
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}

