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

string ans, s[N];
int v[N], ou[N], n, m;
vector <int> e[N];
void Dfs(int x, int cnt, string now){
    if (!v[x]){
        now += s[x];
        cnt++;
    }
    if (cnt == n){
        //cout << now << endl;
        ans = min(ans, now);
        return;
    }

    v[x]++;
    for (int i = 0; i < e[x].size(); i++)
    if (!ou[e[x][i]]){
        ou[e[x][i]] = x;
        Dfs(e[x][i], cnt, now);
        ou[e[x][i]] = 0;
    }else if (ou[x] == e[x][i]){
        ou[x] = -1;
        Dfs(e[x][i], cnt, now);
        ou[x] = e[x][i];
    }
    v[x]--;
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int CAS;
    scanf("%d", &CAS);
    for (int cas = 1; cas <= CAS; cas++){
        printf("Case #%d: ", cas);
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) cin >> s[i];
        for (int i = 1; i <= m; i++){
            int x, y;
            scanf("%d%d", &x, &y);
            e[x].PB(y);
            e[y].PB(x);
        }

        ans = "";
        for (int i = 1; i <= n; i++) ans += "99999";
        memset(ou, 0, sizeof(ou));
        for (int i = 1; i <= n; i++){
            ou[i] = -1;
            Dfs(i, 0, "");
            ou[i] = 0;
        }
        cout << ans << endl;

        for (int i = 1; i <= n; i++) e[i].clear();


    }
}
