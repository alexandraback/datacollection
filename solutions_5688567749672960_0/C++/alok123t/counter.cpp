#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=a;i<b;i++)
const int MX = 1e6 + 6;
int a[MX];
int rev(int x) {
    int ret = 0;
    while(x > 0) {
        ret = ret*10 + x%10;
        x /= 10;
    }
    return ret;
}
void pre() {
    a[1] = 1;
    queue < int > q;
    q.push(1);
    int x;
    while(!q.empty()) {
        x = q.front();
        q.pop();
        if(x + 1 < MX && a[x+1] == 0) {
            a[x+1] = a[x] + 1;
            q.push(x+1);
        }
        if(rev(x) < MX && a[rev(x)] == 0) {
            a[rev(x)] = a[x] + 1;
            q.push(rev(x));
        }
    }
}
int main() {
    pre();
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, n;
    scanf("%d",&t);
    FOR(T, 0, t) {
        scanf("%d",&n);
        printf("Case #%d: %d\n",T+1, a[n]);
    }
    return 0;
}
