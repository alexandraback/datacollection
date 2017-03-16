//#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

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
		vector<int> poc (6,0);
		for (int i = 0; i<K; ++i) {
			long long x = v[i];
			int p = 0;
			while(x%2 == 0) {
				x/=2;
				++p;
			} 
			poc[2] = max(poc[2], p);
			p = 0;
			while(x%3 == 0) {
				x/=3;
				++p;
			} 
			poc[3] = max(poc[3], p);
			p = 0;
			while(x%5 == 0) {
				x/=5;
				++p;
			} 
			poc[5] = max(poc[5], p);
		}
		for (int i = 0; i<poc[3]; ++i) printf("3");
		for (int i = 0; i<poc[5]; ++i) printf("5");
		int zv = N-poc[3]-poc[5];
		int y = 2;
		if (zv < poc[2] && zv >= poc[2]/2) y = 4;
		for (int i = 0; i<zv; ++i) printf("%d", y);
		printf("\n");
	}
	return 0;
}
