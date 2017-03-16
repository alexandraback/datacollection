#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <cmath>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;

void update_result(const string& c, const string& j, string& cr, string& jr, int64_t& diff) {
    // cout << c << " " << j << " " << cr << " " << jr << " " << diff << endl;
    if (abs(stoll(c) - stoll(j)) < diff || (abs(stoll(c) - stoll(j)) == diff && (c < cr || (c == cr && j < jr)))) {
        cr = c;
        jr = j;
        diff = abs(stoll(c) - stoll(j));
    }
}

// filling mode is either -1 (first is less), 0, 1 (first is greater)
void process(string& c, string& j, int64_t pos, string& cr, string& jr, int64_t& diff, int64_t filling_mode)
{
    if (pos == c.size()) {
        update_result(c, j, cr, jr, diff);
    }
    else {
        bool cqm = c[pos] == '?', jqm = j[pos] == '?';

        if (c[pos] == j[pos] && c[pos] != '?') {
            process(c, j, pos+1, cr, jr, diff, filling_mode);
        }
        else if (filling_mode == 1) {
            if (cqm)
                c[pos] = '0';
            if (jqm)
                j[pos] = '9';
            process(c, j, pos + 1, cr, jr, diff, filling_mode);
        }
        else if (filling_mode == -1) {
            if (cqm)
                c[pos] = '9';
            if (jqm)
                j[pos] = '0';
            process(c, j, pos+1, cr, jr, diff, filling_mode);
        }
        else {
            if (!cqm && !jqm && c[pos] > j[pos]) {
                process(c, j, pos+1, cr, jr, diff, 1);
            }
            else if (!cqm && !jqm && c[pos] < j[pos]) {
                process(c, j, pos+1, cr, jr, diff, -1);
            }
            else if (cqm && jqm) {
                c[pos] = '0';
                j[pos] = '0';
                process(c, j, pos+1, cr, jr, diff, 0);

                c[pos] = '0';
                j[pos] = '1';
                process(c, j, pos+1, cr, jr, diff, -1);

                c[pos] = '1';
                j[pos] = '0';
                process(c, j, pos+1, cr, jr, diff, 1);
            }
            else if (cqm && !jqm) {
                c[pos] = j[pos];
                process(c, j, pos+1, cr, jr, diff, 0);

                if (j[pos] != '9') {
                    c[pos] = j[pos] + 1;
                    process(c, j, pos+1, cr, jr, diff, 1);
                }

                if (j[pos] != '0') {
                    c[pos] = j[pos] - 1;
                    process(c, j, pos+1, cr, jr, diff, -1);
                }
            }
            else if (jqm && !cqm) {
                j[pos] = c[pos];
                process(c, j, pos+1, cr, jr, diff, 0);

                if (c[pos] != '9') {
                    j[pos] = c[pos] + 1;
                    process(c, j, pos+1, cr, jr, diff, -1);
                }

                if (c[pos] != '0') {
                    j[pos] = c[pos] - 1;
                    process(c, j, pos+1, cr, jr, diff, 1);
                }
            }
            else {
                assert(false);
            }
        }
        if (cqm)
            c[pos] = '?';
        if (jqm)
            j[pos] = '?';
    }
    /*if (startc < startj) {
        advance_c(c, j, startc, startj, cr, jr, diff);
    }
    else if (startj < startc) {
        advance_j(c, j, startc, startj, cr, jr, diff);
    }
    else if (startc == c.length()) {
        update_result(c, j, cr, jr, diff);
    }
    else {
        advance_c(c, j, startc, startj, cr, jr, diff);
    }*/
}

void test(int case_n) {
    string c, j, cr, jr;
    cin >> c >> j;
    int64_t diff = 1e18;
    process(c, j, 0, cr, jr, diff, 0);
    cout << "Case #" << case_n << ": " << cr << " " << jr << endl;
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        test(i+1);
}
