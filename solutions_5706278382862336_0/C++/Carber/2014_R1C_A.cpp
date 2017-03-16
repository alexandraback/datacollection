#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}

bool check(long long Q)
{
    while (Q % 2 == 0) Q /= 2;
    return Q == 1;
}

void Solved(int nT)
{
    long long P, Q;
    scanf("%lld/%lld", &P, &Q);
    long long T = gcd(P, Q);
    P /= T, Q /= T;
    printf("Case #%d: ", nT);
    if (!check(Q))
    {
        puts("impossible");
        return;
    }
    int result = 0;
    do 
    {
        ++result;
        Q >>= 1;
    } while (P < Q);
    cout << result << endl;
}

int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small-attempt1.out", "w", stdout);

    int T = 1;
    cin >> T;
    for (int nT = 1; nT <= T; ++nT)
    {
        Solved(nT);
    }

    return 0;
}