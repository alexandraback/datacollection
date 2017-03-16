#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int reverse(int x) {
    vector<int> d;
    while (x > 0) {
        d.push_back(x % 10);
        x /= 10;
    }

    string res = "";
    for (int i = 0; i < d.size(); ++i) {
        if (d[i] == 0 && res == "") continue;
        res.push_back(d[i] + '0');
    }

    int y;
    sscanf(res.c_str(), "%d", &y);

    return y;
}

int main() {
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int n;
        cin >> n;
        vector<int> d(n + 1, 1e9);
        d[1] = 1;
        for (int x = 1; x < n; ++x) {
            int y = x + 1;
            d[y] = min(d[y], d[x] + 1);
            y = reverse(x);
            if (y <= n)
//            cerr << x << " " << y << endl;
                d[y] = min(d[y], d[x] + 1);
        }

        cout << "Case #" << test << ": " << d[n] << endl; 
    }
}
