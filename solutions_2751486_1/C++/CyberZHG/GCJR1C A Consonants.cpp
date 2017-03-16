#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;

int n, m;
char str[MAXN];
int sum[MAXN];

bool isConsonant(char ch)
{
    return ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u';
}

int findLeft(int x)
{
    int left = 0, right = m;
    int res = 0;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (sum[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            res = max(res, mid);
            left = mid + 1;
        }
    }
    return res;
}

int main()
{
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt0.out", "w", stdout);
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    str[0] = 'a';
    for (int t = 1; t <= T; ++t)
    {
        scanf("%s%d", str + 1, &n);
        m = strlen(str + 1) + 1;
        for (int i = 1; str[i]; ++i)
        {
            if (isConsonant(str[i]))
            {
                sum[i] = sum[i - 1] + 1;
            }
            else
            {
                sum[i] = 0;
            }
        }
        long long ans = 0;
        int left = 0;
        for (int i = 1; str[i]; ++i)
        {
            if (sum[i] >= n)
            {
                ans += i - n + 1;
                left = max(left, i - n + 1);
            }
            else
            {
                ans += left;
            }
        }
        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}
