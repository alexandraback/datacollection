#include <stdio.h>
char s[1002];
int main(){
	int i,j,k;
	int T,TN;
	int n,m,need;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		scanf("%d%s",&n,s);
		m=0;
		need=0;
		for(i=0;i<=n;i++){
			if(m<i&&need<i-m){
				need=i-m;
			} 
			m+=s[i]-'0';
		}
		printf("Case #%d: %d\n",T,need);
	}
}
