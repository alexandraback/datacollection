#include <algorithm>
#include <numeric>
#include <cstdio>
using namespace std;
#include <iostream>
#include <map>
#include <cmath>

//By chyx111
#define REP(i,n) for(int n_##__LINE__ = (n), i = 0; i < n_##__LINE__; ++i)

int const N = 256;
int arr[N];
double ans[N];

int main() {
	int ca;
	scanf("%d", &ca);
	REP (ica, ca){
		int n;
		scanf("%d", &n);
		REP (i, n){
			scanf("%d", arr + i);
		}
		int sum = accumulate(arr, arr + n, 0);
		REP (r, n){
			double lo = 0, hi = 1;
			REP (_, 100){
				double mid = (lo + hi) / 2;
				double score = arr[r] + mid * sum;
				bool can_win = false;
				double used = 0;
				bool has = false;
				REP (i, n)if(i != r){
					if(arr[i] < score){
						used += (score - arr[i]) / sum;
						has = true;
					}
				}
				if(used > 1 - mid && has){
					can_win = true;
				}
				if(can_win){
					hi = mid;
				}else{
					lo = mid;
				}
			}
			ans[r] = lo * 100;
		}
		printf("Case #%d:", ica + 1);
		REP (i, n){
			printf(" %.10f", ans[i]);
		}
		puts("");
	}
	return 0;
}

