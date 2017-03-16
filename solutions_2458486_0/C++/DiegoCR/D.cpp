#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

int n;
bool visit[2000000];
bool ok;
vector <int> chest[50];
int need[50];
int camino[50];
map<int, int> keys;

void solve(int used, int act)
{
    if ( act == n )
    {
        ok = true;
        return;
    }

    if ( visit[used] ) return;

    visit[used] = true;

    for ( int i = 0; i < n && !ok; i ++ )
    {
        if ( used & (1<<i) ) continue;
        if ( keys[need[i]] )
        {
            keys[need[i]] --;
            camino[act] = i + 1;
            for ( int j = 0; j < chest[i].size(); j ++ )
                keys[chest[i][j]] ++;
            solve(used | (1<<i), act + 1);
            for ( int j = 0; j < chest[i].size(); j ++ )
                keys[chest[i][j]] --;
            keys[need[i]] ++;
        }
    }
}

int main()
{
    freopen( "d.in", "r", stdin );
    freopen( "DSmall.out", "w", stdout );

    int ntc, tc = 0;
    int k, tipo;

    cin >> ntc;

    while ( ntc -- )
    {
        tc ++;

        cin >> k >> n;

        keys.clear();

        for ( int i = 0; i < k; i ++ )
        {
            cin >> tipo;
            keys[tipo] ++;
        }

        for ( int i = 0; i < n; i ++ )
            chest[i].clear();

        for ( int i = 0; i < n; i ++ )
        {
            cin >> need[i] >> k;
            for ( int j = 0; j < k; j ++ )
            {
                cin >> tipo;
                chest[i].push_back(tipo);
            }
        }

        memset ( visit, 0, sizeof(visit) );

        ok = false;

        solve(0, 0);

        cout << "Case #" << tc << ":";

        if ( !ok )
            cout << " IMPOSSIBLE";
        else
            for ( int i = 0; i < n; i ++ )
                cout << " " << camino[i];
        cout << endl;
    }
}
