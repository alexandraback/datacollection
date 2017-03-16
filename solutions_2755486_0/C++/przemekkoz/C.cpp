//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define FI first
#define SE second
#define MP make_pair
using namespace std;
typedef long long LL;
const int D = 700000, W = 405;

int t;
int n;
vector<pair<pair<int,int>, int> > V[D+7];
int tab_[2*W+14];
int *tab = tab_+W+7;

int main()
{
    scanf("%d", &t);

    for(int ti = 1;ti <= t;ti++)
    {
        scanf("%d", &n);

        for(int i = 0;i <= D;i++) V[i].clear();
        for(int i = -W;i <= W;i++) tab[i] = 0;

        for(int i = 1;i <= n;i++)
        {
            int pierwszy_dzien, liczba_atakow, poczatek_ataku, koniec_ataku, sila_pierwszego, zmiana_dnia,
                zmiana_pozycji, zmiana_sily;
            scanf("%d%d%d%d%d%d%d%d", &pierwszy_dzien, &liczba_atakow, &poczatek_ataku, &koniec_ataku,
                  &sila_pierwszego, &zmiana_dnia, &zmiana_pozycji, &zmiana_sily);
            poczatek_ataku *= 2;
            koniec_ataku *= 2;
            zmiana_pozycji *= 2;

            for(int j = 1, a = poczatek_ataku, b = koniec_ataku, d = pierwszy_dzien, s = sila_pierwszego;
                    j <= liczba_atakow;j++)
            {
                V[d].push_back(MP(MP(a,b),s));

                a += zmiana_pozycji;
                b += zmiana_pozycji;
                d += zmiana_dnia;
                s += zmiana_sily;
            }
        }

        int wyn = 0;

        for(int d = 0;d <= D;d++)
        {
            for(int i = 0;i < V[d].size();i++)
            {
                bool udany = 0;

                for(int j = V[d][i].FI.FI;j <= V[d][i].FI.SE;j++)
                    if(tab[j] < V[d][i].SE)
                    {
                        udany = 1;
                        break;
                    }
                //cerr << "Dzien: " << d << " Atak: " << V[d][i].FI.FI << " " << V[d][i].FI.SE << " Sila: " << V[d][i].SE << endl;
                wyn += udany;
            }

            for(int i = 0;i < V[d].size();i++)
                for(int j = V[d][i].FI.FI;j <= V[d][i].FI.SE;j++)
                    tab[j] = max(tab[j], V[d][i].SE);
        }


        printf("Case #%d: %d\n", ti, wyn);
    }

    return 0;
}
