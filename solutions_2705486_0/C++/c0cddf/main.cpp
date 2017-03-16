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
//#define double long double
#define merge botva
#define M_PI 3.14159265358979323846

const int maxn = 531196, maxt = 100020, INF = 1200000000;

#define big pair<int, string>
#define mp make_pair
#define y second

int n, m;
int a[maxn];
string s[maxn];
int dp[7][4100];

int main() {
        freopen("dict.txt", "r", stdin);
        int dlen;
        scanf("%d\n", &dlen);
        for (int i = 0; i < dlen; ++i)
                cin >> s[i];
        //freopen("ellipse.out", "w", stdout);
        fclose(stdin);
        freopen("a.in", "r", stdin);
        int t;
        cin >> t;
        for (int gi = 0; gi < t; ++gi) {
                string S;
                cin >> S;
                //cout << S <<"!\n";
                for (int j = 0; j < 7; ++j)
                        for (int i = 0; i <= S.size(); ++i)
                                dp[j][i] = INF;
                dp[6][0] = 0;
                //cout << "dlen is " << dlen << endl;
                for (int i = 0; i < S.size(); ++i) {
                        for (int last = 0; last < 7; ++last)
                                if (dp[last][i] < INF) {
                                        //cout << last << ", " << i << " : " << dp[last][i] << endl;
                                        for (int j = 0; j < dlen; ++j)
                                        if (i + s[j].size() <= S.size()) {
                                                int llast = 6, bad = 0, hm = 0, rlast = -500;
                                                //if (s[j] == "code") cout << "YOOO\n";
                                                for (int k = 0; k < s[j].size(); ++k)
                                                        if ((S[i + k]) != (s[j][k])) {
                                                                if (last + k < 5 || k - rlast < 5) {
                                                                        bad = 1; break;
                                                                }
                                                                ++hm;
                                                                rlast = k;
                                                                llast = s[j].size() - k;
                                                        }
                                                if (!bad) {
                                                        llast = min(llast, 6);
                                                        dp[llast][i + s[j].size()] = min(dp[llast][i + s[j].size()], dp[last][i] + hm);
                                                }
                                        }
                                }
                        //cout << i << ".\n";
                }
                int minf = INF;
                for (int i = 0; i < 7; ++i)
                        minf = min(minf, dp[i][S.size()]);
                printf("Case #%d: %d\n", gi + 1, minf);
               
        }
}
