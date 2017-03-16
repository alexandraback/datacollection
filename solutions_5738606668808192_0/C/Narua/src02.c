#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN  1000

char instring[MAX_LEN+1];
int T;
int J,N;

long long int chkdivisor(long long int num);

main(int argc, char** argv)
{
	FILE *fp, *foutp;
	char sl[MAX_LEN+1], *rp;
	int it, r, i, cnt;
	long long int minnum,maxnum,num;
	char numstr[33];

	if (argc<=1) { exit(-1); }

	fprintf(stderr,"infile: %s\n",argv[1]);

	fp=fopen(argv[1], "r");
	if (fp==NULL) { exit(-1); }

	foutp=fopen("out.txt", "w");
	if (foutp==NULL) { exit(-1); }

	rp=fgets(sl,MAX_LEN,fp);
	if (rp==NULL) exit(-1);

	T=atoi(sl);
	fprintf(stderr,"T: %d\n",T);
	if (T!=1) exit (-1);

	fprintf(stderr,"Case #%d:\n",1);
	fprintf(foutp,"Case #%d:\n",1);

	rp=fgets(sl,MAX_LEN,fp);
	if (rp==NULL) exit(-1);

	r=sscanf(sl, "%d %d", &N, &J);
	if (r!=2) exit (-1);
	fprintf(stderr,"N J: %d %d\n",N, J);

	if (N>19) {
		fprintf(stderr,"N:%d too large for long long\n",N);
		exit (-1);
	}

	maxnum=1;
	for (i=1;i<=N;i++) { maxnum*=2; }
	minnum=maxnum;
	minnum/=2;
	minnum+=1;
	maxnum-=1;

	fprintf(stderr,"minnum %lld, maxnum %lld\n", minnum, maxnum);

	cnt=0;
	for (num=minnum;num<=maxnum;num+=2) {
		int i,j;
		long long int n[11];
		long long int dn[11];
		long long int cnum=num;
		int d0;
		/* set num */
		numstr[N]='\0';
		for (i=2;i<=10;i++) { n[i]=0; }
		for (j=1;j<=N;j++) {
			d0=cnum%2;
			cnum/=2;
			for (i=2;i<=10;i++) { // base
				n[i]*=i;
				n[i]+=d0;
			}
			numstr[j-1]='0'+d0;
			if (cnum==0) break;
		}
//		fprintf(stderr,"%s %lld %lld %lld %lld %lld %lld %lld %lld %lld\n", numstr, n[2], n[3], n[4], n[5], n[6], n[7], n[8], n[9], n[10]);
		/* chk num */
		for (i=2;i<=10;i++) {
			dn[i]=chkdivisor(n[i]);
			if (dn[i]==0) break;
		}
		if (i==11) {
			fprintf(stderr,"%s %lld %lld %lld %lld %lld %lld %lld %lld %lld\n", numstr, n[2], n[3], n[4], n[5], n[6], n[7], n[8], n[9], n[10]);
			fprintf(foutp,"%s %lld %lld %lld %lld %lld %lld %lld %lld %lld\n", numstr, dn[2], dn[3], dn[4], dn[5], dn[6], dn[7], dn[8], dn[9], dn[10]);
			cnt++;			
			if (cnt>=J) break;
		}
	}

}

long long int chkdivisor(long long int num)
{
	long long int dn,dnm;

	dnm=num;

	for (dn=3;dn<dnm;dn+=2) {		// LSB=1
		if ((num%dn)==0) return dn;
		dnm=num/dn;
	}

	return 0;
}

