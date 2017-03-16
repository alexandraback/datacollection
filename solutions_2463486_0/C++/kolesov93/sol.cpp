#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

using namespace std;

typedef long long ll;

const ll N = ll(1e14) + 100;

bool cool(ll x) {
    vector<int> a;
    while (x) {
        a.push_back(x % 10);
        x /= 10;
    }
    for (int i = 0; i < int(a.size()) - i - 1; ++i)
        if (a[i] != a[ int(a.size()) - i - 1 ]) return false;
    return true;
}

vector<ll> A;

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int _T;
    scanf("%d\n", &_T);

    for (ll x = 1; x * x <= N; ++x)
        if (cool(x) && cool(x * x)) {
            A.push_back(x * x);
            cerr << x << " " << x * x << endl;
        }
    cerr << "Number: " << A.size() << endl;

    for (int __test = 1; __test <= _T; ++__test) {
        ll a, b;
        cin >> a >> b;

        printf("Case #%d: ", __test);
        cout << upper_bound(A.begin(), A.end(), b) - lower_bound(A.begin(), A.end(), a) << endl;
    }


    return 0;
}

