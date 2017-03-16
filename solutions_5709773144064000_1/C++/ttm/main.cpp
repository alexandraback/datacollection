#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <utility>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

double fcost, fbonus, win;

double idk(double f) {
    double time = 0.0;
    for (double i = 0; i < f; ++i) {
        time += fcost / (2.0 + fbonus * i);
    }
    time += win / (2.0 + f * fbonus);
    return time;
}

double binsearch(int lo, int hi) {
    if (lo == hi || lo + 1 == hi) {
        return idk(lo);
    }
    double lv = idk(lo);
    double hv = idk(hi);
    int mid = (hi + lo) / 2;
    if (lv > hv) {
        return binsearch(lo, mid);
    } else
    return binsearch(mid, hi);
}

int main(int argc, char* argv[]) {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int cases; cin >> cases;
    for (int cas = 0; cas < cases; ++cas) {
        cin >> fcost >> fbonus >> win;
        double time = win / 2.0, best_time = time;
        best_time = binsearch(0, int(win / 2));
        printf("Case #%i: %.7f\n", cas + 1, best_time);
    }
}
