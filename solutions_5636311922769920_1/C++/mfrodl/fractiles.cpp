#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long pow(int a, int n) {
    return (n == 0) ? 1 : a * pow(a, n - 1);
}

long tile(vector<int> coord, int k) {
    long result = 0;
    for (int i = 0; i < coord.size() - 1; i++) {
        result += coord[i] - 1;
        result *= k;
    }
    result += coord.back();
    return result;
}

void compute(int k, int c, int s) {
    if (c * s < k) {
        cout << " IMPOSSIBLE";
    }
    else {
        for (int i = 1; i <= k; i += c) {
            vector<int> v;
            for (int j = 0; j < c; j++) {
                v.push_back(min(i + j, k));
            }
            cout << " " << tile(v, k);
        }
    }
}

int main() {

    int t;
    int k, c, s;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> k >> c >> s;
        cout << "Case #" << i + 1 << ":";
        compute(k, c, s);
        cout << endl;
    }
/*
    vector<int> v;
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    cout << tile(v, 8) << endl;
*/
    return 0;
}
