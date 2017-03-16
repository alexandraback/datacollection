#include <algorithm>
#include <map>
#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long llong;
const int MAX = 10000;
int E, R, N;
int v[MAX];
int rk[MAX];
int rem[MAX], pre[MAX];

bool cmp(int i, int j){
	return v[i] != v[j]? v[i] > v[j] : i < j;
}

int PRE(int i){
	if(i < 0 || pre[i] == i) return i;
	return pre[i] = PRE(pre[i]);
}

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int TT;
	scanf("%d", &TT);
	for(int cas = 1;cas <= TT; ++cas){
		scanf("%d %d %d", &E, &R, &N);
		if(R > E) R = E;
		for(int i = 0;i < N; ++i){
			scanf("%d", v + i);
		}
		for(int i = 0; i < N; ++i){
			rem[i] = (i == 0 ? E : R);
			pre[i] = i;
			rk[i] = i;
		}
		sort(rk, rk + N, cmp);

		llong ret = 0;
		for(int i = 0;i < N; ++i){
			int u = rk[i];
			int e = E;
			int ppos = u;
			while(e > 0){
				int pos = PRE(u);
				if(pos < 0) break;
				int fulle = (pos == 0 ? E : R);
				llong used = (ppos - pos) * R + fulle - rem[pos];
				if(used >= e) break;
				e -= used;
				int cost = min(e, rem[pos]);
				e -= cost;
				rem[pos] -= cost;
				ret += llong(cost) * v[u];
				if(rem[pos] == 0){
					pre[pos] = pos - 1;
					e += fulle;
				}
				ppos = pos;
			}
		}

		printf("Case #%d: %lld\n", cas, ret);
	}
	return 0;
}