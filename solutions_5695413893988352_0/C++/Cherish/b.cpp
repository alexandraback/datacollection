#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 1
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < n; ++i)
#define Rep(i,n) for(int i = 1; i <= n; ++i)

char r[10], s[10];

int main()
{
	int t, cas = 0;
	cin >> t;
	while(cas++ < t) {
		cin >> r >> s;
		int len = strlen(r);
		rep(i, len) r[3-i-1] = r[len-i-1], s[3-i-1] = s[len-i-1];
		for(int i = 3-len-1; i >= 0; --i) r[i] = s[i] = '0';
		rep(i, 3) r[i] -= '0', s[i] -= '0';
		int ma = INF, aa, bb;
		rep(a, 1000) {
			if(r[0] != '?'-'0' && r[0] != a/100) continue;
			if(r[1] != '?'-'0' && r[1] != a%100/10) continue;
			if(r[2] != '?'-'0' && r[2] != a%10) continue;
			rep(b, 1000) {
				if(s[0] != '?'-'0' && s[0] != b/100) continue;
				if(s[1] != '?'-'0' && s[1] != b%100/10) continue;
				if(s[2] != '?'-'0' && s[2] != b%10) continue;
				if(abs(a-b) < ma) {
					aa = a, bb = b;
					ma = abs(a-b);
				}
				else if(abs(a-b) == ma) {
					if(a < aa) {
						aa = a, bb = b;
					}
					else if(a == aa) {
						if(b < bb) bb = b;
					}
				}
			}
		}
		int temp = 1;
		rep(i, len) {
			r[3-i-1] = aa % 10 + '0'; aa /= 10;
			s[3-i-1] = bb % 10 + '0'; bb /= 10;
		}
		printf("Case #%d: %s %s\n", cas, r+3-len, s+3-len);
	}
	return 0;
}

