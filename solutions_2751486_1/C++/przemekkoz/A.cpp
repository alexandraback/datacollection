//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1000006;
char TYP[256];


int t;
int n, k;
char tab[N];
int DP[N];

int main()
{
    scanf("%d", &t);

    TYP['a'] = 1;
    TYP['e'] = 1;
    TYP['i'] = 1;
    TYP['o'] = 1;
    TYP['u'] = 1;

    for(int ti = 1;ti <= t;ti++)
    {
        scanf(" ");scanf("%s%n", tab+1, &n);
        scanf("%d", &k);

        LL wyn = 0;

        for(int i = 1, spol = 0;i <= n;i++)
        {
            if(!TYP[tab[i]]) spol++;
            else spol = 0;

            if(spol >= k) DP[i] = i-k+1;
            else DP[i] = DP[i-1];

            //cerr << "I: " << i << " Spol: " << spol << " DP[i]: " << DP[i] << endl;

            wyn += DP[i];
        }

        printf("Case #%d: %lld\n", ti, wyn);
    }

    return 0;
}