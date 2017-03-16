#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

long long ans;
bool hch[30];
string s[111];
int q[111];
int n;

void check()
{
    memset(hch, true, sizeof hch);
    char last = ' ', c;
    for (int i = 1; i <= n; i++) {
        int len = s[q[i]].length();
        for (int j = 0; j < len; j++) {
            //cout << s[q[i]][j];
            c = s[q[i]][j];
            //cout << hch['b'-'a'+1];
            if (!(last == c))
            if (!hch[c - 'a' + 1]) return;
            else hch[c - 'a' + 1] = false;
            last = c;
        }
    }
    //cout << endl;
    ans++;
    ans = ans % 1000000007;
}

bool h[111];

void dfs(int dep)
{
    if (dep > n) {check();return;}
    for (int i = 1; i<= n; i++)
    if (h[i]) {
        h[i] = false;
        q[dep] = i;
        dfs(dep+1);
        h[i] = true;
    }
}

int main()
{
    freopen("cars.in","r",stdin);
    freopen("cars.out","w", stdout);
    int testcase;
    scanf("%d", &testcase);
    for (int test = 1; test <= testcase; test++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            //scanf("%s", s[i]);
            cin >> s[i];
        }
        //for (int i = 1; i <= n; i++)
        //    cout << s[i] << endl;
        memset(h, true, sizeof h);
        ans = 0;
        dfs(1);
        printf("Case #%d: %d\n", test, ans);
    }
    return 0;
}
