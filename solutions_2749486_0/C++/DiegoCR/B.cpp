#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int mx[] = {0, 0, 1, -1};
int my[] = {1, -1, 0, 0};
char dir[] = {'N', 'S', 'E', 'W'};

int mem[505][205][205];

struct p
{
    int x, y, t;
    p(){}
    p(int a, int b, int c)
    {
        x = a;
        y = b;
        t = c;
    }
}aux;

bool isin(int x, int y)
{
    if ( x < 0 || y < 0 )
        return false;
    if ( x > 200 || y > 200 )
        return false;
    return true;
}

int main()
{
    freopen( "b.in", "r", stdin );
    freopen( "SmallB.out", "w", stdout );

    int ntc, tc = 0, X, Y, pasos;

    cin >> ntc;

    while ( ntc -- )
    {
        tc ++;

        cin >> X >> Y;

        X += 100;
        Y += 100;

        queue< p > Q;
        Q.push( p(100, 100, 1) );
        memset ( mem, -1, sizeof(mem) );

        while ( !Q.empty() )
        {
            aux = Q.front();
            Q.pop();

            // cout << aux.x << "-" << aux.y << "\t" << aux.t << " --> " << mem[aux.t - 1][aux.x][aux.y] << endl;

            if ( aux.x == X && aux.y == Y )
            {
                pasos = aux.t;
                break;
            }

            int a, b;
            for ( int i = 0; i < 4; i ++ )
            {
                a = aux.x + mx[i]*aux.t;
                b = aux.y + my[i]*aux.t;

                if ( !isin(a, b) )
                    continue;
                if ( mem[aux.t][a][b] != -1 ) continue;

                mem[aux.t][a][b] = i;
                Q.push(p(a, b, aux.t + 1));
            }
        }

        string ans = "";
        int tx, ty;

        while ( pasos > 1 )
        {
            pasos --;
            ans += dir[mem[pasos][X][Y]];
            // cout << X << "  " << Y << " ++ "<< pasos << " es " << mem[pasos][X][Y] << endl;
            tx = X + mx[mem[pasos][X][Y]]*(-1)*pasos;
            ty = Y + my[mem[pasos][X][Y]]*(-1)*pasos;
            X = tx;
            Y = ty;
        }

        reverse( ans.begin(), ans.end() );

        cout << "Case #" << tc << ": " << ans << endl;
    }
}
