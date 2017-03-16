#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int64;

const int N = 10500;

int tstCnt;
int64 a[N], b[N], ans[N];
int buf[20];

bool isPalindrome(int64 x)
{
    int ptr = 0;
    while (x > 0)
    {
        buf[ptr++] = x % 10;
        x /= 10;
    }

    for (int i = 0; i < ptr / 2; i++)
        if (buf[i] != buf[ptr - 1 - i])
            return false;

    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &tstCnt);
    for (int i = 0; i < tstCnt; i++)
        scanf("%lld%lld", &a[i], &b[i]);

    for (int64 i = 1; i <= 10000000; i++)
        if (isPalindrome(i) && isPalindrome(i * i))
        {
            int64 val = i * i;
            for (int j = 0; j < tstCnt; j++)
                if (val >= a[j] && val <= b[j])
                    ans[j]++;
        }

    for (int i = 0; i < tstCnt; i++)
        printf("Case #%d: %lld\n", i + 1, ans[i]);

    return 0;
}
