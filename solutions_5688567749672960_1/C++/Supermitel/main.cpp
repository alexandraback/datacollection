#include <bits/stdc++.h>

using namespace std;

long long n;

long long rev(long long x)
{
    long long aux = 0;
    while(x)
    {
        aux = aux * 10 + x % 10;
        x /= 10;
    }

    return aux;
}

long long nrcif(long long x)
{
    long long rez = 0;
    do
    {
        rez ++;
        x/=10;
    }while (x);

    return rez;
}

long long pow10(int x)
{
    long long rez = 1;
    for(int i = 0; i < x; i++)
        rez *= 10;
    return rez;
}

long long solve(long long n)
{
    if(n < 10)
        return n;

    long long first, sec, rez;
    long long ncif = nrcif(n);

    if(n % 10 == 0)
        return solve(n-1) + 1;


    first = n % pow10(ncif - ncif / 2);
    sec = rev (n/pow10(ncif - ncif/2));
    rez = first + sec + 1 + solve(pow10(ncif-1) - 1);

    if(sec == 1)
        rez--;

    return rez;
}

int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int t;
    scanf("%d\n", &t);

    for(int i = 1; i <= t; i++)
    {
        scanf("%lld", &n);
        printf("Case #%d: ", i);
        printf("%lld\n", solve(n));

    }
    return 0;
}
