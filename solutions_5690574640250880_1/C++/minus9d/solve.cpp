#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define FOREACH(i, n) for (__typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair

void print_cell(vector< vector<char> > &cell, int R, int C, bool reverse=false)
{
    if(!reverse){
        REP(r, R){
            REP(c, C) {
                printf("%c", cell[r][c]);
            }
            cout << endl;
        }
    }
    else{
        REP(c, C) {
            REP(r, R){
                printf("%c", cell[r][c]);
            }
            cout << endl;
        }
    }
}

bool dfs(int row, int c_max, vector<int> &history, int mine_sum, int R, int C, int M){
    int possible_max_mine = (R - row) * c_max;
    if (possible_max_mine + mine_sum < M) return false;
    
    if (row == R) {
        if (mine_sum == M
            && (history[R-1] == history[R-2])
            ){
            return true;
        }
        else
        {
            return false;
        }
    }

    REP(c, c_max+1){
        if(c == C-1) continue;
        
        history[row] = c;
        bool ans = dfs(row+1, c, history, mine_sum + c, R, C, M);
        if (ans) return true;
    }
    return false;
}

void solve(int R, int C, int M, int test)
{
    bool reverse = false;
    if (R < C) {
        swap(R, C);
        reverse = true;
    }
    
    vector< vector<char> > cell(R);
    REP(r,R){
        cell[r].resize(C);
    }
        
    cout << "Case #" << (test+1) << ": " << endl;

    // exception 1
    if (M == R * C - 1){
        REP(r, R){
            REP(c, C) {
                cell[r][c] = '*';
            }
        }
        cell[R-1][C-1] = 'c';
        print_cell(cell, R, C, reverse);
        return;
    }

    // exception 2
    if (C == 1){
        REP(r, M){
            cell[r][0] = '*';
        }
        FOR(r, M, R){
            cell[r][0] = '.';
        }
        cell[R-1][0] = 'c';
        print_cell(cell, R, C, reverse);
        return;
    }

    vector<int> history(R);
    bool ans = dfs(0, C, history, 0, R, C, M);

    // print answer
    if (!ans){
        cout << "Impossible" << endl;
    }
    else{
        REP(r, R) {
            REP(c, history[r]){
                cell[r][c] = '*';
            }
            FOR(c, history[r], C){
                cell[r][c] = '.';
            }
        }
        cell[R-1][C-1] = 'c';
            
        print_cell(cell, R, C, reverse);
    }
}

int main(void)
{
    int TEST_NUM;
    cin >> TEST_NUM;

    for(int test = 0; test < TEST_NUM; ++test){
        int R, C, M;
        cin >> R >> C >> M;

        solve(R, C, M, test);

    }

    return 0;
}
