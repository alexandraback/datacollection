#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

int a[100+5][100+5], w[100+5], h[100+5];
int f(int n, int m) {
    memset(h, 0, sizeof(h));
    memset(w, 0, sizeof(w));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            w[i] = max(w[i], a[i][j]);
            h[j] = max(h[j], a[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {

        for(int j = 0; j < m; j++) {
            if(a[i][j] != min(w[i], h[j]))  return 0;
        }
    }
    return 1;
}
int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                scanf("%d", &a[j][k]);
            }
        }

        cout << "Case #" << i+1 << ": " << (f(n, m) ? "YES" : "NO") << endl;
    }
    return 0;
}
