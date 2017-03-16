#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <cmath>
#include <cstdlib>
#include <set>
#include <algorithm>
using namespace std;

void process(string& c, string& j, int startc, int startj, string& cr, string& jr, int& diff);

void advance_c(string& c, string& j, int startc, int startj, string& cr, string& jr, int& diff) {
    if (c[startc] == '?') {
        for (char ch = '0'; ch <= '9'; ch++) {
            c[startc] = ch;
            process(c, j, startc+1, startj, cr, jr, diff);
        }
        c[startc] = '?';
    }
    else {
        process(c, j, startc+1, startj, cr, jr, diff);
    }
}

void advance_j(string& c, string& j, int startc, int startj, string& cr, string& jr, int& diff) {
    if (j[startj] == '?') {
        for (char ch = '0'; ch <= '9'; ch++) {
            j[startj] = ch;
            process(c, j, startc, startj+1, cr, jr, diff);
        }
        j[startj] = '?';
    }
    else {
        process(c, j, startc, startj+1, cr, jr, diff);
    }
}

string cr, jr;
int diff = 2000000000;

void update_result(const string& c, const string& j, string& cr, string& jr, int& diff) {
    //cout << c << " " << j << " " << cr << " " << jr << " " << diff << endl;
    if (abs(stoi(c) - stoi(j)) < diff || (abs(stoi(c) - stoi(j)) == diff && (c < cr || (c == cr && j < jr)))) {
        cr = c;
        jr = j;
        diff = abs(stoi(c) - stoi(j));
    }
}

void process(string& c, string& j, int startc, int startj, string& cr, string& jr, int& diff)
{
    if (startc < startj) {
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
    }
}

void test(int case_n) {
    string c, j, cr, jr;
    cin >> c >> j;
    int diff = 2000000000;
    process(c, j, 0, 0, cr, jr, diff);
    cout << "Case #" << case_n << ": " << cr << " " << jr << endl;
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        test(i+1);
}
