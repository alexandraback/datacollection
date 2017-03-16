#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

#define inf (1<<29)
#define eps (1e-9)

#define flt(x,y) ((x)<(y)-eps)
#define fgt(x,y) flt(y,x)
#define fle(x,y) !fgt(x,y)
#define fge(x,y) !flt(x,y)
#define feq(x,y) (fabs((x)-(y))<eps)

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

char str[1000005];
int dp[1000005];

bool isvowel(char a)
{
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return true;
	return false;
}

int main()
{
	int T,cc=0; scanf("%d", &T);
	int n;
	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%s %d\n", str, &n);
		int L = strlen(str);
		if (isvowel(str[0])) dp[0] = 0; else dp[0] = 1;
		for (int i = 1; i < L; i++)
		{
			if (isvowel(str[i])) dp[i] = 0;
			else dp[i] = dp[i-1]+1;
		}
		LL ans = 0, pos = -1;
		for (int i = 0; i < L; i++) {
			if (dp[i] >= n) {
				pos = i-n+2;
			}
			if (pos != -1) {
				ans += pos;
			}
		}
		printf("Case #%d: %lld\n", ++cc, ans);
	}
	return 0;
}
