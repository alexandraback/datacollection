#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char str[120];
int calc(int a){
	if(a==0)return 0;
	if(str[a-1]=='+')return calc(a-1);
	for(int i=0;i<a;i++){
		if(str[i]=='+')str[i]='-';
		else str[i]='+';
	}
	return calc(a-1)+1;
}
int main(){
	int T;scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%s",str);
		int n=strlen(str);
		int ret=calc(n);
		printf("Case #%d: %d\n",t,ret);
	}
}