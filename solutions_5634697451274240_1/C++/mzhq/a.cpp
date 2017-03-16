#include <bits/stdc++.h>
#define ll long long
#define mst(a,x) memset(a,x,sizeof(a))
#define For(i, t) for(int i = 0; i < t; i++)
#define Debug(x) cerr << #x << " = "  << x << endl;
using namespace std;

const int N = 1005;
char s[N];

int main() {
	int T, n, ans;

	freopen("outb.txt", "w", stdout);
	scanf("%d", &T);
	For(cas, T) {
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		ans = 0;
		char ch = '+';
		for(int i = n; i >= 1; i--) {
			if(ch != s[i]) {
				if (ch == '+')
					ch = '-';
				else 
					ch = '+';
				ans++;
			}
		}
		printf("Case #%d: %d\n", cas + 1, ans);
	}
	return 0;
}
