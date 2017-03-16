#include<stdio.h>
#include<algorithm>
int main(){
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		int n;
		char s[101];
		scanf("%s",s);
		for(n=0;s[n];n++);
		int ans=0;
		char c='+';
		for(int i=n-1;i>=0;i--){
			if(c!=s[i]){
				ans++;
				c=s[i];
			}
		}
		printf("Case #%d: %d\n",T,ans);
	}
}
