#include <bits/stdc++.h>

using namespace std;

const int nmax = 19;
const int mmax = 10009;

int tmp[nmax][3];
int used[nmax][nmax][nmax];
int precBst[nmax][nmax][nmax][nmax];
int precConf[nmax][nmax][nmax][nmax];
int mask , conf , bst , i , n , m , J , P , S , j , p , s , er , K , tests , T;

void bkt(int stp , int nr)
{
    if (stp == er)
    {
        if (nr > bst) bst = nr , conf = mask;
        return;
    }

    int j = tmp[stp][0];
    int p = tmp[stp][1];
    int s = tmp[stp][2];

    bkt(stp + 1 , nr);
    if (used[0][p][s] == K || used[j][0][s] == K || used[j][p][0] == K) return;

    used[0][p][s]++;
    used[j][0][s]++;
    used[j][p][0]++;
    mask += (1 << stp);

    bkt(stp + 1 , nr + 1);

    used[0][p][s]--;
    used[j][0][s]--;
    used[j][p][0]--;
    mask -= (1 << stp);
}

int main()
{
freopen("test.in" , "r" , stdin);
freopen("test.out" , "w" , stdout);

cin >> tests;

for (T = 1 ; T <= tests ; ++T)
{
    cin >> J >> P >> S >> K;
    if (K >= S) K = S;

    er = 0;
    for (j = 1 ; j <= J ; ++j)
    for (p = 1 ; p <= P ; ++p)
    for (s = 1 ; s <= S ; ++s)
    {
        tmp[er][0] = j;
        tmp[er][1] = p;
        tmp[er][2] = s;

        er++;
    }

    if (precBst[J][P][S][K])
    {
        bst = precBst[J][P][S][K];
        conf = precConf[J][P][S][K];
    }
    else
    {
        bst = 0;
        bkt(0 , 0);

        precBst[J][P][S][K] = bst;
        precConf[J][P][S][K] = conf;
    }

    cout << "Case #" << T << ": " << bst << '\n';

    for (i = 0 ; i < er ; ++i)
    if ((1 << i) & conf)
    cout << tmp[i][0] << " " << tmp[i][1] << " " << tmp[i][2] << '\n';
}


return 0;
}
