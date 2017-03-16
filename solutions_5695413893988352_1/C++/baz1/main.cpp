#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <utility>
#include <string>
#include <tuple>

//#include <gmpxx.h>

using namespace std;

typedef unsigned long long ull;

inline ull getDiff(const ull a, const ull b) {
    return (a < b) ? b - a : a - b;
}

static string C, J;

tuple<ull,ull,ull,ull,ull,ull,ull> getSuffix(int i) {
    if (i >= C.length()) return tuple<ull,ull,ull,ull,ull,ull,ull>(0, 0, 0, 0, 0, 0, 1);
    ull Cmin, Csim, Cmax, Jmin, Jsim, Jmax, w;
    tie(Cmin, Csim, Cmax, Jmin, Jsim, Jmax, w) = getSuffix(i + 1);
    if (C[i] == '?') {
        if (J[i] == '?') {
            if (getDiff(Csim, Jsim) > getDiff(Cmax, Jmin + w)) {
                Csim = Cmax;
                Jsim = Jmin + w;
            }
            if (getDiff(Csim, Jsim) > getDiff(Cmin + w, Jmax)) {
                Csim = Cmin + w;
                Jsim = Jmax;
            }
            Cmax += 9 * w;
            Jmax += 9 * w;
        } else {
            ull Jd = J[i] - '0';
            if ((Jd > 0) && (getDiff(Csim, Jsim) >= getDiff(Cmax, Jmin + w))) {
                Csim = Cmax + (Jd - 1) * w;
                Jsim = Jmin + Jd * w;
            } else if ((Jd < 9) && (getDiff(Csim, Jsim) > getDiff(Cmin + w, Jmax))) {
                Csim = Cmin + (Jd + 1) * w;
                Jsim = Jmax + Jd * w;
            } else {
                Csim += Jd * w;
                Jsim += Jd * w;
            }
            Jmin += Jd * w;
            Jmax += Jd * w;
            Cmax += 9 * w;
        }
    } else {
        if (J[i] == '?') {
            ull Cd = C[i] - '0';
            if ((Cd < 9) && (getDiff(Csim, Jsim) > getDiff(Cmax, Jmin + w))) {
                Csim = Cmax + Cd * w;
                Jsim = Jmin + (Cd + 1) * w;
            } else if ((Cd > 0) && (getDiff(Csim, Jsim) >= getDiff(Cmin + w, Jmax))) {
                Csim = Cmin + Cd * w;
                Jsim = Jmax + (Cd - 1) * w;
            } else {
                Csim += Cd * w;
                Jsim += Cd * w;
            }
            Cmin += Cd * w;
            Cmax += Cd * w;
            Jmax += 9 * w;
        } else {
            ull Jd = J[i] - '0', Cd = C[i] - '0';
            if (Jd == Cd) {
                Csim += Cd * w;
                Jsim += Jd * w;
            } else if (Cd < Jd) {
                Csim = Cmax + Cd * w;
                Jsim = Jmin + Jd * w;
            } else {
                Csim = Cmin + Cd * w;
                Jsim = Jmax + Jd * w;
            }
            Cmin += Cd * w;
            Cmax += Cd * w;
            Jmin += Jd * w;
            Jmax += Jd * w;
        }
    }
    return tuple<ull,ull,ull,ull,ull,ull,ull>(Cmin, Csim, Cmax, Jmin, Jsim, Jmax, w * 10);
}

string toString(ull n) {
    string result;
    result.reserve(C.length());
    while (n) {
        result.push_back('0' + (n % 10));
        n /= 10;
    }
    while (result.length() < C.length())
        result.push_back('0');
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T;) {
        cin >> C >> J;
        ull Csim, Jsim;
        tie(ignore, Csim, ignore, ignore, Jsim, ignore, ignore) = getSuffix(0);
        cout << "Case #" << (++i) << ": " << toString(Csim) << " " << toString(Jsim) << endl;
    }
    return 0;
}
