#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Max = 205;
int s[Max];
int main(){
	freopen("A-large.in", "r", stdin);
	freopen("Al.txt", "w", stdout);
	int TT;
	scanf("%d", &TT);
	for(int cas = 1;cas <= TT; ++cas){
		int N;
		scanf("%d", &N);
		int sum = 0;
		for(int i = 0;i < N; ++i){
			scanf("%d", s + i);
			sum += s[i];
		}
		double low = 0.;
		double hi = sum * 2;
		for(int test = 0; test < 50; ++test){
			double mid = (low + hi) / 2.;
			double tmp = 0.;
			for(int i = 0;i < N; ++i){
				tmp += max(mid - s[i], 0.);
			}
			if(tmp > sum) hi = mid;
			else low = mid;
		}
		double t = (low + hi) / 2.;
		printf("Case #%d:", cas);
		for(int i = 0;i < N; ++i){
			printf(" %.6f", max(t - s[i], 0.) * 100. / sum);
		}
		puts("");
	}
	return 0;
}
