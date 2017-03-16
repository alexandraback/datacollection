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

#define znak(z)                     ((z) <= '9' ? (z)-'0' : (z) - 'A'+10)
#define foreach(iter, coll)         for(typeof(coll.begin()) iter = coll.begin(); iter != coll.end(); ++iter)
#define foreachr(iter, coll)        for(typeof(coll.rbegin()) iter = coll.rbegin(); iter != coll.rend(); ++iter)
#define lbound(P,R,PRED)            ({typeof(P) X=P,RRR=(R), PPP = P; while(PPP<RRR) {X = (PPP+(RRR-PPP)/2); if(PRED) RRR = X; else PPP = X+1;} PPP;})

#define M 1000000007

using namespace std;

int n, m, k, tab[1000007];
long long wynik, x, y;
long long t1[10005], t2[10005], tile1[10005], tile2[10005];

map <pair<pair<long long, long long>, pair<long long, long long> >, long long> mapa;

long long lcs(long long l1, long long ile1, long long l2, long long ile2)
{
//    printf("odpala %I64d %I64d %I64d %I64d\n", l1, ile1, l2, ile2);
    if(ile1 <= 0 && l1 <= 0)
        return 0;
    if(ile2 <= 0 && l2 <= 0)
        return 0;

    if(mapa[make_pair(make_pair(l1, ile1), make_pair(l2, ile2))] > 0)
        return mapa[make_pair(make_pair(l1, ile1), make_pair(l2, ile2))] - 1;

    if(ile1 <= 0)
    {
        x = lcs(l1-1, tile1[l1-1], l2, ile2);
//        cout << "   dla " << l1-1 << " " << tile1[l1-1] << " " << l2 << " " << ile2 << " dostal " << x << endl;
        mapa[make_pair(make_pair(l1, ile1), make_pair(l2, ile2))] = x+1;
        return x;
    }
    if(ile2 <= 0)
    {
        x = lcs(l1, ile1, l2-1, tile2[l2-1]);
//        cout << "   dla " << l1 << " " << ile1 << " " << l2-1 << " " << tile2[l2-1] << " dostal " << x << endl;
        mapa[make_pair(make_pair(l1, ile1), make_pair(l2, ile2))] = x+1;
        return x;
    }

    if(t1[l1] == t2[l2])
    {
        if(ile1 > ile2)
        {
            x = lcs(l1, ile1-ile2, l2, 0);
//            cout << "   dla " << l1 << " " << ile1 - ile2 << " " << l2 << " " << 0 << " dostal " << x << endl;
            mapa[make_pair(make_pair(l1, ile1), make_pair(l2, ile2))] = x + ile2+1;
            return x + ile2;
        }
        else
        {
            x = lcs(l1, 0, l2, ile2-ile1);
//            cout << "   dla " << l1 << " " << 0 << " " << l2 << " " << ile2-ile1 << " dostal " << x << endl;
            mapa[make_pair(make_pair(l1, ile1), make_pair(l2, ile2))] = x + ile1+1;
            return x + ile1;
        }
    }
    else
    {
        long long x2 = lcs(l1, 0, l2, ile2);
//        printf("   dla %I64d %I64d %I64d %I64d dostal %I64d\n", l1, (long long)0, l2, ile2, x2);
        long long y2 = lcs(l1, ile1, l2, 0);
//        printf("   dla %I64d %I64d %I64d %I64d dostal %I64d\n", l1, ile1, l2, (long long)0, y2);
        mapa[make_pair(make_pair(l1, ile1), make_pair(l2, ile2))] = max(x2, y2)+1;
        return max(x2, y2);
    }
}

int main()
{
	int tests;
	scanf("%d", &tests);
	for(int test = 1; test <= tests; test++)
	{
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++)
		{
		    scanf("%I64d %I64d", &tile1[i], &t1[i]);
		}
		for(int i=0; i<m; i++)
		{
		    scanf("%I64d %I64d", &tile2[i], &t2[i]);
		}

        mapa.clear();
		wynik = lcs(n, 0, m, 0);

		printf("Case #%d: %I64d\n", test, wynik);
	}


	return 0;
}
