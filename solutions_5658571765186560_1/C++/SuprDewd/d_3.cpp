#include "../../lib/include.h"


struct union_find {
    vi p; union_find(int n) : p(n, -1) { }
    int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
    bool unite(int x, int y) {
        int xp = find(x), yp = find(y);
        if (xp == yp) return false;
        if (p[xp] < p[yp]) p[xp] += p[yp], p[yp] = xp;
        else p[yp] += p[xp], p[xp] = yp;
        return true; }
    int size(int x) { return -p[find(x)]; } };

typedef vector<vector<bool> > board;
// vector<board> polynomios;
vector<board> polynomios[10];

board trim(board b) {
    int n = size(b),
        m = size(b[0]);

    int x0 = 0,
        x1 = size(b) - 1,
        y0 = 0,
        y1 = size(b[0]) - 1;

    while (x0 < x1) {
        bool empty = true;
        for (int i = 0; i < m; i++) {
            if (b[x0][i]) {
                empty = false;
            }
        }

        if (!empty)
            break;
        x0++;
    }

    while (x0 < x1) {
        bool empty = true;
        for (int i = 0; i < m; i++) {
            if (b[x1][i]) {
                empty = false;
            }
        }

        if (!empty)
            break;
        x1--;
    }

    while (y0 < y1) {
        bool empty = true;
        for (int i = 0; i < n; i++) {
            if (b[i][y0]) {
                empty = false;
            }
        }

        if (!empty)
            break;
        y0++;
    }

    while (y0 < y1) {
        bool empty = true;
        for (int i = 0; i < n; i++) {
            if (b[i][y1]) {
                empty = false;
            }
        }

        if (!empty)
            break;
        y1--;
    }

    int nn = x1 - x0 + 1,
        mm = y1 - y0 + 1;
    board res(nn, vector<bool>(mm));
    for (int i = 0; i < nn; i++) {
        for (int j = 0; j < mm; j++) {
            res[i][j] = b[i + x0][j + y0];
        }
    }

    return res;
}

board flip(board b) {
    int n = size(b),
        m = size(b[0]);

    board res(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = b[n - i - 1][j];
        }
    }

    return res;
}

board rot(board b) {
    int n = size(b),
        m = size(b[0]);

    board res(m, vector<bool>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = b[j][m - i - 1];
        }
    }

    return res;
}

bool equal(const board &a, const board &b) {
    if (size(a) != size(b) ||
        size(a[0]) != size(b[0])) {
        return false;
    }

    int n = size(a),
        m = size(a[0]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool same(board a, board b) {
    int an = size(a),
        am = size(a[0]),
        bn = size(b),
        bm = size(b[0]);

    if (!(an == bn && am == bm) &&
        !(an == bm && am == bn))
        return false;

    for (int flips = 0; flips < 2; flips++) {
        for (int rots = 0; rots < 4; rots++) {
            if (equal(a, b)) {
                return true;
            }

            a = rot(a);
        }
        a = flip(a);
    }

    return false;
}

// void bt(board &b, int x, int y, int left) {
//     int n = size(b),
//         m = size(b[0]);
// 
//     if (y >= n) {
//         bt(b, x + 1, 0, left);
//         return;
//     }
// 
//     if (left == 0) {
// 
//         bool anyleft = false;
//         for (int i = 0; i < n; i++) {
//             if (b[i][0]) {
//                 anyleft = true;
//             }
//         }
// 
//         if (!anyleft) {
//             return;
//         }
// 
//         union_find uf(n * m);
//         int p = -1,
//             q = -1,
//             total = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (b[i][j]) {
//                     p = i;
//                     q = j;
//                     total++;
// 
//                     for (int di = -1; di <= 1; di++) {
//                         for (int dj = -1; dj <= 1; dj++) {
//                             if ((di == 0) == (dj == 0))
//                                 continue;
// 
//                             int ci = i + di,
//                                 cj = j + dj;
// 
//                             if (0 <= ci && ci < n && 0 <= cj && cj < m && b[ci][cj]) {
//                                 uf.unite(i * m + j, ci * m + cj);
//                             }
//                         }
//                     }
// 
//                 }
//             }
//         }
// 
//         assert(p != -1 && q != -1);
//         assert(b[p][q]);
//         bool added = false;
//         if (uf.size(p * m + q) == total) {
//             bool any = false;
//             board cur = trim(b);
//             for (int i = 0; i < size(polynomios); i++) {
//                 if (same(polynomios[i], cur)) {
//                     any = true;
//                     break;
//                 }
//             }
// 
//             if (!any) {
//                 added = true;
//                 polynomios.push_back(cur);
//                 // cout << "yup" << endl;
//                 // cout << "trying" << endl;
//                 for (int g = 0; g < n; g++) {
//                     for (int h = 0; h < m; h++) {
//                         if (b[g][h]) {
//                             cout << "#";
//                         } else {
//                             cout << ".";
//                         }
//                     }
//                     cout << endl;
//                 }
//                 cout << endl;
//             }
//         }
// 
//         if (!added) {
//             // cout << "nope" << endl;
//         }
//     }
// 
//     if (x >= n) {
//         return;
//     }
// 
//     if (x == 1 && y == 0) {
//         bool any = false;
//         for (int i = 0; i < m; i++) {
//             if (b[0][i]) {
//                 any = true;
//             }
//         }
// 
//         if (!any) {
//             return;
//         }
//     }
// 
//     bt(b, x, y + 1, left);
//     b[x][y] = true;
//     bt(b, x, y + 1, left - 1);
//     b[x][y] = false;
// }


bool handle_solution(vi rows) { return true; }
struct exact_cover {
    struct node {
        node *l, *r, *u, *d, *p;
        int row, col, size;
        node(int _row, int _col) : row(_row), col(_col) {
            size = 0; l = r = u = d = p = NULL; }
    };
    int rows, cols, *sol;
    bool **arr;
    node *head;
    exact_cover(int _rows, int _cols) : rows(_rows), cols(_cols), head(NULL) {
        arr = new bool*[rows];
        sol = new int[rows];
        for (int i = 0; i < rows; i++)
            arr[i] = new bool[cols], memset(arr[i], 0, cols);
    }
    void set_value(int row, int col, bool val = true) { arr[row][col] = val; }
    void setup() {
        node ***ptr = new node**[rows + 1];
        for (int i = 0; i <= rows; i++) {
            ptr[i] = new node*[cols];
            for (int j = 0; j < cols; j++)
                if (i == rows || arr[i][j]) ptr[i][j] = new node(i, j);
                else ptr[i][j] = NULL;
        }
        for (int i = 0; i <= rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!ptr[i][j]) continue;
                int ni = i + 1, nj = j + 1;
                while (true) {
                    if (ni == rows + 1) ni = 0;
                    if (ni == rows || arr[ni][j]) break;
                    ++ni;
                }
                ptr[i][j]->d = ptr[ni][j];
                ptr[ni][j]->u = ptr[i][j];
                while (true) {
                    if (nj == cols) nj = 0;
                    if (i == rows || arr[i][nj]) break;
                    ++nj;
                }
                ptr[i][j]->r = ptr[i][nj];
                ptr[i][nj]->l = ptr[i][j];
            }
        }
        head = new node(rows, -1);
        head->r = ptr[rows][0];
        ptr[rows][0]->l = head;
        head->l = ptr[rows][cols - 1];
        ptr[rows][cols - 1]->r = head;
        for (int j = 0; j < cols; j++) {
            int cnt = -1;
            for (int i = 0; i <= rows; i++)
                if (ptr[i][j]) cnt++, ptr[i][j]->p = ptr[rows][j];
            ptr[rows][j]->size = cnt;
        }
        for (int i = 0; i <= rows; i++) delete[] ptr[i];
        delete[] ptr;
    }
    #define COVER(c, i, j) \
        c->r->l = c->l, c->l->r = c->r; \
        for (node *i = c->d; i != c; i = i->d) \
            for (node *j = i->r; j != i; j = j->r) \
                j->d->u = j->u, j->u->d = j->d, j->p->size--;
    #define UNCOVER(c, i, j) \
        for (node *i = c->u; i != c; i = i->u) \
            for (node *j = i->l; j != i; j = j->l) \
                j->p->size++, j->d->u = j->u->d = j; \
        c->r->l = c->l->r = c;
    bool search(int k = 0) {
        if (head == head->r) {
            vi res(k);
            for (int i = 0; i < k; i++) res[i] = sol[i];
            sort(res.begin(), res.end());
            return handle_solution(res);
        }
        node *c = head->r, *tmp = head->r;
        for ( ; tmp != head; tmp = tmp->r) if (tmp->size < c->size) c = tmp;
        if (c == c->d) return false;
        COVER(c, i, j);
        bool found = false;
        for (node *r = c->d; !found && r != c; r = r->d) {
            sol[k] = r->row;
            for (node *j = r->r; j != r; j = j->r) { COVER(j->p, a, b); }
            found = search(k + 1);
            for (node *j = r->l; j != r; j = j->l) { UNCOVER(j->p, a, b); }
        }
        UNCOVER(c, i, j);
        return found;
    }
};

struct solver {

    map<pair<int, ii>, bool> known;

    solver() {

        // for (int x = 1; x <= 6; x++) {
        //     polynomios.clear();
        //     board arr(x, vector<bool>(x, false));
        //     bt(arr, 0, 0, x);
        //     cout << x << " " << size(polynomios) << endl;
        // }

        // ifstream ifs("polyominoes.txt");

        // string line;
        // board cur;
        // while (getline(ifs, line)) {
        //     if (line == "") {
        //         cur = trim(cur);
        //         int cnt = 0;
        //         for (int i = 0; i < size(cur); i++) {
        //             for (int j = 0; j < size(cur[0]); j++) {
        //                 if (cur[i][j]) {
        //                     cnt++;
        //                 }
        //             }
        //         }

        //         polynomios[cnt].push_back(cur);
        //         cur.clear();
        //     } else {
        //         vector<bool> row;
        //         for (int i = 0; i < size(line); i++) {
        //             row.push_back(line[i] == '#');
        //         }
        //         cur.push_back(row);
        //     }
        // }

        ifstream ifs("d.sol.txt");
        int x, r, c;
        string ans;
        while (ifs >> x >> r >> c >> ans) {
            known[make_pair(x, ii(r, c))] = ans == "GABRIEL";
        }

        // for (int i = 0; i < 10; i++) {
        //     cout << i << " " << size(polynomios[i]) << endl;
        // }
    }

    void solve(bool process, istream &cin, ostream &cout) {

        int x, r, c;
        cin >> x >> r >> c;

        LOGIC;

        if (r > c)
            swap(r, c);

        bool decided = false;
        bool can;
        if (!decided && x >= 2*min(r,c) + 1) can = false, decided = true;
        if (!decided && x >= 7) can = false, decided = true;
        if (!decided && (r*c) % x != 0) can = false, decided = true;
        if (!decided && r == c && x > r) can = false, decided = true;
        if (!decided && x == 1) can = true, decided = true;

        // if (!decided && x == 2) can = true, decided = true;
        // if (!decided && x == 3) can = true, decided = true;
        // if (!decided && x == 4) {
        //     if (!decided && r == 2 && c == 4) can = false, decided = true;
        //     if (!decided && r == 3 && c == 4) can = true, decided = true;
        //     if (!decided && r == 4 && c == 4) can = true, decided = true;
        // }

        // assert(decided);

        // if (!decided) cout << x << "," << r << "," << c << endl;

        pair<int, ii> state(x, ii(r, c));
        if (!decided && known.find(state) != known.end()) {
            decided = true;
            can = known[state];
        }

        if (!decided) {

            bool found = false;
            for (int want = 0; want < size(polynomios[x]); want++) {

                int WANT = 0,
                    CELL = WANT + 1,
                    COLS = CELL + r*c;

                int ROWS = (size(polynomios[x]) + 1) * 2 * 4 * r * c;
                int real_rows = 0;

                exact_cover ec(ROWS, COLS);

                for (int cur = 0; cur < size(polynomios[x]); cur++) {
                    board b = polynomios[x][cur];
                    for (int flips = 0; flips < 2; flips++) {
                        for (int rots = 0; rots < 4; rots++) {
                            for (int is_want = 0; is_want < (cur == want ? 2 : 1); is_want++) {

                                for (int x0 = 0; x0 + size(b) <= r; x0++) {
                                    for (int y0 = 0; y0 + size(b[0]) <= c; y0++) {

                                        if (is_want == 1) {
                                            ec.set_value(real_rows, WANT);
                                        }

                                        for (int i = 0; i < size(b); i++) {
                                            for (int j = 0; j < size(b[0]); j++) {
                                                if (b[i][j]) {
                                                    ec.set_value(real_rows, CELL + (x0 + i) * c + (y0 + j));
                                                }
                                            }
                                        }

                                        real_rows++;
                                    }
                                }
                            }

                            b = rot(b);
                        }

                        b = flip(b);
                    }
                }

                assert(real_rows <= ROWS);

                ec.setup();
                if (!ec.search()) {
                    found = true;
                    break;
                }
            }

            decided = true;
            can = !found;
        }

        assert(decided);

        // return;
        OUTPUT;
        // if (!decided) cout << x << "," << r << "," << c << endl;
        // cout << x << " " << r << " " << c << " ";
        if (can) cout << "GABRIEL" << endl;
        else cout << "RICHARD" << endl;
    }
};

// see https://github.com/SuprDewd/GoogleCodeJamRunner
#include "../../lib/gcj.h"
