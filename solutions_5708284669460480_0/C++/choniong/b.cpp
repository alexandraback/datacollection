#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
using namespace std;

int k, l, s;
string key, tar;

double cou;
double tim;
double mcou;

int cal_cou(string str) {
    int cc = 0;
    for (int i = 0; i < str.length() - l + 1; ++i) {
        if (str.substr(i, l) == tar) {
            ++cc;
        }
    }
    return cc;
}

string tmp;
void loop(int lv) {
    if (lv < s) {
        for (int i = 0; i < k; ++i) {
            tmp[lv] = key[i];
            loop(lv + 1);
        }
    } else {
        ++tim;
        int cc = cal_cou(tmp);
        cou += cc;
        if (cc > mcou) {
            mcou = cc;
        }
    }
}

int main () {
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {

        cin >> k >> l >> s;
        cin >> key >> tar;

        tmp = string(s, ' ');
        cou = 0;
        mcou = 0;
        tim = 0;

        loop(0);

        double ecp = cou / tim;

        printf("Case #%d: %lf\n", tt, mcou - ecp);

    }

    return 0;
}
