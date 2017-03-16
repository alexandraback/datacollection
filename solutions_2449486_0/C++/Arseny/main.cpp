#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int,int,int> iii;

const int ANY = -1;

const int MAX_N = 100;
const int MAX_M = 100;

const int MAX_H = 100;

int N;
int M;
int LAWN[MAX_N][MAX_M];

void read_input()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> LAWN[i][j];
}

bool check_row(int row, int h0)
{
    for (int j = 0; j < M; ++j) {
        int h = LAWN[row][j];
        if (h != ANY && h != h0) return false;
    }

    for (int j = 0; j < M; ++j) {
        LAWN[row][j] = ANY;
    }

    return true;
}

bool check_col(int col, int h0)
{
    for (int i = 0; i < N; ++i) {
        int h = LAWN[i][col];
        if (h != ANY && h != h0) return false;
    }

    for (int i = 0; i < N; ++i) {
        LAWN[i][col] = ANY;
    }
    
    return true;
}

bool solve()
{
    priority_queue<iii, vector<iii>, greater<iii> > Q;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int h = LAWN[i][j];
            if (h < MAX_H) {
                Q.push(make_tuple(h,i,j));
            }
        }
    }

    while (!Q.empty()) {
        int h;
        int row, col;
        tie(h, row, col) = Q.top(); Q.pop();
        if (h != LAWN[row][col]) continue;
        bool is_possible = false;
        is_possible|= check_row(row, h);
        is_possible|= check_col(col, h);
        if (!is_possible) return false;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        read_input();
        bool is_possible = solve();
        cout << "Case #" << t << ": " << (is_possible ? "YES" : "NO") << endl;
    }
}