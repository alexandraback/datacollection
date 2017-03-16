#include<stdlib.h>
#include<stdio.h>
#include<algorithm>

#include<vector>
using namespace std;

int main(){
	int T, R;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t){
		scanf("%d", &R);
		vector<double> N(R), K(R);
		for (int i = 0; i < R; ++i) scanf("%lf", &(N[i]));
		for (int i = 0; i < R; ++i) scanf("%lf", &(K[i]));
		sort(N.begin(), N.end());
		sort(K.begin(), K.end());

		int kscore(0), nscore(0);
		{
			int n(0), k(0);
			while (k < R){
				while (k < R && K[k] < N[n]){
					++k;
				}
				if (k < R) ++kscore;
				++k;
				++n;
			}
		}
		{
			int n(0), k(0);
			while (n < R){
				while (n < R && N[n] < K[k]){
					++n;
				}
				if (n < R) ++nscore;
				++k;
				++n;
			}
		}
		printf("Case #%d: %d %d\n", t, nscore, R - kscore);
	}
	return 0;
}
