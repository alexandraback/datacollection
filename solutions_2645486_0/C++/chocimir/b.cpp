#include<algorithm>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<vector>
using namespace std;

typedef unsigned long long LL;
typedef long double LD;

#define dprintf(...) fprintf(stderr, __VA_ARGS__)

int cond = 1;
#define DB(X) {if(cond){cerr<<"Line:"<<__LINE__<<", "<<#X<<" = "<<X<<endl;}}
const int nMax = 10e2+3;
const int eMax = 10e2+3;
int v[eMax];
LL d[nMax][eMax];
int main() {
	int t; cin >> t;
	for(int x = 1; x <= t; ++x){
		int e, r, n; cin >> e >> r >> n;
		for(int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		if (e <= r) {
			int res = 0;
			for(int i = 0; i < n; i++) {
				res += v[i] * e;
			}
			cout << "Case #" << x << ": " << res << endl;//result 
			continue;
		}
		for(int i = r; i <= e; i++) {
			d[0][i] = v[0]*(e - i + r);
		}
		for(int i = 1; i < n; ++i) {
			for(int j = r; j < e; ++j) {
				int aktmax = 0;
				for(int k = r; (k <= e); ++k) {
					if (k - j + r < 0) {
						continue;
					}

					int tmp = (d[i-1][k] + v[i]*(k - (j - r)));
					if (tmp	> aktmax) {
						aktmax = tmp;
					}
				}
				d[i][j] = aktmax;
			}
			int aktmax = 0;
			for(int k = e - r; k <= e; ++k) {
				int tmp = d[i-1][k] + v[i] * (k - e + r);
				if (tmp > aktmax) {
					aktmax = tmp;
				}
			}
			d[i][e] = aktmax;
		}
		/*
		for(int i = 0; i < n; ++i){
			for(int j = 0; j <= e; ++j) {
				cout <<d[i][j] << " "<< endl;
			}
			cout << endl;
		}
		*/
		int res = 0;
		for(int i = r; i <= e; ++i) {
			if (d[n-1][i] > res) {
				res = d[n-1][i];
			}
		}
		cout << "Case #" << x << ": " << res << endl;//result 
	}
	return 0;
}
