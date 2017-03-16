#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <functional>
#include <iterator>
#include <complex>

using namespace std;

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;

const int N_MAX = 110;
int c[N_MAX][N_MAX], f[N_MAX][N_MAX];
int d[N_MAX][N_MAX];
bool use[N_MAX][N_MAX];

const int DX[4] = {1, -1, 0, 0};
const int DY[4] = {0, 0, 1, -1};
const int K = 4;
const int DH = 50;

int main()
{
    int nTests;
    cin >> nTests;

    for (int test = 0; test < nTests; ++test)
    {
        int h, n, m;
        cin >> h >> n >> m;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) cin >> c[i][j];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) cin >> f[i][j];
        
        memset(d, -1, sizeof(d));

        d[0][0] = 0;
        

        for (int z = 0; z < 2; ++z)
        {
#ifdef DEBUG
            cerr << "Iteration " << z << '\n';
            for (int i = 0; i < n; ++i, cerr << '\n')
                for (int j = 0; j < m; ++j) cerr << d[i][j] << ' ';
#endif
            memset(use, 0, sizeof(use));
            while (true)
            {
                int cur_x = -1, cur_y = -1;

                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < m; ++j)
                        if (!use[i][j] && d[i][j] != -1 && (cur_x == -1 || d[cur_x][cur_y] > d[i][j]))
                            cur_x = i, cur_y = j;
                if (cur_x == -1) break;    


                int ct = d[cur_x][cur_y];
                use[cur_x][cur_y] = true;

                for (int k = 0; k < K; ++k)
                {
                    int nx = cur_x + DX[k], ny = cur_y + DY[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                    {
                        int mt = -1;

                        if (f[nx][ny] + DH <= c[nx][ny] && f[cur_x][cur_y] + DH <= c[nx][ny] && f[nx][ny] + DH <= c[cur_x][cur_y])
                        {
                                
                            int ch = max(h - ct - f[cur_x][cur_y], 0);
                            assert(ch + DH <= c[cur_x][cur_y]);

                            int nh = c[nx][ny] - DH - f[cur_x][cur_y];

                            if (nh >= 0)
                            {
                                int rh = min(nh, ch);
                                if (z == 0)
                                {
                                    if (rh == ch) mt = 0;
                                }
                                else
                                    mt = ct + (ch - rh) + (rh >= 20 ? 10 : 100);
                            }
                        }

                        if (mt != -1)
                        {
                            if (d[nx][ny] == -1 || d[nx][ny] > mt)
                                d[nx][ny] = mt;
                        }
                    }
                }
            }
        }
        int ans = d[n - 1][m - 1];
        cout << "Case #" << test + 1 << ": " << ans / 10 << '.' << ans % 10 << '\n';
    }
    return 0;
}
