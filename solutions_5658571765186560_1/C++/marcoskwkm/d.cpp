#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 7;
const int MAXL = 22;

typedef vector<pii> Poly;

set<Poly> poly[MAXN];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

inline void fix(Poly &piece) {
    int minx = INF, miny = INF;
    for(pii p: piece) {
        minx = min(minx, p.first);
        miny = min(miny, p.second);
    }
    for(pii &p: piece) {
        p.first -= minx;
        p.second -= miny;
    }
    sort(piece.begin(), piece.end());
}

void rotate(Poly &piece) {
    for(pii &p: piece)
        p = pii(-p.second, p.first);
}

void gen_polys() {
    poly[1].insert(Poly(1, pii(0,0)));
    for(int size=2; size<MAXN; ++size) {
        for(Poly piece: poly[size-1]) {
            for(pii p: piece) {
                for(int i=0; i<4; i++) {
                    pii add(p.first + dx[i], p.second + dy[i]);
                    if(find(piece.begin(), piece.end(), add) != piece.end())
                        continue;
                    Poly extended = piece;
                    extended.push_back(add);
                    bool contains = 0;
                    for(int j=0; j<4; ++j) {
                        rotate(extended);
                        fix(extended);
                        if(poly[size].find(extended) != poly[size].end()) {
                            contains = 1;
                            break;
                        }
                    }
                    if(!contains)
                        poly[size].insert(extended);
                }
            }
        }
    }
}

int grid[MAXL][MAXL];

int dfs(int r, int c, int R, int C) {
    grid[r][c] = 1;
    int ret = 1;
    for(int i=0; i<4; i++) {
        int nr = r + dx[i], nc = c + dy[i];
        if(nr >= R || nc >= C || nr < 0 || nc < 0) continue;
        if(!grid[nr][nc])
            ret += dfs(nr, nc, R, C);
    }
    return ret;
}

bool check(int N, int R, int C) {
    for(int r=0; r<R; ++r) {
        for(int c=0; c<C; ++c) {
            if(!grid[r][c]) {
                int q = dfs(r, c, R, C);
                if(q % N != 0) return 0;
            }
        }
    }
    return 1;
}

void printPiece(Poly piece) {
    memset(grid,0,sizeof(grid));
    for(pii p: piece)
        grid[p.first][p.second] = 1;
    for(int r=0; r<6; ++r) {
        for(int c=0; c<6; ++c)
            printf("%c",grid[r][c] ? '#' : ' ');
        printf("\n");
    }
}

void solve(int N, int R, int C, int t) {
    if( (R*C)%N != 0 ) {
        // necessary condition
        printf("Case #%d: RICHARD\n", t);
        return;
    }
    if(N > 6) {
        // get the one with a hole in the middle
        printf("Case #%d: RICHARD\n", t);
        return;
    }
    if( (N+1)/2 > min(R, C) || N > max(R, C) ) {
        // get either the L or the I shaped polyomino
        printf("Case #%d: RICHARD\n", t);
        return;
    }
    if(N <= 3) {
        // its always possible
        printf("Case #%d: GABRIEL\n", t);
        return;
    }
    if(min(R, C) >= 6) {
        // conjecture: its always possible to place the piece
        // so that the remaining cells form a single component
        // this optimization may be optional
        printf("Case #%d: GABRIEL\n", t);
        return;
    }
    bool found = 0;
    for(Poly piece: poly[N]) {
        bool ok = 0;
        for(int rot=0; rot<4; ++rot) {
            for(int r=0; r<R && !ok; ++r) {
                for(int c=0; c<C && !ok; ++c) {
                    bool fits = 1;
                    for(pii p: piece) {
                        if(r + p.first >= R || c + p.second >= C) {
                            fits = 0;
                            break;
                        }
                    }
                    if(!fits) continue;
                    memset(grid, 0, sizeof(grid));
                    for(pii p: piece)
                        grid[r + p.first][c + p.second] = 1;
                    if(check(N, R, C)) ok = 1;
                }
            }
            rotate(piece);
            fix(piece);
        }
        if(!ok) {
            found = 1;
//            printf("This piece screws with Gabriel:\n");
//            printPiece(piece);
            break;
        }
    }
    printf("Case #%d: %s\n", t, found ? "RICHARD" : "GABRIEL");
    return;
}    

int main() {
    gen_polys();
    int t=1, T;
    for(scanf("%d",&T); t<=T; ++t) {
        int n, r, c;
        scanf("%d%d%d",&n, &r, &c);
        solve(n, r, c, t);
    }        
    return 0;
}
