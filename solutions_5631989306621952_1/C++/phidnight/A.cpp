#include <cstdio>

int T,N;
char str[9999];
char output[9999];
int main() {
	scanf("%d",&T);
	for(int ts=1;ts<=T;ts++) {
		scanf("%s",str);
		N=0;
		while(str[N]!='\0') N++;
		int lf=4000;
		int rg=4000;
		output[lf]=str[0];
		for(int i=1;i<N;i++) {
			if(output[lf]>str[i]) {
				rg++;
				output[rg]=str[i];
			} else {
				lf--;
				output[lf]=str[i];
			}
		}
		printf("Case #%d: ",ts);
		for(int i=lf;i<=rg;i++) printf("%c",output[i]);
		printf("\n");
	}
	return 0;
}
