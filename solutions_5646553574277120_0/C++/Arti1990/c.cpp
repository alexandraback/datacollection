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

int c, n, v;
long long maks, res, a;

int main()
{
    testy()
    {
        scanf("%d %d %d", &c, &n, &v);
        maks = 0;
        res = 0;

        FOR(i, 1, n)
        {
            scanf("%I64d", &a);

            while(a > maks+1)
            {
//                cout << "doklada "  << maks+1 << endl;
                maks = maks + (maks+1)*c;
                res++;
            }

            maks = maks + a*c;
        }

        while(v > maks)
        {
            maks = maks + (maks+1)*c;
            res++;
        }

        printf("Case #%d: %d\n", _test, res);
    }

    return 0;
}
