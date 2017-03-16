#include "stdio.h"
#include <math.h>
#include <algorithm>
using namespace std;

#define ll long long

int poss[12];
int possi;
int prod[12];

/*#define t21(i,j,k,ind) ((i-2)*16+(j-2)*4+k-2)*7+ind
#define Calc(i,j,k,ind,a,b,c) LB[t21(i,j,k,ind)] = a*b*c;
//int B[64];
int LB[7*64];

void init() {
	for(int i=2; i<=5; ++i) {
		for(int j=2; j<=5; ++j) {
			for(int k=2; k<=5; ++k) {
//				B[i*4*4+j*4+k] = i*100+j*10+k;
				Calc(i,j,k,0,i,j,k)
				Calc(i,j,k,1,1,i,j)
				Calc(i,j,k,2,1,j,k)
				Calc(i,j,k,3,1,k,i)
				Calc(i,j,k,4,1,1,i)
				Calc(i,j,k,5,1,1,j)
				Calc(i,j,k,6,1,1,k)
			}
		}
	}
}*/

bool check(){
	bool ret = false;
	for(int i=0; i<12; ++i) {
		if(prod[i]==1) continue;
		if(prod[i]/3==0 || prod[i]/5==0 || prod[i]/7==0 ) {
			for(int j=0; j<12; ++j)
				if(prod[j]%prod[i]==0) prod[j]/=prod[i];
//			if(find(poss,poss+7,prod[i])==poss+7) {
				poss[possi] = prod[i];
				++possi;
				ret = true;
//			}
			prod[i]=1;
		}
/*		if(prod[i]%3==0) {
		}
		if(prod[i]%5==0) {
		}
		if(prod[i]%7==0) {
		}*/
	}
	return ret;
}
int main() {
	FILE *fp, *fp2;
	int num;
	int R, N, M, K;
	
//	bool fail;

//	init();
	fopen_s(&fp, "C-small-2-attempt0.in", "r");
	fopen_s(&fp2, "C-small-2-attempt0.out", "w");
	fscanf_s(fp, "%d", &num);
	fscanf_s(fp, "%d %d %d %d", &R, &N, &M, &K);

	fprintf(fp2,"Case #1:\n");
	for(int j=0; j<R; ++j) {
		for(int k=0; k<K; ++k)
			fscanf_s(fp, "%d", &prod[k]);
		
		for(int i=0; i<12; ++i) poss[i]=2;
		possi=0;
		while(possi<12 && check());
		for(int i=0; i<12; ++i)
			fprintf(fp2, "%d", poss[i]);
		fprintf(fp2, "\n");
/*		for(int a=2;a<=5; ++a) {
			for(int b=2;b<=5;++b) {
				for(int c=2;c<=5;++c) {
					fail = false;
					for(int k=0; k<K;++k) {
						if(prod[k]!=1 && find(LB+t21(a,b,c,0),LB+t21(a,b,c,7), prod[k]) == LB+t21(a,b,c,7))
						{fail = true;break;}
					}
					if(!fail) {fprintf(fp2, "%d\n", a*100+b*10+c);break;}
				}
				if(!fail) break;
			}
			if(!fail ) break;
		}
		*/
//		if(fail) fprintf(fp2, "222\n");
	}
	
	fclose(fp);
	fclose(fp2);
	return 0;
}
