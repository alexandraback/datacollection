// Artur Kraska, II UWr

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <list>
#include <set>
#include <map>

#define forr(i, n)                  for(int i=0; i<n; i++)
#define FOREACH(iter, coll)         for(typeof(coll.begin()) iter = coll.begin(); iter != coll.end(); ++iter)
#define FOREACHR(iter, coll)        for(typeof(coll.rbegin()) iter = coll.rbegin(); iter != coll.rend(); ++iter)
#define lbound(P,R,PRED)            ({typeof(P) X=P,RRR=(R), PPP = P; while(PPP<RRR) {X = (PPP+(RRR-PPP)/2); if(PRED) RRR = X; else PPP = X+1;} PPP;})
#define testy()                     int _tests; scanf("%d", &_tests); FOR(_test, 1, _tests)
#define CLEAR(tab)                  memset(tab, 0, sizeof(tab))
#define CONTAIN(el, coll)           (coll.find(el) != coll.end())
#define FOR(i, a, b)                for(int i=a; i<=b; i++)
#define FORD(i, a, b)               for(int i=a; i>=b; i--)
#define MP                          make_pair
#define PB                          push_back
#define deb(X)                      X;

#define M 1000000007
#define INF 1000000007

using namespace std;

long long przelicz(long long l, long long s)
{
    long long res = 0;
    while(l > 0)
    {
        res *= s;
        res += (l&1);
        l <<= 1;

        if(res < 0)
            return -1;
    }
    return res;
}

long long ile, tab[10000007];

void primes()
{
    tab[0] = 2;
    ile = 1;
    for(int i=3; i < 10000077; i+=2)
    {
        bool ok = 1;
        for(int j=0; tab[j]*tab[j] <= i; j++)
        {
            if(i % tab[j] == 0)
            {
                ok = 0;
                break;
            }
        }
        if(ok)
        {
            tab[ile++] = i;
        }
    }
}

long long pierwsza(long long liczba)
{
    forr(i, ile)
    {
        if(liczba%tab[i] == 0)
            return tab[i];
        if(tab[i]*tab[i] == 0)
            return 0;
    }
    return 0;
}

int n, il;

long long przelicz(int l, int s)
{
    long long res = 0, ss = 1;
    while(l > 0)
    {
        if(l&1)
        {
            res += ss;
        }
        ss *= s;
        l >>= 1;
    }
    return res;
}

int t[1000007];

void wyswietl(int nr)
{
    int nr2 = nr;
    int dl = 0;

    while(nr > 0)
    {
        t[dl++] = nr&1;
        nr >>= 1;
    }

    FORD(i, dl-1, 0)
        printf("%d", t[i]);
    forr(i, 16-dl)
        printf("0");
    FORD(i, dl-1, 0)
        printf("%d", t[i]);
}

int main()
{
    //primes();

    scanf("%d %d %d", &n, &n, &il);
    printf("Case #1:\n");

    for(int i=32769; il > 0; i+=2, il--)
    {
        wyswietl(i);
        FOR(j, 2, 10)
            printf(" %lld", przelicz(i, j));
        printf("\n");
    }

    /*
    {
        bool ok = true;
        for(int j=2; j <= 10; j++)
        {
            if(prime(przelicz(i, j)))
            {
                ok = false;
                break;
            }
        }

    }*/

    return 0;
}
