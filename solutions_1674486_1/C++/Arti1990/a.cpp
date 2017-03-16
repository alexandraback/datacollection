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

int a, n, k, tab[1000007];
int wynik;
bool byl[1000005];

list <int> lista[100005];

bool dzialaj(int nr)
{
    if(byl[nr])   return 1;
    byl[nr] = 1;
    foreach(it, lista[nr])
    {
        if(dzialaj(*it))
            return 1;
    }
    return 0;
}

int main()
{
	int tests;
	scanf("%d", &tests);
	for(int test = 1; test <= tests; test++)
	{
		scanf("%d", &n);

        for(int i=0; i<n; i++)
        {
            scanf("%d", &k);
            lista[i].clear();
            for(int j=0; j<k; j++)
            {
                scanf("%d", &a);
                lista[i].push_back(a-1);
            }
        }

        bool b = 0;
        for(int i=0; i<n; i++)
        {
            memset(byl, 0, sizeof(byl));
            b = dzialaj(i);
            if(b)   break;
        }

		printf("Case #%d: %s\n", test, b ? "Yes" : "No");
	}


	return 0;
}
