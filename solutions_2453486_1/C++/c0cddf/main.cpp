#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define ll long long
#define point pair<double, double>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define uint unsigned int
#define double long double
#define merge botva
#define M_PI 3.14159265358979323846

const int maxn = 3000020, maxt = 100020, INF = 1200000000;

int hasdot;
int ended;
int gi;

void tryv(string s) {
        if (ended) return;
        int h1 = 0, h2 = 0, h3 = 0;
        for (int j = 0; j < s.size(); ++j) {
                if (s[j] == '.') hasdot = 1;
                h1 += (s[j] == 'X');
                h2 += (s[j] == 'O');
                h3 += (s[j] == 'T');
        }
        if (h1 + h3 == 4) {
                ended = 1;
                printf("Case #%d: X won\n", gi);
        }
        if (h2 + h3 == 4) {
                ended = 1;
                printf("Case #%d: O won\n", gi);
        }
}

int main() {
        //freopen("ellipse.in", "r", stdin);
        //freopen("ellipse.out", "w", stdout);

        int t;
        scanf("%d\n", &t);
        string s[5];
        for (gi = 1; gi <= t; ++gi) {
                hasdot = 0;
                ended = 0;
                for (int j = 0; j < 4; ++j) {
                        getline(cin, s[j]);
                        //cout << s[j] << endl;
                }
                //cout << "===\n";
                for (int j = 0; j < 4; ++j) {
                        tryv(s[j]);
                        tryv(string("") + s[0][j] + s[1][j] + s[2][j] + s[3][j]);
                }
                tryv(string("") + s[0][0] + s[1][1] + s[2][2] + s[3][3]);
                tryv(string("") + s[3][0] + s[2][1] + s[1][2] + s[0][3]);
                if (!ended) {
                        printf("Case #%d: ", gi);
                        printf(hasdot ? "Game has not completed\n" : "Draw\n");
                }
                getline(cin, s[0]);
        }
}
