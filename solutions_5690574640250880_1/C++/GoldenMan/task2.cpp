#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool test_1_n_solver(int r, int c, int m) {
    if (r > 1 && c > 1) {
        return false;
    }
    int f = r * c - m;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (f == r * c - m) {
                cout << 'c';
            } else if (f == 0) {
                cout << '*';
            } else {
                cout << '.';
            }
            if (f) {
                --f;
            }
        }
        cout << endl;
    }
    return true;
}

void broke(int n, int &a, int &b, int ca, int cb) {
    a = b = -1;
    if (n == 1) {
        return;
    }
    if (n < ca) {
        b = 0;
        a = n;
        return;
    }
    if (n < cb) {
        b = n;
        a = 0;
        return;
    }
    if (n == 3) {
        return;
    }
    a = ca;
    n -= ca;
    b = n;
    if (b > cb) {
        a = b = -1;
    }
    return;
}

void make_ans(int r, int c, int m, int i_, int j_, int i__, int j__, int bi, int bj) {
    vector< vector<int> > mm(r);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            mm[i].push_back(0);
        }
    }
    for (int i = 0; i < i_; ++i) {
        for (int j = 0; j < j_; ++j) {
            mm[i][j] = 1;
        }
    }
    mm[0][0] = 2;
    for (int i = 0; i < i__; ++i) {
        for (int j = 0; j < j_; ++j) {
            mm[i + i_][j] = 1;
        }
    }
    for (int i = 0; i < j__; ++i) {
        for (int j = 0; j < i_; ++j) {
            mm[j][i + j_] = 1;
        }
    }
    for (int i = 0; i < bi; ++i) {
        mm[i][j_ + j__] = 1;
    }
    for (int i = 0; i < bj; ++i) {
        mm[i_ + i__][i] = 1;
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            switch (mm[i][j]) {
            case 0:
                cout << '*';
                break;
            case 1:
                cout << '.';
                break;
            case 2:
                cout << 'c';
                break;
            default:
                cerr << "PANIC!" << endl;
                break;
            }
        }
        cout << endl;
    }
}

bool test_n_m_solver(int r, int c, int m, int i_, int j_) {
    if (i_ < 2 || j_ < 2) {
        return false;
    }
    if (r < 2 || c < 2) {
        return false;
    }
    int f = r * c - m;
    f -= i_ * j_;
    int f_r = r - i_;
    int f_c = c - j_;
    for (int i = 0; i <= f_r; ++i) {
        for (int j = 0; j <= f_c; ++j) {
            if (i * j_ + j * i_ > f) {
                continue;
            }

            int can_insert = 0;
            if (i < f_r) {
                can_insert += j_;
            }
            if (j < f_c) {
                can_insert += i_;
            }
            int need_insert = f - i * j_ - j * i_;
            if (need_insert > can_insert) {
                continue;
            }
            int bi, bj;
            broke(need_insert, bi, bj, j < f_c ? i_ : 0, i < f_r ? j_ : 0);
            if (bi < 0) {
                continue;
            }
            make_ans(r, c, m, i_, j_, i, j, bi, bj);
            return true;
        }
    }
    return false;
}

bool test_c_solver(int r, int c, int m) {
    if (r * c - m == 1) {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (i == 0 && j == 0) {
                    cout << 'c';
                } else {
                    cout << '*';
                }
            }
            cout << endl;
        }
        return true;
    }
    return false;
}

void solve(int t) {
    int r, c, m;
    cin >> r >> c >> m;
    cout << "Case #" << t << ":" << endl;
    if (test_1_n_solver(r, c, m)) {
        return;
    }
    if (test_c_solver(r, c, m)) {
        return;
    }
    for (int i = 2; i <= r; ++i) {
        for (int j = 2; j <= c; ++j) {
            if (test_n_m_solver(r, c, m, i, j)) {
                return;
            }
        }
    }
    cout << "Impossible" << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
        cerr << "Test #" << i + 1 << " solved." << endl;
    }
    return 0;
}

