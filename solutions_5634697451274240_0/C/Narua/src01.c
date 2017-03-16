#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN  1000

char instring[MAX_LEN+1];
int T;
int N;

void inittbl();
int chknum(int num);

int solve(char* pancake, int max);

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
		int i,l,ret;
		rp=fgets(sl,MAX_LEN,fp);
		if (rp==NULL) exit(-1);

		l=strlen(sl);
		fprintf(stderr,"[%d]: (%d) %s\n",it,l,sl);
		ret=solve(sl,l);
		fprintf(stderr,"Case #%d: %d\n",it,ret);
		fprintf(foutp,"Case #%d: %d\n",it,ret);
	}
}

int solve(char* pancake, int max)
{
	int cnt=0;
	int i,s0;
	
	s0=(pancake[0]=='+')?1:0;
	
	for (i=0;i<max;i++) {
		int side;
		if (pancake[i]=='+') { side=1; }
		else if (pancake[i]=='-') { side=0; }
		else { break; }
		
//		fprintf(stderr,"s0=%d,side=%d, cnt=%d\n",s0,side,cnt);
		
		if (side==s0) { continue; }
		cnt++;
		s0=side;
//		fprintf(stderr,"flip:s0=%d,side=%d, cnt=%d\n",s0,side,cnt);
	}
	
	/* last */
	if (s0==0) { cnt++; }
	
//	fprintf(stderr,"ret:%d\n",cnt);
	
	return cnt;
}

