#include <bits/stdc++.h>
#define INF (LLONG_MAX - 2)
using namespace std;
string c, jamm;

long long lowestScore[20][10][10][2];
pair<long long, long long> vals[20][10][10][2];

long long getScore(int a, int b, int index, int pos) {
    if (index == 0) {
        vals[index][a][b][pos] = make_pair(a, b);
        return a - b;
    }
    long long min = INF;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int p = 0; p < 2; p++) {
                if (lowestScore[index - 1][i][j][p] != INF) {
                    long long tmp = lowestScore[index - 1][i][j][p] * 10LL 
                        + (long long)(a - b);
                    pair<long long, long long> tmp2 = make_pair(
                            vals[index - 1][i][j][p].first * 10LL + a,
                            vals[index - 1][i][j][p].second * 10LL + b);
                    if (((pos == 0 && tmp <= 0) || (pos == 1 && tmp >= 0)) 
                        && (abs(tmp) < abs(min) || (abs(tmp) == abs(min) && vals[index][a][b][pos] > tmp2))) {
                        min = tmp;
                        vals[index][a][b][pos] = tmp2;
                    }

                }
            }
        }
    }
    return min;
}

int main() {
    long long test;
    cin >> test;
    for (long long t = 1; t <= test; t++) {
        cin >> c >> jamm;
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    for (int p = 0; p < 2; p++)
                    lowestScore[i][j][k][p] = INF;
                }
            }
        }


        for (unsigned long long index = 0; index < c.size(); index++) {
            if (c[index] == '?' && jamm[index] == '?') {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        for (int p = 0; p < 2; p++) {
                            lowestScore[index][i][j][p] = getScore(i, j, index, p);
                        }
                    }
                }
            } else if (c[index] == '?') {
                for (int i = 0; i < 10; i++) {
                    for (int p = 0; p < 2; p++) {
                        lowestScore[index][i][(int)(jamm[index] - '0')][p] = 
                            getScore(i, jamm[index] - '0', index, p);
                    }
                }
            } else if (jamm[index] == '?') {
                for (int i = 0; i < 10; i++) {
                    for (int p = 0; p < 2; p++) {
                        lowestScore[index][(int)(c[index] - '0')][i][p] = 
                            getScore(c[index] - '0', i, index, p);
                    }
                }
            } else {
                lowestScore[index][(int)(c[index] - '0')]
                [(int)(jamm[index] - '0')][0]
                    = getScore(c[index] - '0', jamm[index] - '0', index, 0);
                lowestScore[index][(int)(c[index] - '0')]
                [(int)(jamm[index] - '0')][1]
                    = getScore(c[index] - '0', jamm[index] - '0', index, 1);
            }
        }
        long long min = INF;
        pair<long long, long long> maxP;
        for (int j = 0; j < 10; j++) {
            for (int i = 0; i < 10; i++) {
                for (int p = 0; p < 2; p++) {
                    if (lowestScore[c.size() - 1][i][j][p] != INF 
                        && (abs(lowestScore[c.size() - 1][i][j][p]) < abs(min)
                        || (abs(lowestScore[c.size() - 1][i][j][p]) == abs(min) && maxP > vals[c.size() - 1][i][j][p]))) {
                        min = lowestScore[c.size() - 1][i][j][p];
                        maxP = vals[c.size() - 1][i][j][p];
                    }
                }
            }
        }
        cout << "Case #" << t << ": " << setw(c.size()) << setfill('0') << maxP.first << " " << setw(c.size()) << setfill('0') << maxP.second << endl;

        // for (int i = 0; i < stringss.size(); i++) {
        //     cout << stringss[i].first << endl;
        // }
        // for (int index = 0; index < c.size(); index++) {
        //     for (int i = 0; i < 10; i++) {
        //         for (int j = 0; j < 10; j++) {
        //             if (lowestScore[index][i][j][0] == INF) {
        //                 cout << "- "; continue;
        //             }
        //             cout << lowestScore[index][i][j][1] << " ";
        //         }
        //         cout << endl;
        //     }
        //     cout << endl << endl;
        // }
    }
}