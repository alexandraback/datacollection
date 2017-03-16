//#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int zrat(long long x, long long y) {
	int p = 0;
	while(x%y == 0) {
		x/=y;
		++p;
	}
	return p;
}

int main(){
	int T,R,N,M,K;
	scanf("%d %d %d %d %d", &T, &R, &N, &M, &K);
	printf("Case #1:\n");
	for (int r = 0; r<R; ++r) {
		vector<long long> v;
		for (int i = 0; i<K; ++i) {
			long long a;
			scanf("%lld", &a);
			v.push_back(a);
		}
		vector<int> poc (9,0);
		for (int i = 0; i<K; ++i) {
			long long x = v[i];
			poc[2] = max(poc[2], zrat(x,2));
			poc[3] = max(poc[3], zrat(x,3));
			poc[5] = max(poc[5], zrat(x,5));
			poc[7] = max(poc[7], zrat(x,7));
		}
		poc[6] = min(poc[2], poc[3]);
		if (poc[6] == poc[3] && poc[6] > 2) poc[6]-=2;
		poc[3]-=poc[6];
		poc[2]-=poc[6];
		for (int i = 0; i<poc[6]; ++i) printf("6");
		for (int i = 0; i<poc[3]; ++i) printf("3");
		for (int i = 0; i<poc[5]; ++i) printf("5");
		for (int i = 0; i<poc[7]; ++i) printf("7");
		int zv = N-poc[3]-poc[5]-poc[7]-poc[6];
		int y = 2;
		if (zv < poc[2] && zv >= poc[2]/3) y = 8;
		else if (zv < poc[2] && zv >= poc[2]/2) y = 4;
		for (int i = 0; i<zv; ++i) printf("%d", y);
		printf("\n");
	}
	return 0;
}
