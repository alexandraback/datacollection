#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cassert>
#include <limits>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

double minTime(double C, double F, double X) {
    double winTime = X / 2.0;
    double curRate = 2.0;
    double farmTime = C / 2.0;

    while (farmTime < winTime) {
        curRate += F;
        double t = farmTime + (X / curRate);
        winTime = std::min(t, winTime);
        farmTime += C / curRate;
    }

    return winTime;
}

int main() {
    std::cout.precision(10);
    // ifstream in("sample.in");
    istream& in = cin;

    int T;
    in >> T;
    for (int t = 0; t != T; ++t) {
        double C, F, X;
        in >> C >> F >> X;
        cout << "Case #" << (t+1) << ": " << minTime(C, F, X) << endl;
    }
    return 0;
}
