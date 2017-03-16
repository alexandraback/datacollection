#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int T;
long long n, m;
int s[60][60];

int main() {
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	for(int cas = 1; cas <= T; cas++) {
		printf("Case #%d: ",cas);
		cin >> n >> m;
		memset(s, 0, sizeof(s));
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n-1; j++)
				s[i][j] = 1;
		long long t = 1;
        for(int i = 2; i < n; i++) t <<= 1;
        if(t < m) {
			puts("IMPOSSIBLE");
			continue;
        } else {
        	//cout << t << endl;
			if(t == m) {
				for(int i = 0; i < n-1; i++) s[i][n-1] = 1;
			} else {
				for(int i = 2; i < n; i++) {
					t >>= 1;
					if(m >= t) {
						s[n-i][n-1] = 1;
						m -= t;
					}
				}
			}
			puts("POSSIBLE");
			for(int i = 0; i < n; i++,puts(""))
				for(int j = 0; j < n; j++) printf("%c",s[i][j]?'1':'0');
		}
	}
	return 0;
}
