#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int E, R, N, v[11], mem[10][10];

int dp(int ind, int energy) {
	if (mem[ind][energy]!=-1)
		return mem[ind][energy];
	if (ind+1 == N) {
		mem[ind][energy] = energy * v[ind];
		return mem[ind][energy];
	}
	int res = dp(ind+1, (R+energy > E ? E : R+energy)), act;
	for (int e=1 ; e<=energy ; e++) {
		act = e * v[ind] + dp(ind+1, (R+energy-e > E ? E : R+energy-e));
		res = max(res, act);
	}
	mem[ind][energy] = res;
	return res;
}

int main() {
	int T, caso, res;
	scanf("%d", &T);
	for (caso=1 ; caso<=T ; caso++) {
		scanf("%d%d%d", &E, &R, &N);
		for (int i=0 ; i<N ; i++)
			scanf("%d", &v[i]);
		memset(mem, -1, sizeof(mem));
		res = dp(0, E);
		printf("Case #%d: %d\n", caso, res);
	}
	return 0;
}
