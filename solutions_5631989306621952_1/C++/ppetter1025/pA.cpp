#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#ifdef _DEBUG_
	#define debug(...) printf(__VA_ARGS__)
#else
	#define debug(...) (void)0
#endif
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int MAXN = 1000 + 10;

char s[MAXN], s2[MAXN*5];

int main() {
	int T;
	scanf("%d", &T);
	for(int kase=1; kase<=T; kase++) {
		scanf("%s", s);
		int n = strlen(s);
		int l=0, r=0;
		char *ans = s2+MAXN*3;
		ans[r++] = s[0];
		for(int i=1; i<n; i++) {
			bool flag = false;
			for(int j=l; j<=r; j++) {
				if(s[i] > ans[j]) {
					ans[--l] = s[i];
					flag = true;
					break;
				}
				if(s[i] < ans[j]) {
					ans[r++] = s[i];
					flag = true;
					break;
				}
			}
			if(!flag)	ans[r++] = s[i];
		}

		printf("Case #%d: ", kase);
		for(int i=l; i<r; i++)	putchar(ans[i]);
		putchar('\n');
	}
    
    return 0;
}
