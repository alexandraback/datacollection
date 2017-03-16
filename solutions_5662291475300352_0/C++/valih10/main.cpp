#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<iomanip>
#include<bitset>
using namespace std;

double d1, d2, d3, d4;

void sol() {
    int n;

    d1 = d2 = 0;
    int a, b, c, cc, vv = 1;

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> a >> b >> cc;

        for(int j = 1; j <= b; ++j) {
            c = cc + j - 1;

            double aa = 1.0 * (360 - a) * c / 360, bb = aa + c;

            if(vv) {
                d1 = aa;
                d2 = bb;
                vv = 0;
            }
            else {
                d3 = aa;
                d4 = bb;
            }
        }
    }

    if(d2 > d4) {
        swap(d4, d2);
        swap(d3, d1);
    }

    if(d2 <= d3)
        cout << 1;
    else
        cout << 0;
}

int main() {
    freopen("ttt", "r", stdin);
    freopen("tttt", "w", stdout);

    int t, a = 0;
    cin >> t;

    while(t--) {
        ++a;
        cout << "Case #" << a << ": ";
        sol();
        cout << "\n";
    }

    return 0;
}
