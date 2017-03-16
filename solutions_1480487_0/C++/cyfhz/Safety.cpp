#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <algorithm>

#include <set>
using namespace  std;
double S[1000];
double R[1000];
void safety ()
{
	//FILE * fp_open, * fp_out;
	 	freopen(".\\A-small-attempt0.in","r", stdin);
	 	freopen(".\\A-samll-attempt0.out", "w", stdout);
// 	freopen(".\\C-large-practice.in","r", stdin);
// 	freopen(".\\C-large-practice.out", "w", stdout);
	//FILE * fp = fopen("debug.txt", "w");
	int T, n, i, j, k, sum, cas = 0;
	double v, left_vote;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		sum = 0;
		for(i  = 0; i < n; i ++){
			scanf("%lf", &S[i]);
			sum += S[i];
		}
		
		for(i = 0; i < n; i ++) {
			double left = 0, right = 100, mid;
			while(right - left >= 1e-6) {
				mid = (left + right) / 2;
				v = S[i] + mid * sum/100;
				left_vote = 100 - mid;
				for(j = 0; j < n; j ++) {
					if(i == j) continue;
					if(S[j] > v) continue;
					else left_vote -= (v - S[j]) * 100 / sum;
				}
				if(left_vote < 0)
				{
					right = mid;
				}else {
					left = mid + 1e-6;
				}
			}
			R[i] = (left + right)/2;
		}
		printf("Case #%d:", ++cas);
		for(i = 0; i < n; i ++)
			printf(" %.6lf", R[i]);
		printf("\n");
	}
	
}

int main() {

	safety();
	return 0;
}
