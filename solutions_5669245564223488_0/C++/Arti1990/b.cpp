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

int n, m;
char slowo[100007];

struct elem
{
    int p, k, sr, caly, ile;
};
elem tab[1007];

int main()
{
    testy()
    {
        CLEAR(tab);

        scanf("%d", &n);
        forr(i, n)
        {
            scanf("%s", slowo);

            int dl = strlen(slowo);
            int pocz = 0, kon = dl-1;

            while(pocz < dl-1 && slowo[pocz] == slowo[pocz+1])
                pocz++;
            while(kon > 0 && slowo[kon] == slowo[kon-1])
                kon--;

            if(kon == 0)
                tab[slowo[0]].caly++;
            else
            {
                tab[slowo[0]].p++;
                tab[slowo[dl-1]].k++;

                if(slowo[0] == slowo[dl-1])
                    tab[slowo[0]].sr++;

                FOR(j, pocz+1, kon-1)
                    if(slowo[j] != slowo[j+1])
                        tab[slowo[j]].sr++;
            }
        }
/*
        FOR(i, 'a', 'z')
        {
            cout << (char)i << " - pocz: " << tab[i].p << ", kon: " << tab[i].k << ", sr: " << tab[i].sr << ", caly: " << tab[i].caly << endl;
        }
*/
        long long wynik = 1;
        int ile_par = 0, ile_ust = 0, ustawione = 0, ile_caly = 0;

        FOR(i, 'a', 'z')
        {
            if(tab[i].sr > 0 && (tab[i].sr + tab[i].p + tab[i].k + tab[i].caly) > 1)
                wynik = 0;
            if(tab[i].p > 1 || tab[i].k > 1)
                wynik = 0;
            if(tab[i].p == 1 && tab[i].k == 1)
                ile_par++;
            ile_caly += tab[i].caly;

            /*if(tab[i].p + tab[i].k > 0 && tab[i].p * tab[i].k == 0)
                ile_ust++;*/
        }

        if(ile_par > 0 && ile_par + ile_caly > n-1)
            wynik = 0;

        //FOR(j, 1, ile_ust)
        //    wynik = (wynik*j)%M;

        ile_ust = 0;

        FOR(i, 'a', 'z')
        {
//            cout << (char)i << ": " << wynik << endl;
            if(tab[i].caly > 0)
            {
                if(tab[i].p == 0 && tab[i].k == 0)
                {
                    ile_ust++;
                    wynik = (wynik*ile_ust)%M;
                }

//                cout << "caly " << tab[i].caly << " razy" << endl;
                FOR(j, 1, tab[i].caly)
                    wynik = (wynik*j) % M;
            }
            //else // nie ma calych
            {
                if(tab[i].p == 0 && tab[i].k == 1)
                {
                    ile_ust++;
                    wynik = (wynik*ile_ust)%M;
                }
            }
//            cout << "  ile: " << ile_ust << endl;;
        }

        printf("Case #%d: ", _test);
        cout << wynik << endl;
    }

	return 0;
}
