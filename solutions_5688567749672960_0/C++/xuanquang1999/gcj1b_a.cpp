using namespace std;
#include <bits/stdc++.h>
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define ii pair<int, int>
#define mp make_pair
#define pb push_back
#define maxN 1000000
int f[maxN+1];

int reverseI(int x) {
    int n = 0;
    while (x) {
        n = 10*n+x%10;
        x /= 10;
    }
    return n;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    f[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int v = u+1;
        if (v <= maxN && !f[v]) {
            q.push(v);
            f[v] = f[u]+1;
        }
        v = reverseI(u);
        if (v <= maxN && !f[v]) {
            q.push(v);
            f[v] = f[u]+1;
        }
    }

    int nTest;
    scanf("%d", &nTest);
    fto(iTest, 1, nTest) {
        int n;
        scanf("%d", &n);
        printf("Case #%d: %d\n", iTest, f[n]);
    }

    return 0;
}
