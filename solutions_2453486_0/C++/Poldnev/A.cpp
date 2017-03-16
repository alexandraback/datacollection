#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <iomanip>

using namespace std;

#define pb push_back

ifstream in("A-small-attempt0.in");
ofstream out("output.txt");

const int n = 4;

int main()
{
    int t;
    in >> t;
    for (int z = 0; z < t; ++z) {
        vector<string> a(n);
        int dots = 0;
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            for (int j = 0; j < n; ++j) {
                dots += (a[i][j] == '.');
            }
        }
        char d = 'T';
        for (char c: {'X', 'O'}) {
            for (int i = 0; i < n; ++i) {
                bool all = true;
                for (int j = 0; j < n; ++j) {
                    if (a[i][j] != c && a[i][j] != d) {
                        all = false;
                        break;
                    }
                }
                if (all) {
                    d = c;
                    break;
                }
            }
            if (d != 'T') {
                break;
            }
            for (int i = 0; i < n; ++i) {
                bool all = true;
                for (int j = 0; j < n; ++j) {
                    if (a[j][i] != c && a[j][i] != d) {
                        all = false;
                        break;
                    }
                }
                if (all) {
                    d = c;
                    break;
                }
            }
            if (d != 'T') {
                break;
            }
            bool all = true;
            for (int i = 0; i < n; ++i) {
                if (a[i][i] != c && a[i][i] != d) {
                    all = false;
                    break;
                }
            }
            if (all) {
                d = c;
                break;
            }
            all = true;
            for (int i = 0; i < n; ++i) {
                if (a[i][n - 1 - i] != c && a[i][n - 1 - i] != d) {
                    all = false;
                    break;
                }
            }
            if (all) {
                d = c;
                break;
            }
        }

        string res;
        if (d != 'T') {
            res = d + string(" won");
        } else if (dots == 0) {
            res = "Draw";
        } else {
            res = "Game has not completed";
        }
        out << "Case #" << z + 1 << ": " << res << endl;
    }

    return 0;
}
