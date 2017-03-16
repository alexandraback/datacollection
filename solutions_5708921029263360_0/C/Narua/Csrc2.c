#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN  16384

int solve(int it, int flg);

FILE *fp;
FILE *foutp;

int T,J,P,S,K;

main(int argc, char** argv)
{
	char sl[MAX_LEN+1], *rp;
	int it, ret;

	if (argc<=1) { exit(-1); }
	fprintf(stderr,"infile:  %s\n",argv[1]);

	fp=fopen(argv[1], "r");
	if (fp==NULL) { exit(-1); }

	{
		char *cp;
		char foutname[256];
		strcpy(foutname, argv[1]);
		cp=strstr(foutname, ".in");
		if (cp) {	strcpy(cp, ".out.txt"); }
		else {		strcat(foutname, ".out.txt"); }

		fprintf(stderr,"outfile: %s\n",foutname);
		foutp=fopen(foutname, "w");
		if (foutp==NULL) { exit(-1); }
	}

	rp=fgets(sl,MAX_LEN,fp);
	if (rp==NULL) exit(-1);

	T=atoi(sl);
	fprintf(stderr,"T: %d\n",T);

	for (it=1; it<=T; it++) {
		int i,j;
		int r;

		rp=fgets(sl,MAX_LEN,fp);
		if (rp==NULL) exit(-1);

		r=sscanf(sl, "%d %d %d %d", &J,&P,&S,&K);
		if (r!=4) exit (-1);

		fprintf(stderr,"[%d] %d %d %d %d\n", it, J,P,S,K);

		ret=solve(it,0);
		fprintf(stderr,"Case #%d: %d\n", it, ret);
		fprintf(foutp ,"Case #%d: %d\n", it, ret);
		ret=solve(it,1);
	}

}

int JP[101];
int PS[101];
int JS[101];

int solve(int it, int flg)
{
	int i,ret, j,p,s;
	
	for (i=0;i<100;i++) { JP[i]=PS[i]=JS[i]=0; }
	ret=0;
	for (j=0;j<J;j++) {
		for (p=0;p<P;p++) {
			for (s=0;s<S;s++) {
				if (JP[j*P+p]>=K) continue;
				if (PS[p*S+s]>=K) continue;
				if (JS[j*S+s]>=K) continue;
				JP[j*P+p]++;
				PS[p*S+s]++;
				JS[j*S+s]++;
				ret++;
				if (!flg) {	fprintf(stderr,"%d %d %d\n", j+1,p+1,s+1); }
				else	 {	fprintf(foutp ,"%d %d %d\n", j+1,p+1,s+1); }
			}
		}
	}
	return ret;
}


