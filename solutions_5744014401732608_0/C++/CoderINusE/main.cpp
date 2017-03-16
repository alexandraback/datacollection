#include <bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000
using namespace std;
typedef long long ll;
typedef int char_32;
#define INF16 1000000


int b;
pair <int, int> p[50];

int ms[55][55];


void func(int n) {
    ms[1][n] = 1;
    for(int i = n; i <= b; ++i) {

        for(int j = i + 1; j <= b; ++j) {

            ms[i][j] = 1;

        }

    }

}


int main() {
    freopen("B-small-attempt2 (1).in", "r", stdin);
    freopen("ancestor.out", "w", stdout);
    int t; cin >> t;
    ll m;
    for(int z = 0; z < t; ++z) {
        memset(ms,0,sizeof ms);
        cin >> b >> m;

        cout << "Case #" << z + 1 << ": ";

        ll sum = 0;
        vector <ll> d;
        d.resize(b + 2);
        d[0] = 1;
        for(int i = 0; i <= b - 3; ++i) {
            sum += (1LL << i);
            d[i + 1] = (1LL << i);
        }
        sum += 1;
        if(m > sum) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        cout << "POSSIBLE" << endl;



        int k = 2;
        for(int i = b - 2; i >= 0; --i) {

            if(d[i] <= m) {

                func(k);
                m -= d[i];

            }
            k += 1;

        }

        for(int i = 1; i <= b; ++i) {
            for(int j = 1; j <= b; ++j) {
                cout << ms[i][j];
            }
            cout << endl;
        }






    }
}
