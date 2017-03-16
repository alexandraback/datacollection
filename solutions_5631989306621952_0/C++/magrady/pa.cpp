#include<stdio.h>
#include<algorithm>
#include<string>
char s0[1001];
int main(){
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		scanf("%s",s0);
		int n;
		for(n=0;s0[n];n++);
		std::string s;
		int i,j,k;
		for(i=0;i<n;i++){
			std::string a=s0[i]+s;
			std::string b=s+s0[i];
			if(a<b) s=b;
			else s=a;
		}
		printf("Case #%d: %s\n",T,s.c_str());
	}
}
