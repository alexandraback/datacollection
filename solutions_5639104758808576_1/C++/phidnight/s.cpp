#include <cstdio>

int T,N;
char num[1008];
int main() {
	scanf("%d",&T);
	for(int tn=1;tn<=T;tn++) {
		scanf("%d",&N);
		scanf("%s",num);
		int total=0;
		int sol=0;
		for(int i=0;i<=N;i++) {
			if(num[i]!='0') {
				if(total<i) {
					sol+=i-total;
					total=i;
				}
				total+=(int)(num[i]-'0');
			}
		}
		printf("Case #%d: %d\n",tn,sol);
	}
	return 0;
}
