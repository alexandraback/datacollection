#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

typedef long double ld;

int n, s;
vector<int> v;
vector<ld> a;

inline bool check(ld cur, int num) {
        ld ms = v[num] + cur * s;
        cur = 1.0 - cur;
        for (int i = 0; i < n; ++i) {
                if (i == num) continue;
                ld t = (ms - v[i]) / s;
                if (t <= 0) continue;
                cur -= t;
        }
        return (cur <= 0);
}

int main() {
        int tt;
        in >> tt;
        for (int t = 0; t < tt; ++t) {
                out << "Case #" << t + 1 << ": ";

                v.clear();
                in >> n; 
                v.resize(n);

                s = 0;
                for (int i = 0; i < n; ++i) {
                        in >> v[i];
                        s += v[i];
                }


                for (int i = 0; i < n; ++i) {
                        double l = 0.0, r = 1.0;
                        for (int j = 0; j < 50; ++j) {
                                double mid = (l + r) / 2.0;
                                if (check(mid, i)) r = mid;
                                else l = mid;
                        }
                        out << fixed << setprecision(8) << l * 100.0 << " ";
                }
                out << endl;
        }

                    
        return 0;
}
