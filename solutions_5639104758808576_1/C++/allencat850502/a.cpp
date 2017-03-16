#include <stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int N;
		scanf("%d",&N);
		char s[1010];
		scanf("%s",s);
		int sum=0;
		int add=0;
		for(int i=0;i<=N;i++){
			if(s[i]=='0')continue;
			if(sum<i)add+=i-sum,sum=i;
			sum+=s[i]-'0';
		}
		printf("Case #%d: %d\n",t,add);
	}
}
