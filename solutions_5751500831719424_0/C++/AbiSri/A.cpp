#include <iostream>
#include <iomanip>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <fstream>
using namespace std;

int t, n;
string s[100];

int main() {
    ifstream fin("A.in");
    ofstream fout("A.out");
    fin >> t;
    for (int k = 0; k < t; k++) {
        fout << "Case #" << k + 1 << ": ";
        fin >> n;
        for (int i = 0; i < n; i++) {
            fin >> s[i];
        }
        vector<pair<char, int> > v[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < s[i].length();) {
                char c = s[i][j];
                int len = 1;
                while ((j + len) < s[i].length() && s[i][j + len] == c) len++;
                v[i].push_back(make_pair(c, len));
                j += len;
            }
        }

        int s = v[0].size();
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (v[i].size() != s) {
                flag = true;
                break;
            }
        }

        if (flag) {
            fout << "Fegla Won" << endl;
            continue;
        }

        int moves = 0, bound = 0, temp, temp2 = 99999999;

        for (int i = 0; i < v[0].size(); i++) {
            temp = 0;
            temp2 = 999999999;
            for (int j = 0; j < n; j++) {
                if (v[j][i].first != v[0][i].first) {
                    flag = true;
                    break;
                }
                bound = max(bound, v[j][i].second);
            }
            if (flag) {
                fout << "Fegla Won" << endl;
                break;
            }

            for (int j = 1; j <= bound; j++) {
                temp = 0;
                for (int l = 0; l < n; l++) {
                    temp += abs(j - v[l][i].second);
                }
                temp2 = min(temp2, temp);
            }
            moves += temp2;
        }
        if (!flag) {
            fout << moves << endl;
        }
    }
}
