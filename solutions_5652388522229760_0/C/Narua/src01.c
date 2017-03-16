#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN  1000000

char instring[MAX_LEN+1];
int T;
int N;

void inittbl();
int chknum(int num);

main(int argc, char** argv)
{
	FILE *fp, *foutp;
	char sl[MAX_LEN+1], *rp;
	int it;

	if (argc<=1) { exit(-1); }

	fprintf(stderr,"infile: %s\n",argv[1]);

	fp=fopen(argv[1], "r");
	if (fp==NULL) { exit(-1); }

	foutp=fopen("out.txt", "w");
	if (foutp==NULL) { exit(-1); }

	rp=fgets(sl,255,fp);
	if (rp==NULL) exit(-1);

	T=atoi(sl);
	fprintf(stderr,"T: %d\n",T);

	for (it=1;it<=T;it++) {
		int i,n;
		rp=fgets(sl,255,fp);
		if (rp==NULL) exit(-1);

		N=atoi(sl);
		printf("N[%d]: %d\n",it,N);
		
		inittbl();
		
		for (i=1;i<1000;i++) {
			int ret;
			n=N*i;
			ret=chknum(n);
			if (ret<0) {
				fprintf(stderr,"Case #%d: INSOMNIA\n",it);
				fprintf(foutp,"Case #%d: INSOMNIA\n",it);
				break;
			}
			if (ret==10) {
				fprintf(stderr,"Case #%d: %d\n",it,n);
				fprintf(foutp,"Case #%d: %d\n",it,n);
				break;
			}
		}
	}
}

int digit[10],dn;

void inittbl() {
	int i;
	dn=0;
	for (i=0;i<=9;i++) digit[i]=0;
}

int chknum(int num) {
	int i,d1;
	printf("num: %d\n",num);
	if (num==0) return -1;
	for (i=0;i<=7;i++) {
		d1=num%10;
		num=num/10;
		if (digit[d1]==0) { digit[d1]=1; dn++; }
		printf("d1,num,dn: %d,%d,%d\n",d1,num,dn);
		if (num==0) break;
	}
	return dn;
}
