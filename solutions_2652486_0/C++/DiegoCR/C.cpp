#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

int arr[110];
bool visit[110];
int R, N, M, K;
int need;
vector <int> pos;

void solve()
{
    srand (time(NULL));
    pos.clear();
    for ( int i = 2; i <= 5; i ++ )
        for ( int j = i; j <= 5; j ++ )
            for ( int k = j; k <= 5; k ++ )
            {
                int cont = 0;
                memset(visit, false, sizeof(visit));
                for ( int mask = 0; mask < (1<<3); mask ++ )
                {
                    int mult = 1;
                    if ( mask & 1 ) mult *= i;
                    if ( mask & 2 ) mult *= j;
                    if ( mask & 4 ) mult *= k;

                    if ( arr[mult] && !visit[mult] )
                    {
                        visit[mult] = true;
                        cont ++;
                    }
                }

                if ( cont >= need )
                    pos.push_back(i*100 + j*10 + k);
            }
    /*
    for ( int i = 0; i < pos.size(); i ++ )
        cout << pos[i] << " -- " << endl;
    cout << endl;
    */
    int opc = rand() % pos.size();
    cout << pos[opc] << endl;

}

int main()
{
    freopen ( "SmallC.in", "r", stdin );
    freopen ( "SmallC.out", "w", stdout );

    int tc, num;

    cin >> tc;

    cin >> R >> N >> M >> K;

    cout << "Case #1:" << endl;

    for ( int i = 0; i < R; i ++ )
    {
        memset ( arr, 0, sizeof(arr) );
        need = K;
        for ( int j = 0; j < K; j ++ )
        {
            cin >> num;
            if ( arr[num] ) need --;
            arr[num] = 1;

        }
        // cout << i << endl;
        solve();
    }
}
