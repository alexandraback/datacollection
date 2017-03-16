#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 50;

int N, cases;
int A[MAXN], B[MAXN];
int head, cnt;
bool st;
int ans;

void gao(int v, int sta, bool status){
	if (sta == 0){
		// check final status
		if ((A[v] == head) || (A[head] == v) || status) {
			ans = max(ans, cnt);
			st = true;
		}
		return ;
	}
	if(!status){
		// try direct
		int bh = A[v];
		if(sta & (1 << bh)){
			gao(bh, sta - (1 << bh), A[bh] == v);
			if(st) return;
		}
		/*// try backward
		bh = B[v];
		if(sta & (1 << bh)){
			gao(bh, sta - (1 << bh), true);
		}*/
	} else {
		// pick first
		for(int i = 0; i < N; ++i)
			if(sta & (1 << i)){
				gao(i, sta - (1 << i), A[v] == i || A[i] == v);
				if(st) return;
			}
	}
	return ;
}

int main(){
	scanf("%d", &cases);
	for(int xx = 1; xx <= cases; ++xx){
		scanf("%d", &N);
		for(int i = 0; i < N; ++i){
			scanf("%d", &A[i]);
			A[i]--;
			B[A[i]] = i;
		}
		ans = -1;
		for(int i = 1; i < (1 << N); ++i){
			for(int j = 0; j < N; ++j)
				if(i & (1 << j)){
					head = j;
					cnt = __builtin_popcount(i);
					st = false;
					gao(j, i - (1 << j), false);
					break;
				}
		}
		printf("Case #%d: %d\n", xx, ans);
	}
}
