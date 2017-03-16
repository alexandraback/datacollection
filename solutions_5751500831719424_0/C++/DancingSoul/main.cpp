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
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;


vector<char> a[105];
vector<int> b[105];

string s;
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int CAS, n;
    scanf("%d", &CAS);
    for (int cas = 1; cas <= CAS; cas++){
        printf("Case #%d: ", cas);
        for (int i = 0; i < 100; i++) a[i].clear(), b[i].clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            cin >> s;
            int cnt = 1;
            for (int j = 1; j < s.size(); j++)
            if (s[j] != s[j - 1]){
                a[i].PB(s[j - 1]);
                b[i].PB(cnt);
                cnt = 1;
            }else cnt++;
            a[i].PB(s[s.size() - 1]);
            b[i].PB(cnt);
        }
        int flag = 0;
        for (int i = 1; i < n; i++)
        if (a[i].size() != a[i - 1].size()) flag = 1;
        if (flag){
            puts("Fegla Won");
            continue;
        }
        for (int i = 1; i < n; i++)
        for (int j = 0; j < a[i].size(); j++)
        if (a[i][j] != a[i - 1][j]) flag = 1;
        if (flag){
            puts("Fegla Won");
            continue;
        }
        int ans = 0;
        for (int i = 0; i < a[0].size(); i++){
            int mx = -INF, mn = INF;
            for (int j = 0; j < n; j++)
                mx = max(b[j][i], mx), mn = min(b[j][i], mn);
            ans += mx - mn;
        }
        printf("%d\n", ans);
    }
}
