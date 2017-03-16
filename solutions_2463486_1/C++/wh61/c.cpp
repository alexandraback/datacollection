#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

#define LL long long

int f[12000000];

bool fair(LL num)
{
    LL temp = 0, temp0 = num;
    while (temp0 != 0)
    {
        temp = temp * 10LL + temp0 % 10LL;
        temp0 /= 10LL;
    }
    if (temp == num) return 1;
    else return 0;
}

LL upper_sqrt(LL num)
{
    double num0 = num;
    num0 = sqrt(num0);
    LL ans = (LL)num0;
    for (LL temp = ans - 1; temp <= ans + 1; temp++)
        if (temp * temp >= num) return temp;
}
LL lower_sqrt(LL num)
{
    double num0 = num;
    num0 = sqrt(num0);
    LL ans = (LL)num0;
    for (LL temp = ans + 1; temp >= ans - 1; temp--)
        if (temp * temp <= num) return temp;
}

int main()
{
    freopen("cin2.in", "r", stdin);
    freopen("cout2.txt", "w", stdout);
    f[0] = 0;
    for (int k = 1; k <= 10000005; k++)
    {
        LL num = k;
        f[k] = f[k - 1];
        if (!fair(num)) continue;
        if (fair(num * num)) f[k]++;
    }
    int T, ca = 0;
    scanf("%d", &T);
    while (T--)
    {
        LL A, B;
        cin >> A >> B;
        A = upper_sqrt(A);
        B = lower_sqrt(B);
        printf("Case #%d: %d\n", ++ca, f[B] - f[A - 1]);
    }
    return 0;
}
