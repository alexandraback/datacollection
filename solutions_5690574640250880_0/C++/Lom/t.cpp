#include <algorithm>
#include <utility>

#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#include <iostream>


using namespace std;

pair<bool, vector<string>> tryWin(const vector<string>& m) {
    int R = m.size();
    int C = m[0].length();

    vector<string> mCheck = m;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (mCheck[i][j] == '.') {
                int bombs = 0;
                for (int v1 = -1; v1 < 2; ++v1) {
                    for (int v2 = -1; v2 < 2; ++v2) {
                        int p = v1 + i, q = v2 + j;
                        if (p > -1 && p < R && q > -1 && q < C && mCheck[p][q] == '*') {
                            ++bombs;
                        }
                    }
                }

                mCheck[i][j] = char('0' + bombs);
            }
        }
    }

    bool found = false;
    pair<int, int> foundP;
    for (int i = 0; !found && i < R; ++i) {
        for (int j = 0; !found && j < C; ++j) {
            if (mCheck[i][j] == '0') {
                found = true;
                foundP = make_pair(i, j);
            }
        }
    }

    if (!found) {
        return make_pair(false, vector<string>());
    } else {
        queue<pair<int, int>> q;
        q.push(foundP);
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            if (mCheck[p.first][p.second] == 'C') {
                mCheck[p.first][p.second] = 'c';
                continue;
            }

            for (int v1 = -1; v1 < 2; ++v1) {
                for (int v2 = -1; v2 < 2; ++v2) {
                    int x = v1 + p.first, y = v2 + p.second;
                    if (x > -1 && x < R && y > -1 && y < C
                        && mCheck[x][y] >= '0' && mCheck[x][y] <= '9')
                    {
                        mCheck[x][y] = (mCheck[x][y] == '0') ? 'c' : 'C';
                        q.push(make_pair(x, y));
                    }
                }
            }
        }

        bool ok = true;
        for (int i = 0; ok && i < R; ++i) {
            for (int j = 0; ok && j < C; ++j) {
                if (mCheck[i][j] != 'c' && mCheck[i][j] != '*') {
                    ok = false;
                }
            }
        }

        if (ok) {
            pair<bool, vector<string>> ans = make_pair(true, m);
            ans.second[foundP.first][foundP.second] = 'c';
            return ans;
        } else {
            return make_pair(false, vector<string>());
        }
    }
}

vector<string> fillCont(int R, int C, int M) {
    vector<string> m(R, string(C, '.'));

    int CL = (R < C) ? (min(C, M / R)) : C;
    for (int i = 0; i < R && M > 0; ++i) {
        for (int j = 0; j < ((i == R - 1) ? C : CL) && M > 0; ++j) {
            m[i][j] = '*';
            --M;
        }
    }

    return m;
}

vector<string> fillFlood(int R, int C, int M) {
    vector<string> m(R, string(C, '.'));

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    --M;
    m[0][0] = '*';
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int v1 = -1; M > 0 && v1 < 2; ++v1) {
            for (int v2 = -1; M > 0 && v2 < 2; ++v2) {
                int x = v1 + p.first, y = v2 + p.second;
                if (x > -1 && x < R && y > -1 && y < C && m[x][y] == '.') {
                    --M;
                    m[x][y] = '*';
                    q.push(make_pair(x, y));
                }
            }
        }
    }

    return m;
}

vector<string> fillSpiral(int R, int C, int M) {
    vector<string> m(R, string(C, '.'));
    int k = 0, l = 0;

    while (k < R && l < C && M > 0) {
        for (int i = l; M > 0 && i < C; ++i) {
            m[k][i] = '*';
            --M;
        }
        ++k;

        for (int i = k; M > 0 && i < R; ++i) {
            m[i][R-1] = '*';
            --M;
        }
        --C;

        if (k < R) {
            for (int i = C - 1; M > 0 && i >= l; --i) {
                m[R-1][i] = '*';
                --M;
            }
            --R;
        }

        if (l < C) {
            for (int i = R - 1; M > 0 && i >= k; --i) {
                m[i][l] = '*';
                --M;
            }
            ++l;
        }
    }

    return m;
}

int main(int argc, char* argv[]) {
    int numTests = 0;
    cin >> numTests;
    for (int test = 1; test <= numTests; ++test) {
        int R = 0, C = 0, M = 0;
        cin >> R >> C >> M;
        cout << "Case #" << test << ":" << endl;

        if (M == R * C - 1) {
            string s(C, '*');
            for (int i = 0; i < R - 1; ++i) {
                cout << s << endl;
            }

            s[0] = 'c';
            cout << s << endl;

            continue;
        }

        vector<string> m;
        pair<bool, vector<string>> ans;

        // m = fillCont(R, C, M);
        // ans = tryWin(m);
        // if (ans.first) {
        //     for (auto& s : ans.second) {
        //         cout << s << endl;
        //     }
        //     continue;
        // }

        // m = fillFlood(R, C, M);
        // ans = tryWin(m);
        // if (ans.first) {
        //     for (auto& s : ans.second) {
        //         cout << s << endl;
        //     }
        //     continue;
        // }

        // m = fillSpiral(R, C, M);

        // ans = tryWin(m);
        // if (ans.first) {
        //     for (auto& s : ans.second) {
        //         cout << s << endl;
        //     }
        //     continue;
        // }

        {
            string P = string(M, '*') + string(R * C - M, '.');
            sort(P.begin(), P.end());
            bool found = false;
            do {
                vector<string> m(R);
                for (int i = 0; i < R; ++i) {
                    m[i] = P.substr(i * C, C);
                }

                ans = tryWin(m);
                if (ans.first) {
                    for (auto& s : ans.second) {
                        cout << s << endl;
                    }

                    found = true;
                    break;
                }
            } while (next_permutation(P.begin(), P.end()));

            if (found) {
                continue;
            }
        }

        cout << "Impossible" << endl;
    }

    return 0;
}
