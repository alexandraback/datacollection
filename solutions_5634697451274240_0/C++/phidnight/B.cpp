#include <cstdio>

int T,N;
char str[999];
int main() {
	scanf("%d",&T);
	for(int ts=1;ts<=T;ts++) {
		scanf("%s",str);
		char nw='+';
		int len=0;
		while(str[len]!='\0') len++;
		int sol=0;
		for(int i=len-1;i>=0;i--) {
			if(str[i]!=nw) {
				nw=str[i];
				sol++;
			}
		}
		printf("Case #%d: %d\n",ts,sol);
	}
	return 0;
}
