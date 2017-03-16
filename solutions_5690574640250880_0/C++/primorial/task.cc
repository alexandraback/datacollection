#include <iostream>
#include <sstream> 
#include <cstdio>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdlib> 
#include <ctime>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
template<typename T> T ABS(const T& val) { return val < 0 ? -val : val; }

void dfs(int i, int j, const vector<string>& ans, vector<vector<char> >& used)
{
    if (used[i][j])
        return;
    used[i][j] = true;

    bool mine = false;
    for (int iter = 0; iter < 2; ++iter) {

        for (int di = -1; di < 2; ++di) {
            if (i + di < 0 || i + di >= ans.size())
                continue;

            for (int dj = -1; dj < 2; ++dj) {
                if (j + dj < 0 || j + dj >= ans[i].size() || (! di && !dj))
                    continue;

                if (iter && ! mine) {
                    dfs(i + di, j + dj, ans, used);                    
                } else if (!iter) {
                    mine = mine || ('*' == ans[i + di][j + dj]);
                }
            }
        }

    }
}

bool check(const vector<string>& ans, int M, int E)
{
    vector<vector<char> > used(ans.size(), vector<char>());
    int si, sj;

    for (int i = 0; i < ans.size(); ++i) {
        used[i].assign(ans[i].size(), false);

        size_t pos = ans[i].find('c');
        if (pos != string::npos) {
            si = i;
            sj = pos;
        }
    }

    dfs(si, sj, ans, used);

    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            if (!used[i][j] && (ans[i][j] == 'c' || ans[i][j] == '.'))
                return false;
            if (ans[i][j] == '*')
                --M;
            else
                --E;
        }
    }

    return M == 0 && E == 0;
}

int main ()
{
    std::ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int test = 1; test <= T; ++test) {
        cout << "Case #" << test << ":\n";
        int R, C, M;
        cin >> R >> C >> M;
        int empty = R * C - M;
        vector<string> ans(R, string());
        int mcheck = M;
        int echeck = empty;

        if (empty == 1) {
            for (int i = 0; i < R; ++i) {
                ans[i].resize(C);
                fill(ans[i].begin(), ans[i].end(), '*');
            }

            ans[0][0] = 'c';
        } else if (empty >= 2 * C + 2 * R - 4) {
            for (int i = 0; i < R; ++i) {
                for (int j = 0; j < C; ++j) {
                    if (j < C - 2 && i < R - 2 && M > 0) {
                        ans[i].push_back('*');
                        --M;
                    } else {
                        ans[i].push_back('.');
                    }
                }
            }

            ans[R - 1][C - 1] = 'c';
        } else if (empty >= 8 && R >= 3 && C >= 3 && empty < 2 * C + 2 * R - 4 ) {
            for (int i = 0; i < R; ++i) {
                ans[i].resize(C);
                fill(ans[i].begin(), ans[i].end(), '*');
            }

            ans[0][0] = 'c';
            ans[0][1] = '.';
            ans[0][2] = '.';
            ans[1][0] = '.';
            ans[1][1] = '.';
            ans[1][2] = '.';
            ans[2][0] = '.';
            ans[2][1] = '.';
            empty -= 8;

            if (empty & 1) {
                ans[2][2] = '.';
                --empty;
            }

            for (int i = 3; i < R && empty; ++i) {
                ans[i][0] = '.';
                ans[i][1] = '.';
                empty -= 2;
            }

            for (int i = 3; i < C && empty; ++i) {
                ans[0][i] = '.';
                ans[1][i] = '.';
                empty -= 2;
            }
        } else if (empty % 2 == 0 && empty >= 4) {
            for (int i = 0; i < R; ++i) {
                if (empty >= C && (empty - C != 1) && (empty / C >= 2 || i > 0)) {
                    for (int j = 0; j < C; ++j) {
                        ans[i].push_back('.');
                    }

                    empty -= C;
                } else if (i == 0 || (empty >= C)) {
                    for (int j = 0; j < C; ++j) {
                        if (j < empty / 2 || (R == 1 && j < empty)) {
                            ans[i].push_back('.');
                        } else {
                            ans[i].push_back('*');
                        }
                    }

                    if (R != 1)
                        empty /= 2;
                    else
                        empty = 0;
                } else {
                    for (int j = 0; j < C; ++j) {
                        if (j < empty) {
                            ans[i].push_back('.');
                        } else {
                            ans[i].push_back('*');
                        }
                    }

                    empty = 0;
                }
            }

            ans[0][0] = 'c';
        } else if (empty % R == 0 && (empty / R > 1 || empty == 1)) {
            for (int i = 0; i < R; ++i) {
                for (int j = 0; j < C; ++j) {
                    if (j < empty / R) {
                        ans[i].push_back('.');
                    } else {
                        ans[i].push_back('*');
                    }
                }
            }

            ans[0][0] = 'c';
        } else if (empty % C == 0 && (empty / C > 1 || empty == 1)) {
            for (int i = 0; i < R; ++i) {
                for (int j = 0; j < C; ++j) {
                    if (i < empty / C) {
                        ans[i].push_back('.');
                    } else {
                        ans[i].push_back('*');
                    }
                }
            }

            ans[0][0] = 'c';
        } else {
            ans.clear();
        }

        if (ans.empty()) {
            cout << "Impossible\n";
        } else {
            if (!check(ans, mcheck, echeck)) {
                cout << "ERROR" << endl;
                assert(false);
            }

            for (int i = 0; i < R; ++i) {
                cout << ans[i] << "\n";
            }
        }
    }
    return 0;
}
