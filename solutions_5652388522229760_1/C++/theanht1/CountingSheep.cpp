#include <bits/stdc++.h>

using namespace std;

bool a[10];

bool check(long long x) {
    while (x > 0) {
        a[x % 10] = true;
        x = x / 10;
    }

    for (int i = 0; i < 10; i++)
        if (!a[i]) return false;
    return true; 
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("CountingSheep.out", "w", stdout);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {        
        long long n;
        cin >> n;

        if (n == 0) {
            cout << "Case #" << i << ": INSOMNIA" << endl;
            continue;
        }

        memset(a, false , sizeof(a));
        long long m = n;
        while (true) {
            if (check(m)) break;
            m += n;
        }

        cout << "Case #" << i << ": " << m << endl;
    }
}
