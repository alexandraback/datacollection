/*
 * Author: Václav Volhejn (IAmWave)
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
//typedef long long ll;

const bool distribute = true;

const int values[4][4] = {{0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 0, 1}, {3, 2, 1, 0}};
const bool minuses[4][4] = {{0, 0, 0, 0}, {0, 1, 0, 1}, {0, 1, 1, 0}, {0, 0, 1, 1}};

int toInt(char c) {
    if(c == 'i') return 1;
    if(c == 'j') return 2;
    if(c == 'k') return 3;
}

void solve(istream *in, ostream *out) {
    int cases;
    *in >> cases;
    rep(caseI, 0, cases) {
        *out << "Case #" << (caseI + 1) << ": ";

        int l;
        unsigned long long x;
        *in >> l >> x;
        string t;
        *in >> t;
        string s = "";

        rep(i, 0, min(x, 8ull)) s += t;
        int n = s.size();
        bool hasMinus[n + 1];
        int total[n + 1];
        hasMinus[0] = false;
        total[0] = 0;
        int found = 0;
        rep(i, 1, n + 1) {
            total[i] = values[total[i - 1]][toInt(s[i - 1])];
            hasMinus[i] = hasMinus[i - 1] xor minuses[total[i - 1]][toInt(s[i - 1])];

            if((found == 0) && (total[i] == 1) && (!hasMinus[i])) found++;
            if((found == 1) && (total[i] == 3) && (!hasMinus[i])) found++;
        }
        /*cout << endl;
        rep(i, 1, n + 1) cout << total[i];
        cout << endl;
        rep(i, 1, n + 1) cout << hasMinus[i];
        cout << endl;*/
        if(x < 8) {
            if((total[n] != 0) || (!hasMinus[n])) {
                *out << "NO" << endl;
                continue;
            }
        } else {
            if((!hasMinus[l * 2]) && (!total[l * 2])) { //vyhodnoti se do -1
                if((x % 2) != 1) {
                    *out << "NO" << endl;
                    continue;
                }
            } else { //zbytek se musi vyhodnotit do -1
                if((x % 4) != 2) {
                    *out << "NO" << endl;
                    continue;
                }
            }
        }
        if(found == 2)
            *out << "YES" << endl;
        else
            *out << "NO" << endl;
    }
}

int main() {
    ostream *out;
    istream *in = new ifstream("C-large.in");
    out = &cout;
    if (distribute) out = new ofstream("out.txt");
    solve(in, out);
    return 0;
}
