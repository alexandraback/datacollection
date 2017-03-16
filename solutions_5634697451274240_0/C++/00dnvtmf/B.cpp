//writed by dnvtmf
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
#define VI vector<int>
const double EPS = 1e-7, PI = acos(-1.0);
using namespace std;
typedef long long LL;
typedef pair <int, int> P;
const int NUM = 100010;
char s[110];
int n, len;
int main()
{
#ifdef ACM_TEST
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas)
    {
        scanf("%s", s);
        len = strlen(s);
        n = 1;
        for(int i = 1; i < len; ++i)
		{
			if(s[i] == s[i - 1]) continue;
			else ++n;
		}
		if(s[len - 1] == '+') --n;
        printf("Case #%d: %d\n", cas, n);
    }
    return 0;
}
