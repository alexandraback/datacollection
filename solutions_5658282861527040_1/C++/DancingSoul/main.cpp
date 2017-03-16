#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int,int> PI;

const DB eps = 1e-6;
const int N = 50 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;


LL f[40][2][2][2];

int a[40], b[40], c[40];

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int CAS;
    scanf("%d", &CAS);
    for (int cas = 1; cas <= CAS; cas++){
        printf("Case #%d: ", cas);
        LL A, B, C, _A, _B, _C;
        cin >> A >> B >> C;
        A--, B--, C--;
        for (int i = 0; i <= 32; i++){
            a[i] = A >> i & 1;
            b[i] = B >> i & 1;
            c[i] = C >> i & 1;
        }
        memset(f, 0, sizeof(f));
        f[33][1][1][1] = 1;


        for (int i = 32; i >= 0; i--)
        for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
        for (int x = 0; x < 2; x++)
        for (int _a = 0; _a < 2; _a++)
        for (int _b = 0; _b < 2; _b++){
            if (j && (_a && !a[i])) continue;
            if (k && (_b && !b[i])) continue;
            if (x && ((_a & _b) && !c[i])) continue;
            if (j && ((_a && a[i]) || (!_a && !a[i]))) _A = 1; else _A = 0;
            if (k && ((_b && b[i]) || (!_b && !b[i]))) _B = 1; else _B = 0;
            if (x && (((_a & _b) && c[i]) || (!(_a & _b) && !c[i]))) _C = 1; else _C = 0;
            f[i][_A][_B][_C] += f[i + 1][j][k][x];
        }
        LL ans = 0;
        for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
            ans += f[0][i][j][k];
        cout << ans << endl;
    }

}
