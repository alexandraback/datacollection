#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long llong;
inline int lowb(int x){return x & (-x);}

const int MAX = 40;//lg(10^12)
const int MAXM = 1005;

int s[1<<20];
int sum[1<<20], idx[1<<20];
//int path[MAX][MAXM][MAXM];
//int dp[MAX][MAXM][MAXM];
bool cmp(int i, int j){
	return sum[i] < sum[j];
}
int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("Cs0.txt", "w", stdout);
	//srand(time(0));
	int TT;
	scanf("%d", &TT);
	
	for(int cas = 1;cas <= TT; ++cas){
		int N;
		scanf("%d", &N);
		for(int i = 0; i < N; ++i){
			scanf("%d", s+ (1<<i));
		}
		sum[0] = 0;
		for(int i = 1, end = 1<<N; i < end; ++i){
			sum[i] = sum[i - lowb(i)] + s[lowb(i)];
			idx[i] = i;
		}
		sort(idx, idx + (1<<N), cmp);
		int u = -1, v = -1;
		for(int i = 1, end = 1<<N; i < end; ++i){
			if(sum[idx[i]] == sum[idx[i - 1]]){
				u = idx[i];
				v = idx[i - 1];
			}
		}
		printf("Case #%d:\n", cas);
		if(u == -1) puts("Impossible");
		else{
			int w = u & v;
			u ^= w;
			v ^= w;
			while(u > 0){
				int cur = lowb(u);
				printf("%d%c", s[cur], cur == u? '\n' : ' ');
				u -= cur;
			}
			while(v > 0){
				int cur = lowb(v);
				printf("%d%c", s[cur], cur == v? '\n' : ' ');
				v -= cur;
			}
		}
	}
	
	return 0;
}
