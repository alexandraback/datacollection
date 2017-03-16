#pragma  comment(linker, "/STACK:36777216")
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define  lc(x) (x<<1)
#define  rc(x) (lc(x)+1)
#define  PI    (acos(-1))
#define  EPS   1e-8
#define  MAXN  222222
#define  MAXM  888888
#define  LL    long long
#define  ULL   unsigned long long
#define  INF   0x7fffffff
#define  pb    push_back
#define  mp    make_pair
#define  mod   1000000007
#define  lowbit(x) (x&(-x))

using namespace std;

vector <pair<char, int> > vec[105];

bool check(int x, int y){
    if(vec[x].size() != vec[y].size()) return false;
    for(int i = 0; i < vec[x].size(); i ++)
        if(vec[x][i].first != vec[y][i].first) return false;
    return true;
}

int t, n;
char ch[105];

int main(){
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> t;
    for(int cas = 1; cas <= t; cas ++){
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++){
            scanf(" %s", &ch);
            char now = ch[0];
            int cnt = 1, len = strlen(ch);
            vec[i].clear();
            for(int j = 1; j < len; j ++)
                if(ch[j] != ch[j - 1])
                    vec[i].pb(mp(now, cnt)), now = ch[j], cnt = 1;
                else cnt ++;
            vec[i].pb(mp(now, cnt));
        }
        printf("Case #%d: ", cas);
        bool flag = false;
        for(int i = 1; i <= n; i ++)
            for(int j = i + 1; j <= n; j ++)
                if(check(i, j) == false)
                    flag = true;
        for(int i = 1; i <= n; i ++){
            for(int j = 0; j < vec[1].size(); j ++)
                cout << vec[i][j].second << ' ';
            cout << endl;
        }
        if(flag) printf("Fegla Won\n");
        else{
            int ans = 0;
            for(int i = 0; i < vec[1].size(); i ++){
                int mn = INF;
                for(int j = 1; j <= 200; j ++){
                    int res = 0;
                    for(int k = 1; k <= n; k ++)
                        res += abs(vec[k][i].second - j);
                    mn = min(mn, res);
                }
                ans += mn;
            }
            printf("%d\n", ans);
        }
    }
}
