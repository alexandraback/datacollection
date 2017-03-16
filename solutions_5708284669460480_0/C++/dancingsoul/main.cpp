#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int M = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int CAS, k, l, s;
char a[105], t[105];
DB f[105][105][105];
int next[105][105];

void get_next(){
    for (int i = 0; i <= l; i++)
    for (int j = 0; j < k; j++){
        for (int x = min(l, i + 1); x >= 0; x--){
            int flag = 1;
            for (int y = 0; y < x; y++){
                if ((!y && t[x - 1] != a[j]) || (y && t[x - y - 1] != t[i - y])){
                    flag = 0;
                    break;
                }
            }
            if (flag){
                next[i][j] = x;
                break;
            }
        }
    }
}

int get(){
    int now = 0, ret = 0;
    for (int i = 0; i < s; i++){
        int mx = -1, nxt;
        for (int j = 0; j < k; j++)
        if (next[now][j] > mx){
            mx = next[now][j];
            nxt = j;
        }
        now = next[now][nxt];
        if (now == l) ret++;
    }
    return ret;
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &CAS);
    for (int cas = 1; cas <= CAS; cas++){
        scanf("%d%d%d", &k, &l, &s);
        scanf("%s", a);
        scanf("%s", t);

        memset(f, 0, sizeof(f));
        memset(next, 0, sizeof(next));
        get_next();
        int mx = get();
        f[0][0][0] = 1;
        for (int i = 0; i < s; i++)
        for (int j = 0; j <= l; j++)
        for (int x = 0; x <= mx; x++)
        for (int nxt = 0; nxt < k; nxt++){
            int p = next[j][nxt];
            if (p == l) f[i + 1][p][x + 1] += f[i][j][x] / k;
            else f[i + 1][p][x] += f[i][j][x] / k;
        }
        DB ans = 0;
        for (int i = 0; i <= l; i++)
        for (int j = 0; j <= mx; j++){
            ans += f[s][i][j] * j;
        }
        printf("Case #%d: %.8f\n", cas, mx - (float)ans);
    }
}
