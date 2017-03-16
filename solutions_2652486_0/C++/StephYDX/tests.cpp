#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long llong;

const llong INF = 0x7fffffffffffffffLL;

int v[12];
int u[12];
int count(int n, int x){
	return n % x ? 0 : (count(n / x, x) + 1);
}
int vst[200], TRUE;
void guess1(int N, int M, int K){
	//bool single2 = false;
	//int cnt2 = 0;
	//int cnt3 = 0;
	//int cnt5 = 0;
	//for(int i = 0;i < K; ++i){
	//	cnt2 = max(cnt2, count(v[i], 2));
	//	cnt3 = max(cnt3, count(v[i], 3));
	//	cnt5 = max(cnt5, count(v[i], 5));
	//	if(count(v[i], 2) % 2 == 1) single2 = true;
	//}
	//int n = 0;
	//if(single2) u[n++] = 2;
	//while(cnt3--) u[n++] = 3;
	//while(cnt5--) u[n++] = 5;
	//int rem = N - n;
	for(int i = 2;i <= 5; ++i){
		for(int j = i;j <= 5; ++j){
			for(int k = j;k <= 5; ++k){
				++TRUE;
				vst[1] = vst[i] = vst[j] = vst[k] =
				vst[i * j] = vst[j * k] = vst[k * i] =
				vst[i * j * k] = TRUE;
				bool chk = true;
				for(int t = 0; t < K; ++t){
					if(vst[v[t]] < TRUE) chk = false;
				}
				if(chk){
					u[0] = i;
					u[1] = j;
					u[2] = k;
					return;
				}
			}
		}
	}
}
int main(){
	freopen("C-small-1-attempt0.in","r",stdin);
	freopen("C-small-1-attempt0.out","w",stdout);
	int TT;
	scanf("%d", &TT);
	for(int cas = 1;cas <= TT; ++cas){
		int R, N, M, K;
		scanf("%d %d %d %d", &R, &N, &M, &K);
		printf("Case #%d:\n", cas);
		while(R--){
			for(int i = 0;i < K; ++i){
				scanf("%d", v + i);
			}
			guess1(N, M, K);
			for(int i = 0;i < N; ++i){
				putchar(u[i] + '0');
			}
			puts("");
		}
	}
	return 0;
}