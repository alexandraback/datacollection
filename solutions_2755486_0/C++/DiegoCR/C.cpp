#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue < pair<int, int> > Q;
int act;
int mem[3][2000];
int minl, maxr;

struct tribu
{
    int n, d, l, r, s;
    int ddia, ddis, ds;
}arr[20];

bool ataque(int dia, int t)
{
    int nd = (dia - arr[t].d)/arr[t].ddia;
    int pos = arr[t].l + nd*(arr[t].ddis) + 1000;
    int fuerza = arr[t].s + nd*arr[t].ds;
    bool ok = true;

    minl = min(minl, pos);
    maxr = max(maxr, pos + arr[t].r - arr[t].l);

    for ( int i = 0; i < arr[t].r - arr[t].l && ok ; i ++ )
        if ( mem[act%2][pos + i] < fuerza )
            ok = false;

    if ( ok )
        return false;

    for ( int i = 0; i < arr[t].r - arr[t].l; i ++ )
        mem[(act + 1)%2][pos + i] = max(mem[(act + 1)%2][pos + i], fuerza);

    return true;
}

void update()
{
    // cout << minl << " - " << maxr << endl;
    for ( int i = minl; i <= maxr; i ++ )
    {
        mem[act%2][i] = max(mem[(act + 1)%2][i], mem[act%2][i]);
        // cout << mem[act%2][i] << " ";
    }
    // cout << endl;
}

int main()
{
    freopen ( "c.in", "r", stdin );
    freopen ( "SmallC.out", "w", stdout );

    int ntc, tc = 0, N;

    cin >> ntc;

    while ( ntc -- )
    {
        tc ++;

        cin >> N;

        for ( int i = 0; i < N; i ++ )
        {
            cin >> arr[i].d >> arr[i].n >> arr[i].l >> arr[i].r >> arr[i].s;
            cin >> arr[i].ddia >> arr[i].ddis >> arr[i].ds;
            for ( int j = 0; j < arr[i].n; j ++ )
                Q.push( make_pair((arr[i].d + arr[i].ddia*j)*-1, i) );
        }

        int ans = 0, ant = -1;
        pair<int, int> aux;
        act = 0;
        minl = 2000;
        maxr = 0;
        bool flag = false;

        memset ( mem, 0, sizeof(mem) );

        while ( !Q.empty() )
        {
            aux = Q.top();
            Q.pop();

            if ( aux.first * -1 != ant )
            {
                act ++;
                update();
            }

            // cout << aux.first * -1 << "  " << ant << endl;

            if ( ataque(aux.first * -1, aux.second) )
                ans ++;

            ant = aux.first * -1;
        }

        cout << "Case #" << tc << ": " << ans << endl;
    }
}
