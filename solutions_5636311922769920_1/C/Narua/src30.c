#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN  1000

char instring[MAX_LEN+1];

void solve(int it, int k, int c, int s);

FILE *foutp;

main(int argc, char** argv)
{
	FILE *fp;
	char sl[MAX_LEN+1], *rp;
	int T;
	int C,K,S;
	int it, r;

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

	for (it=1; it<=T; it++) {

		rp=fgets(sl,MAX_LEN,fp);
		if (rp==NULL) exit(-1);

		r=sscanf(sl, "%d %d %d", &K, &C, &S);
		if (r!=3) exit (-1);

		fprintf(stderr,"K C S: %d %d %d\n", K, C, S);
		solve (it, K, C, S);
	}

}

unsigned char rest[100];    int restcnt;
unsigned char currest[100]; int currestcnt;
unsigned char minrest[100]; int minrestcnt;
long long int ansidxlist[100];
long long int ansidxlist0[100];
int anscnt;

void solve(int it, int K, int C, int S)
{
	int anscnt, ansrest;
	long long int totcnt;
	long long int scanidx;
	long long int ic, ik, ii, il, is, scancnt;
	int tn;

	// init rest
	for (ik=0; ik<K; ik++) { rest[ik]=1; } restcnt=K;
	
	for (ic=0,totcnt=1; ic<C; ic++) { totcnt*=K; }
	scanidx=0;
	scancnt=K;
	if (C==1) scancnt=1;

//	fprintf(stderr,"totcnt %lld, scancnt %lld, S %d\n", totcnt, scancnt, S);

	// scan for ans num = S
	anscnt=0;
	for (;scanidx<totcnt;) {
		int minidx;
		minrestcnt=restcnt; minidx=-1;
		for (is=0;is<scancnt;is++,scanidx++) {
			currestcnt=0;
//			fprintf(stderr,"--[%lld]: ", scanidx);
			for (ii=0; ii<K; ii++) { // pattern L cnt=1
				tn=(int)rest[ii];
				for (ic=0,il=1;ic<C;ic++,il*=K) {
					if ( ((scanidx/il)%K)==ii ) tn=0;
				}
				currest[ii]=tn;
				if (tn) currestcnt++;
//				fprintf(stderr," %d", tn);
			}
//			fprintf(stderr,"\n", tn);
			
			//
//			fprintf(stderr,"[%lld]: (%d)", scanidx, currestcnt);
//			for (ii=0; ii<K; ii++) {
//				fprintf(stderr," %d", (int)currest[ii]);
//			}
//			fprintf(stderr,"\n");
			
			
			if (currestcnt<minrestcnt) {
				for (ii=0; ii<K; ii++) { minrest[ii]=currest[ii]; }
				minrestcnt=currestcnt;
				minidx=scanidx;
			}
		}
		if (minidx>=0) {
			ansidxlist[anscnt]=minidx+1;
			for (ii=0; ii<K; ii++) { rest[ii]=minrest[ii]; }
			restcnt=minrestcnt;
			anscnt++;
			if (restcnt==0) break;
//			fprintf(stderr,"anscnt %d\n", anscnt);
			if (anscnt>=K) break;
		}
	}

	if ( (restcnt==0) && (anscnt>=S) ) {
		int ia, anscnt0;
		anscnt0=anscnt;
		for (ii=0; ii<anscnt0; ii++) { ansidxlist0[ii]=ansidxlist[ii]-1; }
		// init rest
		for (ik=0; ik<K; ik++) { rest[ik]=1; } restcnt=K;
		for (anscnt=0;anscnt<S;) {
			int minidx;
			minrestcnt=restcnt; minidx=-1;
			for (ia=0;ia<anscnt0;ia++) {
				currestcnt=0;
				for (ii=0; ii<K; ii++) { // pattern L cnt=1
					tn=(int)rest[ii];
					for (ic=0,il=1;ic<C;ic++,il*=K) {
						if ( ((ansidxlist0[ia]/il)%K)==ii ) tn=0;
					}
					currest[ii]=tn;
					if (tn) currestcnt++;
				}

				if (currestcnt<minrestcnt) {
					for (ii=0; ii<K; ii++) { minrest[ii]=currest[ii]; }
					minrestcnt=currestcnt;
					minidx=ansidxlist0[ia];
				}
			}
			if (minidx>=0) {
				ansidxlist[anscnt]=minidx+1;
				for (ii=0; ii<K; ii++) { rest[ii]=minrest[ii]; }
				restcnt=minrestcnt;
				anscnt++;
				if (restcnt==0) break;
			}
		}
	}

	if (restcnt==0) {
		fprintf(stderr,"Case #%d:", it);
		fprintf(foutp, "Case #%d:", it);
		for (ii=0;ii<anscnt;ii++) {
		fprintf(stderr," %lld", ansidxlist[ii]);
		fprintf(foutp, " %lld", ansidxlist[ii]);
		}
		fprintf(stderr,"\n");
		fprintf(foutp, "\n");
	} else {
		fprintf(stderr,"Case #%d: IMPOSSIBLE\n", it);
		fprintf(foutp, "Case #%d: IMPOSSIBLE\n", it);
	}
}


