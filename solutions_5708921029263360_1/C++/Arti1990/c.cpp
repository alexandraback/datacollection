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

int a, b, c, k, tab[107][107];

int main()
{
    testy()
    {
        scanf("%d %d %d %d", &a, &b, &c, &k);
        CLEAR(tab);
        forr(i, max(b, k))
        {
            forr(j, k)
                tab[i][(i+j)%b] = 1;
        }
        int res = 0;
        forr(i, c)
            forr(j, b)
                res += tab[i][j];
        res *= a;

        if(res != a*b*min(c, k))
            cout << "ZLE!!!!!!" << endl;

        printf("Case #%d: %d\n", _test, res);
        forr(l, a)
            forr(i, c)
                forr(j, b)
                    if(tab[(l+i)%c][j])
                        printf("%d %d %d\n", l+1, j+1, i+1);
    }

    return 0;
}
