#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string.h>
bool strcmp(char a[],char b,int n){
	if(n==0)return 1;
	if(b!=a[0])return b<a[0];
	for(int i=0;i<n-1;i++)
		if(a[i]!=a[i+1])return a[i]<a[i+1];
	return a[n-1]<b;
}
using namespace std;
int main(){
	freopen("inputA","r",stdin);
	freopen("outputA","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		printf("Case #%d: ",t);
		char c[1000];
		char tmp[1000];
		scanf("%s",c);
		int l=strlen(c);
		for(int i=0;i<l;i++){
			int rsl=strcmp(tmp,c[i],i);
			if(rsl)tmp[i]=c[i];
			else{
			   	for(int j=i;j>0;j--)tmp[j]=tmp[j-1];
				tmp[0]=c[i];
			}
		}
		for(int i=0;i<l;i++)printf("%c",tmp[i]);
		puts("");
	}
}

