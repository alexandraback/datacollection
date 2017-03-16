#include<stdio.h>
int n,ca;
char ch[1003];
int main(){
	scanf("%d",&ca);
	for(int cas=1;cas<=ca;cas++){
		scanf("%d%s",&n,ch);
		int add=0,ct=0;
		for(int i=0;i<=n;i++){
			if(add+ct<i)add=i-ct;
			ct+=ch[i]-'0';
		}
		printf("Case #%d: %d\n",cas,add);
	}
}
