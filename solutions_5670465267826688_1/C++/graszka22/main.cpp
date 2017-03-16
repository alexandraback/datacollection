#include <bits/stdc++.h>
#define LL long long int
#define ULL unsigned long long int
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, f, n) for(int i = (f); i <= (n); ++i)
using namespace std;

const int N = 10005;
char p[N];
int ltr[N], rtl[N];
int tb[8][8] =
{
    {0, 1, 2, 3,  4, 5, 6, 7},
    {1, 4, 3, 6,  5, 0, 7, 2},
    {2, 7, 4, 1,  6, 3, 0, 5},
    {3, 2, 5, 4,  7, 6, 1, 0},

    {4, 5, 6, 7,  0, 1, 2, 3},
    {5, 0, 7, 2,  1, 4, 3, 6},
    {6, 3, 0, 5,  2, 7, 4, 1},
    {7, 6, 1, 0,  3, 2, 5, 4}
};

int tbr[8][8] =
{
    {0, 1, 2, 3, 4, 5, 6, 7},
    {5, 0, 7, 2, 1, 4, 3, 6},
    {6, 3, 0, 5, 2, 7, 4, 1},
    {7, 6, 1, 0, 3, 2, 5, 4},

    {4, 5, 6, 7, 0, 1, 2, 3},
    {1, 4, 3, 6, 5, 0, 7, 7},
    {2, 7, 4, 1, 6, 3, 0, 5},
    {3, 2, 5, 4, 7, 6, 1, 0}
};

bool allowed2[8][8];
bool allowed3[8][8]; //middle always j
int count3[8][8][8];

int podziel(int a, int c)
{
    return tbr[a][c];
}

int pot(int a, LL n)
{
    if(n <= 0) return 0;
    if(n == 1) return a;
    int t = pot(a, n/2);
    t = tb[t][t];
    if(n%2 == 1)
        t = tb[t][a];
    return t;
}

int main()
{
    int T;
    scanf("%d", &T);
    FOR(t, 1, T)
    {
        bool ok = false;
        LL l, x, full;
        scanf("%lld%lld \n%s", &l, &x, p);
        REP(i, l)
        {
            if(p[i] == 'i') p[i] = 1;
            else if(p[i] == 'j') p[i] = 2;
            else p[i] = 3;
        }

        if(x*l < 3) goto END;

        //czyść
        REP(i, 8) REP(j, 8) allowed2[i][j] = allowed3[i][j] = 0;
        REP(i, 8) REP(j, 8) REP(k, 8) count3[i][j][k] = 0;

        //iloczyny w lewo i w prawo
        ltr[0] = 0;
        rtl[l] = 0;
        REP(i, l)
            ltr[i+1] = tb[ltr[i]][p[i]];
        for(int i = l-1; i >= 0; --i)
            rtl[i] = tb[p[i]][rtl[i+1]];

        //wszystkie przerwane w pół
        REP(i, l+1)
            allowed2[ltr[i]][rtl[i]] = true;

        //wrzucamy początek dla tych przerwanych w trzy
        FOR(i, 1, l)
        {
            ++count3[0][ltr[i]][rtl[i]];
            if(ltr[i] == 2)
                allowed3[0][rtl[i]] = true;
        }


        for(int i = 0; i < l; ++i)
        {
            int nc[8][8][8] = {0};
            //usuń to, co teraz się kończy
            --count3[ltr[i]][p[i]][rtl[i+1]];
            //dla każdej możliwości która daje z przodu ltr[i], z tyłu kk i istnieje
             REP(jj, 8) REP(kk, 8)
                if(count3[ltr[i]][jj][kk] > 0)
                    //teraz staje się nową - przedłużony 1., skrócony 2., 3 (kk) bez zmian
                    nc[ltr[i+1]][podziel(p[i], jj)][kk] += count3[ltr[i]][jj][kk];
            //kopiujemy nc do count3 i aktualizujemy dozwolone
            REP(ii, 8) REP(jj, 8) REP(kk, 8)
            {
                count3[ii][jj][kk] = nc[ii][jj][kk];
                if(jj == 2 && count3[ii][jj][kk] > 0)
                    allowed3[ii][kk] = true;
            }
        }


        full = ltr[l];

        //wariant z trójką w jednej grupie
        //i, k - możliwości w allowed3
        REP(i, 8) REP(k, 8)
        {
            if(!allowed3[i][k]) continue;
            int left = 0, right = pot(full, x-1);
            //ii to ile grup zostawiamy z przodu
            //po 10 na peeeewno nam się zapętli
            REP(ii, 10)
            {
                if(ii+1 > x) break;
                if(tb[left][i] == 1 && tb[k][right] == 3)
                {
                    ok = true;
                    goto END;
                }
                left = tb[left][full];
                right = podziel(full, right);
            }
        }

        //wariant z dwoma dwójkami
        //i1, k1 - możliwości pierwszej dwójki
        //i2, k2 - jw
        REP(i1, 8) REP(k1, 8)
        REP(i2, 8) REP(k2, 8)
        {
            if(!allowed2[i1][k1]) break; //mogłabym dać to wcześniej, ale kolejka klamerka… nie chcemy tego xd
            if(!allowed2[i2][k2]) continue;
            //zmienna leftcount jest nie potrzebna
            //ale nie tykam
            //bo działa xd
            int left = 0, leftCount = 0;
            REP(ii, 10)
            {
                int middle = 0;
                int right = pot(full, x-leftCount-2);
                REP(jj, 10) //jj to tak naprawdę liczba grup w środku
                {
                    if(leftCount+1+jj+1 > x) break;
                    //NARESZCIE!
                    if(tb[left][i1] == 1 && tb[tb[k1][middle]][i2] == 2 && tb[k2][right] == 3)
                    {
                        ok = true;
                        goto END;
                    }
                    middle = tb[middle][full];
                    right = podziel(full, right);
                }
                ++leftCount;
                left = tb[left][full];
            }

        }


        END:
        if(ok)
            printf("Case #%d: YES\n", t);
        else
            printf("Case #%d: NO\n", t);
    }
    return 0;
}

