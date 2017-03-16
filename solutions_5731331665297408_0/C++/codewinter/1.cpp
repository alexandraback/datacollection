#include <bits/stdc++.h>
using namespace std;

const int N = 15;

void solve()
{
    string s[15];
    int a[15];
    int n,m;
    cin >> n >> m;
    int x,y;
    int c[15][15];
    memset(c,0,sizeof(c));
    for(int i = 1; i <= n; i ++) cin >> s[i],a[i] = i;
    while(m --) {
        scanf("%d%d",&x,&y);
        c[x][y] = c[y][x] = 1;
    }    
    string ans = "",empty = "";
    do {
        stack<int> stk;
        stk.push(a[1]);
        for(int i = 2; i <= n; i ++) {
            while(!stk.empty()) {
                if(c[stk.top()][a[i]]) {
                    break;
                }
                else stk.pop();
            }
            if(stk.empty()) break;
            stk.push(a[i]);
            if(i == n) {
                string tmp;
                for(int j = 1; j <= n; j ++)
                    tmp += s[a[j]];
                if(ans == empty) ans = tmp;
                else if(ans > tmp) ans = tmp;
            }
        }
    }while(next_permutation(a + 1,a + n + 1));
    if(n == 1) ans = s[1];
    cout << ans << endl;
}

int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas = 1; cas <= t; cas ++) {
        printf("Case #%d: ",cas);
        solve();
    }
    return 0;
}
