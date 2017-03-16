#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int INF = 1e9;

typedef pair<int,int> pii;

int g[20][20];

int eval(int n, int m)
{
    int s = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (g[i][j]){
                s++;
                if (i > 0 && j > 0 && i < n-1 && j < m-1){
                    if (g[i-1][j] && g[i][j-1] && g[i+1][j] && g[i][j+1])s--;
                }
            }
        }
    }
    return s;
}

int solve(int n, int m, int k, int r, int c)
{
    int ms = n*m;
    for (int i = r*m+c; i < n*m - k; i++){
        g[i/m][i%m] = 1;
        int s = (k == 1 ? eval(n,m) : solve(n,m,k-1,(i+1)/m,(i+1)%m));
        if (s < ms)ms = s;
        g[i/m][i%m] = 0;
    }
    return ms;
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int t, T, n, m, k;
    cin >> T;
    for (t=1;t<=T;t++){
        cin >> n >> m >> k;
        for (int i = 0;i < n; i++){
            for (int j = 0; j < m; j++){
                g[i][j] = 0;
            }
        }
        cout << "Case #" << t << ": " << solve(n,m,k,0,0) << "\n";
    }
}
