#include <iostream>
#include <sstream>
#include <cmath>

#define lli long long int
#define R 10000000

using namespace std;

int t;
lli a, b;

int d[R+1];

bool pali(lli n) {
    stringstream ss;
    ss << n;
    string p = ss.str();
    int l = p.length();
    for (int i = 0; i < l/2; i++) {
        if (p[i] != p[l-i-1]) return false;
    }
    return true;
}

void alku() {
    for (lli i = 1; i <= R; i++) {
        if (!pali(i)) continue;
        if (!pali(i*i)) continue;
        d[i] = 1;
    }
    for (int i = 1; i <= R; i++) {
        d[i] += d[i-1];
    }
}

void laske(int n) {
    cin >> a >> b;
    int aa = (int)ceil(sqrt((double)a));
    int bb = (int)floor(sqrt((double)b));
    cout << "Case #" << n << ": " << d[bb]-d[aa-1] << "\n";
}

int main() {
    alku();
    cin >> t;
    for (int i = 0; i < t; i++) {
        laske(i+1);
    }
}
