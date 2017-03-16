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
#define EPS 0.000000001

using namespace std;

int n, m, k, l;
char slowo[1000007], sl[10007], slowo1[10000];
int p[100007];
long double ppb[10007], res[207][207], result, result2;

void pre(char wz[], int t[])
{
    t[0] = -1;
    int poz = -1;
    for(int i=1; wz[i]; i++)
    {
        while(poz != -1 && wz[poz+1] != wz[i])   poz = t[poz];
        if(wz[poz+1] == wz[i])   poz++;
        t[i] = poz;
        //printf("t[%d] = %d\n", i, poz);
    }
}

void generuj(int nr)
{
    if(nr == n)
    {
        FOR(i, 0, n-m)
        {
            int rr = 1;
            forr(j, m)
                if(slowo[j] != sl[i+j])
                    rr = 0;
            if(rr == 1)
                result2++;
        }
        return ;
    }
    forr(i, l)
    {
        sl[nr] = slowo1[i];
        generuj(nr+1);
    }
}

int main()
{
    testy()
    {
        scanf("%d %d %d", &l, &m, &n);
        scanf("%s", slowo1);
        CLEAR(ppb);
        forr(i, l)
        {
            ppb[slowo1[i]] += 1.0/(long double)l;
        }
        //ppb['Z'+1] = 1.0;

        scanf("%s", slowo);
        pre(slowo, p);

        result = 1 + (n-m)/(m-p[m-1]-1);
        forr(i, m)
            if(ppb[slowo[i]] < EPS)
                result = 0;

        //cout << "maks: " << result << endl;

        result2 = 0.0;
        generuj(0);

        forr(i, n)
            result2 /= l;

        /*
        CLEAR(res);
        res[0][0] = 0;

        FOR(i, 1, n+1)
        {
            FOR(j, 0, m)
            {
                int dl = j;
                FOR(c, 'A', 'Z'+1)
                {
                    int poz = -1;
                    while(poz != -1 && p[poz+1] != c)   poz = t[poz];
                    if(p[poz+1] == c)   poz++;
                    //if(poz != -1 && wz[poz+1] == 0)
                    //    fun(i-poz);

                }
                if()
                res[i][m] += 1;
            }
        }
        */

        printf("Case #%d: %.10lf\n", _test, max((double)(result-result2), 0.0));
    }

    return 0;
}
