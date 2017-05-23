#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const long long MAXN = 100000000000000LL;

bool isPalindrome(long long n)
{
    char num[100];
    sprintf(num, "%lld", n);
    int len = strlen(num);
    for (int i = 0, j = len - 1; i < len; ++i, --j)
    {
        if (num[i] != num[j])
        {
            return false;
        }
    }
    return true;
}

long long fairs[100];

void init()
{
    int fairNum = 0;
    for (long long x = 1; x <= 100000000; ++x)
    {
        if (x * x > MAXN)
        {
            break;
        }
        if (isPalindrome(x) && isPalindrome(x * x))
        {
            fairs[fairNum++] = x * x;
            //printf("%lld\n", x * x);
        }
    }
    fairs[fairNum] = MAXN + 1;
}

int getNum(long long x)
{
    for (int i = 0; ; ++i)
    {
        if (x < fairs[i])
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    //freopen("C-small-attempt0.in", "r", stdin);
    //freopen("C-small-attempt0.out", "w", stdout);
    freopen("C-large-1.in", "r", stdin);
    freopen("C-large-1.out", "w", stdout);
    init();
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        long long a, b;
        scanf("%lld%lld", &a, &b);
        printf("Case #%d: %d\n", t, getNum(b) - getNum(a - 1));
    }
    return 0;
}
