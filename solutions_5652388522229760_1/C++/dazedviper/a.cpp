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

#define ONLINE_JUDGE

bool digits[10];

bool done() {
    for (int i = 0; i < 10; i++)
        if (!digits[i]) return false;
    return true;
}

int main() {
#ifdef ONLINE_JUDGE
    freopen("A-large.in", "r", stdin);
        freopen("A-large.out", "w", stdout);
        //freopen("X-large-practice.in", "r", stdin);
        //freopen("X-large-practice.out", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int N; cin >> N;
        if (N == 0) {
            printf("Case #%d: INSOMNIA\n", i);
            continue;
        }

        for (int i = 0; i < 10; i++)
            digits[i] = false;

        int M = N;
        for (int i = 1; !done(); i++) {
            M = i * N;
            int x = M;
            while (x > 0) {
                digits[x % 10]++;
                x /= 10;
            }

            /*
            for (int i = 0; i < 10; i++)
                cout << digits[i] << " ";
            cout << endl;
             */
        }

        printf("Case #%d: %d\n", i, M);
    }

    return 0;
}