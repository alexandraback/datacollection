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

const int N = 25;

int n, s;
vector<int> v;
vector<int> a1, a2;
bool f;

void rec(int x) {
        if (f) return;
        if (s == 0 && !a1.empty() && !a2.empty()) {
                for (int i = 0; i < a1.size(); ++i) out << a1[i] << " ";
                out << endl;
                for (int i = 0; i < a2.size(); ++i) out << a2[i] << " ";
                out << endl;
                f = true;
                return;
        }
        if (x == n) {
                return;
        }
        s += v[x];
        a1.push_back(v[x]);
        rec(x + 1);
        s -= v[x];
        a1.pop_back();

        s -= v[x];
        a2.push_back(v[x]);
        rec(x + 1);
        s += v[x];
        a2.pop_back();

        rec(x + 1);
}

int main() {
        ios_base::sync_with_stdio(0);

        int tt;
        in >> tt;
        for (int t = 1; t <= tt; ++t) {
                out << "Case #" << t << ":\n";

                in >> n;
                v.clear();
                v.resize(n);
                for (int i = 0; i < n; ++i) {
                        in >> v[i];
                }
                s = 0;
                f = false;
                a1.clear();
                a2.clear();
                rec(0);
                if (!f) out << "Imossible\n";
        }

                    
        return 0;
}
