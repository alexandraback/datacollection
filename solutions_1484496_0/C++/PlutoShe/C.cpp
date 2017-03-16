#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int test, ll, rr, n;
int a[501];
int b[501];
int total, ty;
bool u;

void print1() {
    for (int i = 0; i < n; i++) {
        //cout << b[i] << ' ';
        if (b[i] == 1) cout << a[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; i++)
        if (b[i] == 2) cout << a[i] << ' ';
    cout << endl;
}
int c[4];

void dfs(int k) {
    //cout << k << ' ' << c[1] << ' ' << c[2] << endl;
    if (c[1] > total / 2 || c[2] > total / 2) return;
    if (c[1] != 0 && c[1] == c[2]) {print1();  u = true; return;}
    for (int i =0; i < n; i++) {
        //cout << i;
        if (b[i] == 0) {
            b[i] = k; c[k] += a[i];
            dfs(3 - k);
            if (u) return;
            dfs(k);
            if (u) return;
            b[i] = 0;
            c[k] -= a[i];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++) {
memset(b, 0, sizeof(b));
        u = false;
        cin >> n;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
          //  cout << a[i];
            total += a[i];
        }
        sort(a, a + n);
        //cout << endl << total << endl;
        //if (total & 1 == 1)cout << "Impossible"; {
                //if (a[n - 1] > total) cout << "Impossible"; else
            u = false;
            c[1] = 0; c[2] = 0;
            dfs(1);
            if (!u) cout << "impossible";
        //}
    }

}
