#include<stdio.h>
#include<stdlib.h>


int main(int argc, char** argv) {
	int tsts;

	scanf("%d",&tsts);
	for(int t=1;t<=tsts;++t) {
		int r,c,w;
		scanf("%d %d %d",&r,&c,&w);
		int res=(c/w)*r+w-1+((c%w)!=0?1:0);

		printf("Case #%d: %d\n",t,res);
	}

	return 0;
}