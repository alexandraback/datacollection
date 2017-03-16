#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
	int t;
	cin>>t;
	int p[2000];
	const int N = 1e3+2;
	int d;
	for(int K=1; K<=t; ++K) {
		cin>>d;
		memset(p,0,sizeof(p));
		for(int i =0; i <d; ++i) {
			int a;
			cin>>a;
			p[a]++;
		}
		int res = 1e9+7;
		int m = 0;
		for (int i = 1000; i > 0; --i) {
			m = 0;
			for (int j = i+1; j < N; ++j) {
				if (p[j] > 0) {
					int k = (j+i-1)/i - 1;
					m += p[j] * k;
				}
			}
			res = min(res, i + m);
		}
		printf("Case #%d: %d\n", K, res);
	}
	return 0;
}

