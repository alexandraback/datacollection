#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <iomanip>




using namespace std;

const int MAXN = 100;
typedef long long LL;
int T;
int N;
LL mat[MAXN][MAXN];



int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> T;
    for(int ncase = 1; ncase <= T; ncase++)
    {
        int M;
        cin >> N;
        memset(mat, 0, sizeof(mat));
        for(int i = 1; i <= N; i++)
        {
            cin >> M;
            for(int j = 0; j < M; j++)
            {
                int x;
                cin >> x;
                mat[i][x] = 1;
            }
        }
        for(int k = 1; k <= N; k++)
        {
            for(int i = 1; i <= N; i++)
            {
                for(int j = 1; j <= N; j++)
                {
                    mat[i][j] += mat[i][k] * mat[k][j];
                }
            }
        }
        bool bingo = false;
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(mat[i][j] >= 2)
                {
                    bingo = true;
                    break;
                }
            }
            if(bingo) break;

        }
        cout << "Case #" << ncase << ": ";
        if(bingo) cout << "Yes" << endl;
        else cout << "No" << endl;
    }













    return 0;
}

