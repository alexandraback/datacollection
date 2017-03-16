#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MP make_pair
#define SPII set<pair<int,int> >
#define SSPII set<SPII >
#define VPII vector<pair<int,int> >
#define VVPII vector<VPII >

int X, R, C;
SSPII ominoes_temp[8];
VVPII ominoes[8];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int board[25][25];

void add(SSPII &res, SPII s) {
    for (SPII::iterator it = s.begin(); it != s.end(); it++) {
        pair<int,int> p = *it;
        for (int i = 0; i < 4; i++) {
            int rr = p.first + dr[i];
            int cc = p.second + dc[i];
            int leftmost = min(cc, 0);
            int topmost = min(rr, 0);
            SPII s2 = s;
            s2.insert(MP(rr, cc));
            if (s2.size() > s.size()) {
                SPII s3;
                for (SPII::iterator it2 = s2.begin(); it2 != s2.end(); it2++) {
                    s3.insert(MP(it2->first - topmost, it2->second - leftmost));
                }
                assert(s3.size() - 1 == s.size());
                res.insert(s3);
            }
        }
    }
}

void gen_ominoes() {
    SPII s;
    s.insert(MP(0, 0));
    ominoes_temp[1].insert(s);
    for (int i = 2; i <= 6; i++) {
        for (SSPII::iterator it = ominoes_temp[i - 1].begin(); it != ominoes_temp[i - 1].end(); it++) {
            SPII st = *it;
            add(ominoes_temp[i], st);
        }
    }

    for (int i = 1; i <= 6; i++) {
        for (SSPII::iterator it = ominoes_temp[i].begin(); it != ominoes_temp[i].end(); it++) {
            VPII v;
            SPII st = *it;
            for (SPII::iterator it2 = st.begin(); it2 != st.end(); it2++) {
                v.push_back(*it2);
            }
            ominoes[i].push_back(v);
        }
    }
}

int flood_fill(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C)
        return 0;
    if (board[r][c] == 1)
        return 0;
    board[r][c] = 1;
    int res = 1;
    for (int i = 0; i < 4; i++) {
        res += flood_fill(r + dr[i], c + dc[i]);
    }
    return res;
}

bool can_fill(VPII v, int r, int c) {
    for (int i = 0; i < R; i++)
        fill(board[i], board[i] + C, 0);
    int dr = r - v[0].first;
    int dc = c - v[0].second;
    for (int i = 0; i < v.size(); i++) {
        int rr = v[i].first + dr;
        int cc = v[i].second + dc;
        if (rr < 0 || rr >= R || cc < 0 || cc >= C)
            return false;
        board[rr][cc] = 1;
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 0) {
                int cnt = flood_fill(i, j);
                if (cnt % X != 0)
                    return false;
            }
        }
    }
    return true;
}

bool can_fill_any(VPII v) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (can_fill(v, i, j))
                return true;
        }
    }
    return false;
}

VPII rotate_omino(VPII v) {
    int topmost = 0;
    int leftmost = 0;
    for (int i = 0; i < v.size(); i++) {
        int a = v[i].first, b = v[i].second;
        v[i].first = b;
        v[i].second = -a;
        topmost = min(topmost, v[i].first);
        leftmost = min(leftmost, v[i].second);
    }
    for (int i = 0; i < v.size(); i++) {
        v[i].first -= topmost;
        v[i].second -= leftmost;
    }
    return v;
}

VPII reflect_omino(VPII v) {
    int leftmost = 0;
    for (int i = 0; i < v.size(); i++) {
        int a = v[i].first, b = v[i].second;
        v[i].first = a;
        v[i].second = -b;
        leftmost = min(leftmost, v[i].second);
    }
    for (int i = 0; i < v.size(); i++) {
        v[i].second -= leftmost;
    }
    return v;
}

bool solve() {
    bool win = true;
    for (int i = 0; i < ominoes[X].size(); i++) {
        VPII v = ominoes[X][i];
        bool can = false;
        for (int j = 0;j < 4 && !can; j++) {
            v = rotate_omino(v);
            VPII v2 = reflect_omino(v);
            if (can_fill_any(v))
                can = true;
            if (can_fill_any(v2))
                can = true;
        }
        if (!can)
            return true;
    }
    return false;
}

int main() {
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small.out", "w", stdout);
    gen_ominoes();
    int T;
    scanf("%d",&T);
    for (int cc = 1; cc <= T; cc++) {
        scanf("%d %d %d", &X, &R, &C);
        if (X >= 7 || solve()) {
            printf("Case #%d: RICHARD\n", cc);
        } else {
            printf("Case #%d: GABRIEL\n", cc);
        }
    }
    return 0;
}
