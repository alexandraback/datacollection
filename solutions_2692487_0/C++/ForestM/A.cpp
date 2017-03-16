#include "stdio.h"
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#define ll long long
using namespace std;

int boa[11];
int N;
int Ans[11];

int findAns(int &A, int s) {
	if(s+1-A<A) {A = 2*A-1;
		return 1;}
	A = 2*A-1;
	return findAns(A, s)+1;
}

int calc(int &A, int i) {
	int ans=0;
	int tmp;
	for(int j=i; j<N; ++j) {
		if(A<=boa[j]) {
			if(A==1) {
				ans+=N-j; break;
			}
			tmp = findAns(A, boa[j]);
			ans+=tmp;
		}
		A+=boa[j];
	}
	return ans;
}
int main() {
	FILE *fp, *fp2;
	int num;
	int A;

	int ans;
	int now;
	int tmp;

	fopen_s(&fp, "A-small-attempt2.in", "r");
	fopen_s(&fp2, "A-small-attempt2.out", "w");
	fscanf_s(fp, "%d", &num);

	for(int i=0; i<num; ++i) {
		fprintf(fp2,"Case #%d: ",i+1);
		fscanf_s(fp,"%d %d", &A, &N);

		for(int j=0; j<N; ++j)
			fscanf_s(fp, "%d", &boa[j]);
		sort(boa, boa+N);

		ans = 0;
		now = A;
//		int tmp2;
		if(A<=1) {fprintf(fp2, "%d\n", N);continue;}
		for(int j=0; j<N; ++j) {
			Ans[j]=0;
			if(A<=boa[j]) {
				Ans[j]=findAns(A, boa[j]);
			}
/*			tmp = calc(A,j);
			if(tmp<N-j) ans+=tmp;
			if(A<=boa[j]) {
				if(A==1) {
					ans+=N-j; break;
				}
				tmp = findAns(A, boa[j]);
				if(tmp<N-j) ans+=tmp;
				else {ans+=(N-j);break;}
			}*/
			A+=boa[j];
		}

		int fin=N;
		int sum=0;
		for(int j=0; j<N;++j) {
			sum += Ans[j];
			if(sum+N-j-1 < fin) {
				fin = sum+N-j-1;
			}
		}
		fprintf(fp2, "%d\n", fin);
	}

	fclose(fp);
	fclose(fp2);
	return 0;
}
