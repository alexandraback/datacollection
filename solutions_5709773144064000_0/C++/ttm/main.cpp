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

int main(int argc, char* argv[]) {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int cases; cin >> cases;
    for (int cas = 0; cas < cases; ++cas) {
        cin >> fcost >> fbonus >> win;
        double time = win / 2.0, best_time = time;
        for (int n_f = 0; 1; ++n_f) {
            time = idk(n_f);
            if (time > best_time) break;
            best_time = time;
        }
        printf("Case #%i: %.7f\n", cas + 1, best_time);
    }
}
