#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

string str, resc, resj;
int len, df;

int s2i(string s) {
    stringstream ss;
    ss << s;
    int res;
    ss >> res;
    return res;
}

void dfs(int idx) {
    if (idx == len) {
        string s1 = str.substr(0, len / 2);
        string s2 = str.substr(len / 2);
        int score1 = s2i(s1);
        int score2 = s2i(s2);
        int d = abs(score1 - score2);
        if (d < df) {
            df = d;
            resc = s1;
            resj = s2;
        }
        else if (d == df) {
            if (s1 < resc) {
                resc = s1;
                resj = s2;
            }
            else if (s1 == resc) {
                resj = min(resj, s2);
            }
        }
        return;
    }
    if (str[idx] != '?') dfs(idx + 1);
    else {
        for (char ch = '0'; ch <= '9'; ++ch) {
            str[idx] = ch;
            dfs(idx + 1);
        }
        str[idx] = '?';
    }
}

void run() {
    string c, j;
    cin >> c >> j;
    str = c + j;
    len = str.length();
    df = 1000000000;
    dfs(0);
    cout << resc << " " << resj << endl;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
