#include <cstdio>
#include <iostream>
using namespace std;

int S[100], P[100];

const int infT = 10000 * 2;

double crossTime(int i, int j) {	
	
	/*
	if (P[i] > P[j]) swap(i, j);
	if (S[i] <= S[j]) return -1;
	*/
	
	if (S[i] == S[j]) return -1;
	if (S[i] < S[j]) swap(i, j);
	if (P[i] > P[j]) return -1;
	
	return (double(P[j] - P[i] - 5) / (S[i] - S[j]));
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t=0; t<T; ++t) {
		
		int N;
		scanf("%d", &N);
		
		char ch[10];
		for (int i=0; i<N; ++i) {
			scanf("%s", ch);
			scanf("%d%d", &S[i], &P[i]);
		}
		
		double sec = infT;
		for (int i=0; i<N; ++i) for (int j=i+1; j<N; ++j) {
			double ct = crossTime(i, j);
			if (ct < 0) continue;
			
			double ai = P[i] + S[i] * ct;
			double aj = P[j] + S[j] * ct;
			if (ai > aj) swap(ai, aj);
			
			for (int k=0; k<N; ++k) if ((k!=i) && (k!=j)){
				double ak = P[k] + S[k] * ct;
				if ((ai < ak + 1e-9) && (ak < aj + 1e-9)) sec = min(sec, ct);
			}
		}
	
		printf("Case #%d: ", t+1);
		if (sec < infT - 1e-9) printf("%.5lf\n", sec);
		else printf("Possible\n");
	}
	return 0;
}