#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

int T;
long long f[16], e[16];
long long s;

void pre(){
    f[1] = 1;e[1] = 1;
    f[2] = 11;e[2] = 11;
    long long x = 100;
    for (int i = 3; i <= 15; i++) {
        f[i] = 3 + 8 * 2 + f[i-1];
        long long k = 10;
        int l = (i - 3) / 2;
        for (int j = 1; j <= l; j++) {
            f[i] += 2 * 9 * k;
            k *= 10;
        }
        if (i % 2 == 0) {
            f[i] += 9 * k;
        }
        e[i] = x + 1;
        x *= 10;
    }
}

long long gao(){
    long long ret = 0;
    long long x = s;
    if (s % 10 == 0) {
        ret += 1;
        x -= 1;
    }
    vector<int> a;
    for (; x; x /= 10) {
        a.push_back(int(x % 10));
    }
    long long k = 1;
    for (int i = 0; i < a.size()/2; i++) {
        if (i == 0) {
            ret += k * (a[i] + a[a.size() - 1 - i] - 2);
        }else {
            ret += k * (a[i] + a[a.size() - 1 - i]);
        }
        k *= 10;
    }
    if (a.size() % 2 == 1) {
        int i  = a.size() / 2;
        if (i == 0) {
            ret += k * (a[i] - 1);
        }else {
            ret += k * a[i];
        }
    }
    return min(ret + 1, s - e[a.size()]) + f[a.size()];
}

int main() {
    pre();
    cin >> T;
    for (int Ca = 1; Ca <= T; Ca++) {
        cin >> s;
        cout << "Case #" << Ca << ": " << gao() << endl;
    }

    return 0;
}