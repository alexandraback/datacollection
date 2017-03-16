#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm> // max...
#include <utility> // pair
#include <complex>
#include <climits> // int, ll...
#include <limits> // double...
#include <cmath> // abs, atan...
#include <cstring> // memset
#include <string>
#include <functional> // greater, less...
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, double> id;
typedef pair<double, int> di;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<id> vid;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, ll> mil;
typedef map<ll, ll> mll;

//#define ONLINE_JUDGE

// sacar i posicion del bloque block
int getcell(int i, int block, int k) {
    return (block-1) * k + i;
}

int main() {
#ifdef ONLINE_JUDGE
    freopen("X-small-practice.in", "r", stdin);
        freopen("X-small-practice.out", "w", stdout);
        //freopen("X-large-practice.in", "r", stdin);
        //freopen("X-large-practice.out", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
    freopen("D-large.in", "r", stdin);
    freopen("D-large.out", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int K, C, S; cin >> K >> C >> S;
        if (K == S) {
            printf("Case #%d: ", t);
            for (int i = 1; i < K; i++) printf("%d ", i);
            printf("%d\n", K);
        } else {
            printf("Case #%d: ", t);

            int n = K / 2;
            if (K % 2 == 1) n++;
            if (n > S) {
                cout << "IMPOSSIBLE" << endl;
                continue;
            }

            for (int i = 1; i <= K-2; i += 2) {
                printf("%d ", getcell(i+1, i, K));
            }
            if (K % 2 == 0) {
                printf("%d\n", getcell(K, K-1, K));
            } else {
                printf("%d\n", K);
            }
        }
    }

    return 0;
}