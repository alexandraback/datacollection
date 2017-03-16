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

long long p, q, a, pom, nwd;

long long gcd(long long a, long long b)
{
    long long c;

    while(b != 0)
    {
        c = b;
        b = a%b;
        a = c;
    }

    return a;
}

int main()
{
    testy()
    {
        scanf("%I64d/%I64d", &p, &q);
        printf("Case #%d: ", _test);

//cout << p << " " << q << endl;
        nwd = gcd(p, q);
        //cout << nwd << endl;
        p /= nwd;
        q /= nwd;

//cout << "tu" << endl;
        a = q;
        while((a&1) == 0)
            a >>= 1;

        if(a == 1 && p > 0)
        {
            int i;
            for(i=1; (1LL<<i)*p < q; i++)
                ;
            printf("%d\n", i);
        }
        else
            printf("impossible\n");
    }

	return 0;
}
