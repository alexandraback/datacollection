#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <cassert>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long L;

const int MX = 1000009;
int mem[MX];
char str[100];
int rev(int x) {
    sprintf(str, "%d", x);
    string s(str);

    reverse(s.begin(), s.end());
    int ans;
    sscanf(s.c_str(),"%d", &ans);
    return ans;
}

L rev2(L x) {
    sprintf(str, "%lld", x);
    string s(str);

    reverse(s.begin(), s.end());
    L ans;
    sscanf(s.c_str(),"%lld", &ans);
    return ans;
}

typedef pair<int,L> P;

L pd(int k){
    L ans = 1;
    for (int i=1;i<=k;i++)ans*=10LL;
    return ans;
}
L f(L x) {
    //L x;
    //sscanf(str.c_str(), "%lld", &x);
    sprintf(str, "%lld", x);
    //string N(str);

    //cout << x << endl;
    if(x <= 999LL)return mem[x];

    int len = strlen(str);//x.size();
    int mid = (len) / 2;

    L lft = (x % pd(mid));
    if (lft == 0LL) return f(x - 1LL) + 1LL;
    if (lft == 1LL) {
        L xx = rev2(x);
        L lft2 = xx % pd(mid);

        if (lft2 == 1)
            return f(x - 1LL) + 1LL;
        else
            return f(xx) + 1LL;
    }

    return f(x - lft + 1) + lft - 1;
}
void solve() {
    //string line;cin >> line;
    L x;cin >> x;
    int ans = f(x);
    printf("%d\n", ans);
    //printf("%d : %d\n", ans, mem[x]);
    //assert(mem[x] == ans);
}
int main() {
    memset(mem, -1, sizeof(mem));
    mem[1] = 1;
    queue<int> q;

    int x,t,y;
    q.push(1);
    while (!q.empty()) {
        x = q.front();q.pop();
        t = mem[x] + 1;

        y = x + 1;
        if (y < MX and mem[y] == -1) {
            mem[y] = t;
            q.push(y);
        }

        y = rev(x);
        //cout << x << "@" << y << endl;
        if (y < MX and mem[y] == -1) {
            mem[y] = t;
            q.push(y);
        }
    }

    int NC;cin >> NC;
    for (int i=1; i<= NC; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}