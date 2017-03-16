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

int n;
double tab1[1000007], tab2[1000007];

int graj(double t1[1000007], double t2[1000007])
{
    int poz1 = 0, poz2 = 0;

    while(poz2 < n)
    {
        while(poz2 < n && t1[poz1] >= t2[poz2])
        {
            poz2++;
        }

        if(poz2 == n)
            break;

//        cout << t1[poz1] << " bije " <<  t2[poz2] << " (" << poz1 << ", " << poz2 << ") " << endl;

        poz1++;
        poz2++;
    }

//    cout << "poz1: " << poz1 << endl;

    return poz1;
}

int main()
{
    testy()
    {
        scanf("%d", &n);
        forr(i, n)
            scanf("%lf", &tab1[i]);
        forr(i, n)
            scanf("%lf", &tab2[i]);

        sort(tab1, tab1 + n);
        sort(tab2, tab2 + n);

        int res1 = graj(tab1, tab2);
        int res2 = graj(tab2, tab1);

        printf("Case #%d: %d %d\n", _test, res2, n-res1);
    }

	return 0;
}
