#include <cstdio>
#include <cmath>
using namespace std;

int t,r;

int T,R,N,M,K;
int max(int a, int b) {
	if(a>b) return a;
	return b;
}
int factorset[10],curfactorset[10];
int factors[3] = {2,3,5};
void testc() {
	scanf("%d %d %d %d\n",&R,&N,&M,&K);
	for(int r=0;r<R;r++) {
		factorset[2]=0;
		factorset[3]=0;
		factorset[5]=0;
		int Z;
		for(int k=0;k<K;k++) {
			scanf("%d",&Z);
			curfactorset[2]=0; curfactorset[3]=0;curfactorset[5]=0;
			while(Z%2==0) { curfactorset[2]++; Z/=2;}
			while(Z%3==0) { curfactorset[3]++; Z/=3;}
			while(Z%5==0) { curfactorset[5]++; Z/=5;}
			factorset[2] = max(factorset[2],curfactorset[2]);
			factorset[3] = max(factorset[3],curfactorset[3]);
			factorset[5] = max(factorset[5],curfactorset[5]);
		}
		int n = 3;
		int printed = 0;
		while(factorset[5]) { printf("5"); factorset[5]--; n--;printed++;}
		while(factorset[3]) { printf("3"); factorset[3]--; n--;printed++;}
		if(n==1) {
			if(factorset[2]>0) {
				int r = 1;
				while(factorset[2]) { r*=2; factorset[2]--;}
				printf("%d",r);printed++;
			}
		}
		if(n==2) {
			if(factorset[2]==2) {
				printf("22"); printed+=2;
			}
			if(factorset[2]==3) {
				printf("42"); printed+=2;
			}
			if(factorset[2]==4) {
				printf("44"); printed+=2;
			}
		}
		if(n==3) {
			if(factorset[2]==3) {
				printf("222"); printed+=3;
			}
			if(factorset[2]==4) {
				printf("422"); printed+=3;
			}
			if(factorset[2]==5) {
				printf("442"); printed+=3;
			}
			if(factorset[2]==6) {
				printf("444"); printed+=3;
			}
		}
		while(printed<3) {
			printf("2");
			printed++;
		}
		if(printed>3) {
			printf("ERROR");
		}
		printf("\n");
	}
}

int main() {
	scanf("%d\n",&T);
	for(int t=0;t<T;t++) {
		printf("Case #%d:\n",t+1);
		testc();
	}

}