#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

#define pb push_back
#define mp make_pair
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) n; i++)

const int INF = 1e9;

using namespace std;

int d[10000000];

int rev(int x) {
    int res = 0;
    while (x > 0) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    freopen("a.in", "rt", stdin);
    freopen("a.out", "wt", stdout);

    int t, n;

    forn(i, 1000001) {
        d[i] = INF;
    }

    d[1] = 1;
    queue <int> q;
    q.push(1);
    for (int i = 1; i <= 1000000; i++) {
        int v = q.front();
        q.pop();
        if (d[v + 1] == INF) {
            d[v + 1] = d[v] + 1;
            q.push(v + 1);
        }
        int u = rev(v);
        if (d[u] == INF) {
            d[u] = d[v] + 1;
            q.push(u);
        }
    }

    scanf("%d", &t);

    forn(t1, t) {
        cin >> n;

    	cout << "Case #" << t1 + 1 << ": " << d[n] << endl;
    }


    return 0;
}