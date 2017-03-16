#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<sstream>
#include<iostream>
#include<algorithm>

using namespace std;

enum Quaternion
{
    One = 0,
    I = 1,
    J = 2,
    K = 3,
    MinusOne = 4,
    MinusI = 5,
    MinusJ = 6,
    MinusK = 7
};

Quaternion baseProd[8][8] = 
{
    {One,       I,          J,          K,          MinusOne,   MinusI,     MinusJ,     MinusK},
    {I,         MinusOne,   K,          MinusJ,     MinusI,     One,        MinusK,     J},
    {J,         MinusK,     MinusOne,   I,          MinusJ,     K,          One,        MinusI},
    {K,         J,          MinusI,     MinusOne,   MinusK,     MinusJ,     I,          One},
    {MinusOne,  MinusI,     MinusJ,     MinusK,     One,        I,          J,          K},
    {MinusI,    One,        MinusK,     J,          I,          MinusOne,   K,          MinusJ},
    {MinusJ,    K,          One,        MinusI,     J,          MinusK,     MinusOne,   I},
    {MinusK,    MinusJ,     I,          One,        K,          J,          MinusI,     MinusOne}
};

Quaternion mult(Quaternion first, Quaternion second)
{
    return baseProd[(int)first][(int)second];
}

long long l, x;
long long total;
char buffer[11000];
Quaternion rep[11000];

bool candoit()
{
    Quaternion repTotal = One;
    for (int i = 0; i < l; i++)
    {
        repTotal = mult(repTotal, rep[i]);
    }

    Quaternion totalMult = One;
    for (int i = 0; i < (x % 4); i++)
    {
        totalMult = mult(totalMult, repTotal);
    }
    if (totalMult != MinusOne)
        return false;

    int bestIBegin = 0;
    Quaternion prefix = One;
    for (bestIBegin = 0; bestIBegin < 4 * l; bestIBegin++)
    {
        prefix = mult(prefix, rep[bestIBegin % l]);
        if (prefix == I)
        {
            break;
        }
    }
    if (bestIBegin == 4 * l)
        return false;
    bestIBegin++;

    int bestKEnd = 0;
    Quaternion suffix = One;
    for (bestKEnd = 0; bestKEnd < 4 * l; bestKEnd++)
    {
        suffix = mult(rep[l - 1 - (bestKEnd % l)], suffix);
        if (suffix == K)
        {
            break;
        }
    }
    if (bestKEnd == 4 * l)
        return false;
    bestKEnd++;

    if (bestIBegin + bestKEnd >= total)
        return false;

    return true;
}

int main()
{
    int t, test;
    scanf("%d", &test);
    for (t = 0; t < test; t++)
    {
        scanf("%lld %lld", &l, &x);
        scanf("%s", buffer);
        total = l * x;
        for (int i = 0; i < l; i++)
        {
            rep[i] = (Quaternion)((int)(buffer[i] - 'i' + 1));
        }

        if (candoit())
            printf("Case #%d: YES\n", t+1);
        else
            printf("Case #%d: NO\n", t+1);
    }
    return 0;
}
