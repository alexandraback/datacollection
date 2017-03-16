#include<iostream>
#include <cstdio>
#include<cassert>
#include<vector>
#include<set>
#define REP(n,N) for(int n = 0; n < N; ++n)
using namespace std;

int R, C, M;
vector<vector<char>> F;

bool solve() {
    int nM = R * C - M;
    
    if (R == 1 || C == 1) {
        if (R == 1) {
            REP(c,nM) {
                F[0][c] = '.';
            }
        } else {
            REP(r,nM) {
                F[r][0] = '.';
            }
        }
        F[0][0] = 'c';
        return true;
    }
    
    if (nM == 1) {
        F[0][0] = 'c';
        return true;
    }
    
    if (R == 2 || C == 2) {
        if (nM % 2 || nM == 2) {
            return false;
        }
        
        if (R == 2) {
            REP(c,nM/2) {
                F[0][c] = F[1][c] = '.';
            }
        } else {
            REP(r,nM/2) {
                F[r][0] = F[r][1] = '.';
            }
        }
        F[0][0] = 'c';
        return true;
    }
    
    if (set<int>{ 2, 3, 5, 7}.count(nM)) {
        return false;
    }
    
    auto clear = [&](int r, int c) { if (F[r][c] == '*' && nM) { F[r][c] = '.', --nM; }};
    
    REP(c,3) {
        REP(r,2) {
            clear(r,c);
        }
    }
    clear(2,0), clear(2,1);
    
    for(int r = 0; r < R && nM >= 2; ++r) {
        clear(r,0), clear(r,1);
    }
    
    for(int c = 0; c < C && nM >= 2; ++c) {
        clear(0,c), clear(1,c);
    }
    
    for(int r = 2; r < R; ++r) {
        for(int c = 2; c < C && nM > 0; ++c) {
            clear(r,c);
        }
    }
    
    F[0][0] = 'c';
    assert(nM == 0);
    
    return true;
}

int main() {
    int T; cin >> T;
    
    for(int t = 1; t <= T; ++t) {
        cin >> R >> C >> M;
        F = vector<vector<char>>(R, vector<char>(C, '*'));
        cout << "Case #" << t << ":" << endl;
        
        if (solve()) {
            for(int r = 0; r < R; ++r) {
                for(int c = 0; c < C; ++c) {
                    cout << F[r][c];
                } cout << endl;
            }
            
            int cnt = 0; bool click = false;
            REP(r, R) REP(c, C) {
                if (F[r][c] == 'c') {
                    assert(!click);
                    click = true;
                } else if (F[r][c] == '*') {
                    cnt++;
                } else {
                    assert(F[r][c] == '.');
                }
            }
            assert(cnt == M);
        } else {
            cout << "Impossible" << endl;
        }
    }
}