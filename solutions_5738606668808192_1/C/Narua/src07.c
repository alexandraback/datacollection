#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN  1000

char instring[MAX_LEN+1];
int T;
int J,N;

long long int chkdivisor(long long int num);

typedef struct {
	long long int s3;
	long long int s2;
	long long int s1;
	long long int s0;
} LLLLint;

void LLLLclr(LLLLint *n);
void LLLLcp(LLLLint *ns, LLLLint *nd);
void LLLLadd(LLLLint *n, int add);
void LLLLmul(LLLLint *n, int mul);
long long int LLLLdiv(LLLLint *n, int div);
long long int LLLLchkdiv(LLLLint *n);

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
		LLLLint nL[11];
		LLLLint dnL[11];
		long long int dn2[11];
		long long int cnum=num;
		int d0;
		/* set num */
		numstr[N]='\0';
		for (i=2;i<=10;i++) { dn2[i]=0; }
		for (i=2;i<=10;i++) { LLLLclr(&nL[i]); }
		for (j=1;j<=N;j++) {
			d0=cnum%2;
			cnum/=2;
			for (i=2;i<=10;i++) { // base
				LLLLmul(&nL[i],i);
				LLLLadd(&nL[i],d0);
			}
			numstr[j-1]='0'+d0;
			if (cnum==0) break;
		}
//		fprintf(stderr,"%s %lld %lld %lld %lld %lld %lld %lld %lld %lld\n", numstr, n[2], n[3], n[4], n[5], n[6], n[7], n[8], n[9], n[10]);
		/* chk num */
		for (i=2;i<=10;i++) {
			dn2[i]=LLLLchkdiv(&nL[i]);
			if (dn2[i]==0) break;
		}
		if (i==11) {
			fprintf(stderr,"%s %lld %lld %lld %lld %lld %lld %lld %lld %lld\n", numstr, dn2[2], dn2[3], dn2[4], dn2[5], dn2[6], dn2[7], dn2[8], dn2[9], dn2[10]);
			fprintf(foutp,"%s %lld %lld %lld %lld %lld %lld %lld %lld %lld\n", numstr, dn2[2], dn2[3], dn2[4], dn2[5], dn2[6], dn2[7], dn2[8], dn2[9], dn2[10]);
			cnt++;
			if (cnt>=J) break;
		} else {
			fprintf(stderr,"%d %s %lld %lld %lld %lld %lld %lld %lld %lld\n", cnt, numstr, dn2[2], dn2[3], dn2[4], dn2[5], dn2[6], dn2[7], dn2[8], dn2[9], dn2[10]);
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

long long int LLLLchkdiv(LLLLint *n)
{
	long long int MN=0x100000000LL;
	LLLLint tmp;
	long long int dn,dnm,mod,lcnt;

	dnm=MN;

	for (dn=3,lcnt=0;dn<dnm;dn+=2,lcnt++) {		// LSB=1
		LLLLcp(n, &tmp);
		mod=LLLLdiv(&tmp, dn);
		if (mod==0) return dn;
		if ( (tmp.s3==0) && (tmp.s2==0) ) {
			dnm=(tmp.s1)*MN+tmp.s0;
		}
		if (lcnt>0xFFFFFF) break;
	}

	return 0;
}


void LLLLclr(LLLLint *n)
{
	n->s3=0;
	n->s2=0;
	n->s1=0;
	n->s0=0;
}

void LLLLcp(LLLLint *ns, LLLLint *nd)
{
	nd->s3=ns->s3;
	nd->s2=ns->s2;
	nd->s1=ns->s1;
	nd->s0=ns->s0;
}

void LLLLadd(LLLLint *n, int add)
{
	long long int MN=0x100000000LL;
	n->s0+=add;
	n->s1+=(n->s0/MN);
	n->s2+=(n->s1/MN);
	n->s3+=(n->s2/MN);
	n->s0%=MN;
	n->s1%=MN;
	n->s2%=MN;
}

void LLLLmul(LLLLint *n, int mul)
{
	long long int MN=0x100000000LL;
	n->s0*=mul;
	n->s1*=mul;
	n->s2*=mul;
	n->s3*=mul;
	n->s1+=(n->s0/MN);
	n->s2+=(n->s1/MN);
	n->s3+=(n->s2/MN);
	n->s0%=MN;
	n->s1%=MN;
	n->s2%=MN;
}

long long int LLLLdiv(LLLLint *n, int div)
{
	long long int MN=0x100000000LL;
	long long int mod;

	mod=n->s3%div;
	n->s3/=div;
	n->s2+=mod*MN;

	mod=n->s2%div;
	n->s2/=div;
	n->s1+=mod*MN;
	
	mod=n->s1%div;
	n->s1/=div;
	n->s0+=mod*MN;

	mod=n->s0%div;
	n->s0/=div;

	return mod;
}


