#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
map <LL , int> mymap;
LL n;
LL rev (LL n) {
    int bit[20] , len = 0;
    while (n > 0) {
        bit[len ++] = n % 10;
        n /= 10;
    }
    for (int i = 0 ; i < len ; i ++)
        n = n * 10 + bit[i];
    return n;
}
LL bfs (LL n) {
    LL ans = n;
    queue <LL> que;que.push (1);mymap[1] = 1;
    while (!que.empty ()) {
        LL u = que.front ();que.pop ();
        LL k = mymap[u];
        if (k > ans) {
            continue;
        }
        if (u <= n) {
            ans = min (ans , n - u + k);
        }
        if (mymap.count (u + 1) == 0) {
            que.push (u + 1);
            mymap[u + 1] = k + 1;
        }
        LL v = rev (u);
        if (mymap.count (v) == 0) {
            que.push (v);
            mymap[v] = k + 1;
        }
    }
    return ans;
}
int main () {
    // freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%lld" , &n);
        mymap.clear ();
        printf ("Case #%d: %lld\n" , ++ cas , bfs (n));
    }
    return 0;
}