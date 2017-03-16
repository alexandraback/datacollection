#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define N 1000200
#define M 200020
#define LL long long
#define inf 0x3f3f3f3f


char s[N], a[N];
int n;
LL x;
int num[N], b[N], c[N];
int mat[5][5] = {
	0, 0, 0, 0, 0,
	0, 1, 2, 3, 4,
	0, 2, -1, 4, -3,
	0, 3, -4, -1, 2,
	0, 4, 3, -2, -1
};
int f(char c) {
	if(c == '1') return 1;
	if(c == 'i') return 2;
	if(c == 'j') return 3;
	if(c == 'k') return 4;
	return -1;
}
int mul(int x, int y) {
	int c = mat[abs(x)][abs(y)];
	if(x < 0) c = -c;
	if(y < 0) c = -c;
	return c;
}
int main() {
	//freopen("tt.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int cas, kk = 0;
	cin >> cas;
	while(cas--) {
		cin >> n >> x;
		cin >> s + 1;
		if(x > 40) {
			x = x - (x - 25) / 4 * 4;
		}
		int t = x;
		for(int i = 0; i < t; ++i)
			for(int j = 1; j <= n; ++j)
				a[i*n+j] = s[j];
		memcpy(s, a, sizeof a);
		n *= t;
		for(int i = 1; i <= n; ++i)
			num[i] = f(s[i]);
		bool flag = 0;
		int val = 1;
		for(int i = 1; i <= n; ++i) {
			val = mul(val, num[i]);
			if(val == 2) {
				for(int j = i + 1; j <= n; ++j) {
					val = mul(val, num[j]);
					if(val == 4) {
						for(int k = j + 1; k <= n; ++k) {
							val = mul(val, num[k]);
						}
						if(val == -1) flag = 1;
						break;
					}
				}
				break;
			}
		}
		
		printf("Case #%d: %s\n", ++kk, flag? "YES": "NO");
	}
	return 0;
}


