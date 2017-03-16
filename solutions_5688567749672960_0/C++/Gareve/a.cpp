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

using namespace std;

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
void solve() {
    int x;scanf("%d",&x);
    printf("%d\n", mem[x]);
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

    int NC;scanf("%d", &NC);
    for (int i=1; i<= NC; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}