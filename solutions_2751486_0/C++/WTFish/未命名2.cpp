#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char s[2000010], c;
int l, T, n, w, j, cnt;
long long ans;
bool ck(char c)
{
    if (c == 'a') return 1;
	if (c == 'e') return 1;
	if (c == 'i') return 1;
	if (c == 'o') return 1;
	if (c == 'u') return 1;
	return 0;
}
int main()
{
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	scanf("%d", &T);
    getchar();
    while (T--)
    {
        l = 0;
        scanf("%s%d", &s, &n);
        l = strlen(s);
        ans = 0ll, j = 0;
		cnt = !ck(s[j]);
        for (int i = 0; i < l; i++)
		{
            for ( ; j + 1 < l; j++)
			{
                if (cnt >= n) break;
                if (ck(s[j + 1]) == 0) cnt++;
				else cnt = 0;
            }
            if (cnt >= n) ans += l - j;
            if (j - i + 1 == n) cnt--;
        }
        printf("Case #%d: %I64d\n", ++w, ans);
    }
    return 0;
}
