#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> PP;

/*
    freopen("input","r",stdin);
    freopen("output","w",stdout);
*/


bool solve(int C,int R,int X) {
    int i,j,k,l,r,x,y;
    for (i = 0;i < C;i++) {
        l = i;
        r = C - 1 - l;
        bool ok = 0;
        x = (C - 1) * l;
        for (j = 0;j <= R - C && ok == 0;j++) {
            if (x % X == 0) ok = 1;
            x += C;
        }
        if (ok == 0) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    freopen("D-small-attempt0.in.txt","r",stdin);
    freopen("output","w",stdout);
    int T,X,R,C,L,Y;
    cin >> T;
    for (int z1 = 1;z1 <= T;z1++) {
        cin >> X >> R >> C;
        cout << "Case #" << z1 << ": ";
        if (R < C) swap(R,C);
        if ((R * C) % X != 0) {
            cout << "RICHARD" << endl;
            continue;
        }
        if (R < X) {
            cout << "RICHARD" << endl;
            continue;
        }
        if (C * 2 - 1 > X) {
            cout << "GABRIEL" << endl;
            continue;
        }
        if (C * 2 < X) {
            cout << "RICHARD" << endl;
            continue;
        }
        bool ok = solve(C,R,X);
        if (ok == 1) cout << "RICHARD" << endl;
        else cout << "GABRIEL" << endl;
    }
    return 0;
}
