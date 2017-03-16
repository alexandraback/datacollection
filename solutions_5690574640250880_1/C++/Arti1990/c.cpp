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

#define M 1000000007
#define INF 1000000007

using namespace std;

int r, c, m;
int rot, tab[55][55];

bool dzialaj()
{
    int ile = r*c-m;

    if(m >= r*c)
        return 0;

    if(ile == 1)
    {
        forr(i, r)
            forr(j, c)
                tab[i][j] = 1;
        return 1;
    }

    if(r == 1)
    {
        FORD(i, c-1, c-m)
            tab[0][i] = 1;
        return 1;
    }
    if(r == 2)
    {
        FORD(i, c-1, c-m/2)
            tab[0][i] = tab[1][i] = 2;
        return 1- ((m&1) || 2*c-m == 2);
    }

    if(ile == 2 || ile == 3 || ile == 5 || ile == 7)
    {
        return 0;
    }

    if(ile >= r*2)
    {
        int ile_c = m/r, ile_w_c = m%r;
        FORD(i, c-1, c-ile_c)
            forr(j, r)
                tab[j][i] = 3;

        forr(j, ile_w_c)
            tab[r-1-j][c-ile_c-1] = 4;

        if(ile_w_c == r-1)
        {
            tab[1][c-ile_c-1] = 0;
            tab[r-1][c-ile_c-2] = 5;

            if(ile_c == c-3)
            {
                tab[2][c-ile_c-1] = 0;
                tab[r-1][c-ile_c-3] = 6;
            }
        }
        return 1;
    }

    if((ile&1) == 0)
    {
        FORD(i, c-1, 2)
            forr(j, r)
                tab[j][i] = 7;

        FOR(j, ile/2, r)
            tab[j][0] = tab[j][1] = 8;

        return 1;
    }
    else
    {
        FORD(i, c-1, 2)
            forr(j, r)
                tab[j][i] = 9;

        ile -= 3;
        tab[0][2] = tab[1][2] = tab[2][2] = 0;

        FOR(j, ile/2, r)
            tab[j][0] = tab[j][1] = 9;

        return 1;
    }


    return 1;
}

int main()
{
    testy()
    {
        scanf("%d %d %d", &r, &c, &m);
        printf("Case #%d:\n", _test);

        CLEAR(tab);

        if(r > c)
        {
            swap(r, c);
            rot = 1;
        }
        else
            rot = 0;

        if(dzialaj())
        {
            if(rot)
            {
                forr(i, c)
                {
                    forr(j, r)
                        if(i + j == 0)
                            printf("c");
                        else
                            printf("%c", tab[j][i] ? '*' : '.');
                    printf("\n");
                }
            }
            else
            {
                forr(i, r)
                {
                    forr(j, c)
                        if(i + j == 0)
                            printf("c");
                        else
                            printf("%c", tab[i][j] ? '*' : '.');
                    printf("\n");
                }
            }
        }
        else
            printf("Impossible\n");

    }

	return 0;
}
