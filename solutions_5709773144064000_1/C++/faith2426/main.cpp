#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ifstream ifs("in.in");
    ofstream ofs("out.out");

    int T;
    ifs >> T;
    for (int t = 1; t <= T; ++t) {
        double C, F, X;
        ifs >> C >> F >> X;

        double result = 0.0;
        double cookies = 0.0;
        double rate = 2.0;

        if (C >= X) {
            result = X / rate;
            cookies = X;
        } else {
            for (double diff = X - cookies; diff > 10e-6; diff = X - cookies) {
                if (C >= diff) {
                    result += diff / rate;
                    cookies = X;
                    break;
                }

                result += (C - cookies) / rate;
                cookies = C;

                double t1 = X / (rate + F);
                double t2 = (X - C) / rate;

                if (t1 < t2) {
                    cookies = 0;
                    rate += F;
                } else {
                    result += t2;
                    cookies = X;
                    break;
                }
            }
        }

        ofs.precision(7);
        ofs << "Case #" << t << ": " << fixed << result << endl;
    }

    return 0;
}
