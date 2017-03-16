#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int dr[]={-1,1,0,0}, dc[]={0,0,-1,1};

struct square { int r,c; square(int r, int c) : r(r), c(c) {} };
bool operator< (const square &A, const square &B) { return A.r < B.r || (A.r == B.r && A.c < B.c); }
bool operator== (const square &A, const square &B) { return A.r == B.r && A.c == B.c; }
ostream& operator<< (ostream &out, const square &A) { return out << "(" << A.r << "," << A.c << ")"; }

typedef set<square> omino;

omino left_top_align(const omino &A) {
    int rmin=4747, cmin=4747;
    for (auto s : A) { rmin=min(rmin,s.r); cmin=min(cmin,s.c); }
    omino B;
    for (auto s : A) B.insert( square( s.r-rmin, s.c-cmin ) );
    return B;
}

omino rotate(const omino &A) {
    omino B;
    for (auto s : A) B.insert( square( s.c, 100-s.r ) );
    B = left_top_align(B);
    return B;
}

omino transpose(const omino &A) {
    omino B;
    for (auto s : A) B.insert( square( s.c, s.r ) );
    B = left_top_align(B);
    return B;
}

set<omino> rotations_and_reflections(const omino &A) {
    set<omino> answer;
    omino B = A;
    for (int j=0; j<2; ++j) {
        for (int i=0; i<4; ++i) { B=rotate(B); answer.insert(B); }
        B = transpose(B);
    }
    return answer;
}

set<omino> evolve(const omino &A) {
    set<omino> answer;
    for (auto s : A) {
        for (int d=0; d<4; ++d) {
            omino B = A;
            B.insert( square(s.r+dr[d], s.c+dc[d]) );
            if (B.size() == A.size()) continue;
            B = *rotations_and_reflections(B).begin();
            answer.insert(B);
        }
    }
    return answer;
}

set<omino> evolve(const set<omino> &S) {
    set<omino> answer;
    for (auto o : S) {
        set<omino> curr = evolve(o);
        answer.insert( curr.begin(), curr.end() );
    }
    return answer;
}

set<omino> evolve_restricted(const omino &A, const vector< vector<int> > &grid) {
    set<omino> answer;
    for (auto s : A) {
        for (int d=0; d<4; ++d) {
            omino B = A;
            int nr = s.r+dr[d], nc = s.c+dc[d];
            if (nr<0 || nr>=int(grid.size()) || nc<0 || nc>=int(grid[0].size())) continue;
            if (grid[nr][nc] != 0) continue;
            B.insert( square(nr,nc) );
            if (B.size() == A.size()) continue;
            answer.insert(B);
        }
    }
    return answer;
}

set<omino> evolve_restricted(const set<omino> &S, const vector< vector<int> > &grid) {
    set<omino> answer;
    for (auto o : S) {
        set<omino> curr = evolve_restricted(o,grid);
        answer.insert( curr.begin(), curr.end() );
    }
    return answer;
}

int fill(vector< vector<int> > &grid, int r, int c, int cfrom, int cto) {
    if (r<0 || r>=int(grid.size()) || c<0 || c>=int(grid[0].size())) return 0;
    if (grid[r][c] != cfrom) return 0;
    grid[r][c] = cto;
    int answer = 1;
    for (int d=0; d<4; ++d) answer += fill(grid,r+dr[d],c+dc[d],cfrom,cto);
    return answer;
}

bool can_fill(vector< vector<int> > &grid, int X) {
    int R=grid.size(), C=grid[0].size();
    bool has_empty = false;
    bool is_already_bad = false;
    for (int r=0; r<R; ++r) for (int c=0; c<C; ++c) if (grid[r][c]==0) {
        has_empty = true;
        if (fill(grid,r,c,0,10) % X != 0) { is_already_bad = true; break; }
    }
    for (int r=0; r<R; ++r) for (int c=0; c<C; ++c) if (grid[r][c]==10) fill(grid,r,c,10,0);
    if (is_already_bad) return false;
    if (!has_empty) return true;

    // if we got here, we still need to place at least one X-omino
    int er=-1, ec=-1;
    for (int r=0; r<R; ++r) {
        for (int c=0; c<C; ++c) if (grid[r][c]==0 && er==-1) { er=r; ec=c; break; }
        if (er >= 0) break;
    }
    omino single;
    single.insert( square(er,ec) );
    set<omino> options;
    options.insert(single);
    for (int x=2; x<=X; ++x) options = evolve_restricted(options,grid);

    for (auto option : options) {
        for (auto s : option) grid[ s.r ][ s.c ] = 1;
        if (can_fill(grid,X)) return true;
        for (auto s : option) grid[ s.r ][ s.c ] = 0;
    }
    return false;
}

bool gabriel_wins(const omino &A, int r, int c, int X, int R, int C) {
    vector< vector<int> > grid( R, vector<int>(C,0) );
    for (auto s:A) grid[ r+s.r ][ c+s.c ] = 1;
    return can_fill(grid,X);
}

bool richard_wins(const omino &A, int X, int R, int C) {
    set<omino> shapes = rotations_and_reflections(A);
    for (auto shape : shapes) {
        int maxr=0, maxc=0;
        for (auto s : shape) { maxr=max(maxr,s.r); maxc=max(maxc,s.c); }
        for (int r=0; r+maxr<R; ++r) for (int c=0; c+maxc<C; ++c) if (gabriel_wins(shape,r,c,X,R,C)) return false;
    }
    return true;
}

bool richard_wins(int X, int R, int C) {
    if (X == 1) return false;
    if (X >= 7) return true;
    if ((R*C)%X != 0) return true;

    // generate all X-ominoes
    omino single;
    single.insert( square(0,0) );
    set<omino> ominoes;
    ominoes.insert( single );
    for (int x=2; x<=X; ++x) ominoes = evolve(ominoes);

    // check each X-omino
    for (auto o : ominoes) if (richard_wins(o,X,R,C)) return true;
    return false;
}

int main() {
    int T; cin >> T;
    for (int t=1; t<=T; ++t) {
        int X, R, C;
        cin >> X >> R >> C;
        cout << "Case #" << t << ": " << (richard_wins(X,R,C) ? "RICHARD" : "GABRIEL") << endl;
    }
}
