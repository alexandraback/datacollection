//#define __test__aTest__
#ifndef __test__aTest__

#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <assert.h>
#include <stdexcept>

using namespace std;

#define ll long long
#define ull size_t

const int dx[] = {-1, 0, 0, 1, -1, -1, 1, 1};
const int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};
bool visited[5][5];
char board[5][5];
char b[5][5];
int R, C, M;


int getCount(int i, int j);

void checkDFS(int i, int j) {
    if (visited[i][j])  return;
    visited[i][j] = true;
    int c = getCount(i, j);
    b[i][j] = '0' + c;
    
    if (c == 0) {
        for (int k = 0; k < 8; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < R && y >= 0 && y < C) {
                c = getCount(x, y);
                b[x][y] = '0' + c;
                if (c == 0) {
                    checkDFS(x, y);
                }
            }
        }
    }
}
void checkValid() {
    int ci = 0, cj = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            b[i][j] = board[i][j];
            visited[i][j] = false;
            if (b[i][j] == 'c') {
                ci = i;
                cj = j;
            }
        }
    }
    checkDFS(ci, cj);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (b[i][j] == '.') {
                cerr<<R<<" "<<C<<" "<<M<<" "<<endl;
                for (int i = 0; i < R; i++) {
                    for (int j = 0; j < C; j++) {
                        cerr<<board[i][j];
                    }
                    cerr<<endl;
                }
                assert(false);
            }
        }
    }

}

void printBoard() {
    checkValid();
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout<<board[i][j];
        }
        cout<<endl;
    }
}

int getCount(int i, int j) {
    int c = 0;
    for (int k = 0; k < 8; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 0 && x < R && y >= 0 && y < C) {
            if (board[x][y] == '*') c++;
        }
    }
    return c;
}

bool dfs(int i, int j) {
    if (board[i][j] == '*')  return false;
    if (visited[i][j])       return false;
    visited[i][j] = true;
    int c = getCount(i, j);
    if (c == 0) {
        board[i][j] = '0';
        for (int k = 0; k < 8; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < R && y >= 0 && y < C) {
                c = getCount(x, y);
                board[x][y] = '0' + c;
                if (c == 0) {
                    dfs(x, y);
                }
            }
        }
        return true;
    }
    return false;
}

bool checkAndPrint() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            visited[i][j] = false;
        }
    }
    bool flag = false;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            flag = dfs(i, j);
            if (flag) break;
        }
        if (flag) break;
    }
    bool isValid = true;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == '.')
                isValid = false;
        }
    }
    if (!isValid)  return false;
    bool first = true;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char c = board[i][j];
            if (c == '0') {
                if (first)  {
                    board[i][j] = 'c';
                    first = false;
                } else {
                    board[i][j] = '.';
                }
            } else if (c >= '1' && c <= '8') {
                board[i][j] = '.';
            }
        }
    }
    if (first) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] != '*') {
                    board[i][j] = 'c';
                }
            }
        }
    }
    printBoard();
    return true;
}

void process() {
    cin >> R >> C >> M;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            board[i][j] = '.';
        }
    }
    if (M == 0) {
        board[0][0] = 'c';
        printBoard();
        return;
    } else if (R * C - M == 1) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                board[i][j] = '*';
            }
        }
        board[0][0] = 'c';
        printBoard();
        return;
    }
    int k = M;
    int N = R * C;
    int s = (1 << k) - 1;
    while (!(s & 1 << N))
    {
        for (int i = 0; i < N; i++) {
            if (s & (1 << i)) {
                int x = i / C;
                int y = i - x * C;
                board[x][y] = '*';
             }
        }
        if (checkAndPrint()) {
            return;
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                board[i][j] = '.';
            }
        }
        // do stuff with s
        int lo = s & ~(s - 1);       // lowest one bit
        int lz = (s + lo) & ~s;      // lowest zero bit above lo
        s |= lz;                     // add lz to the set
        s &= ~(lz - 1);              // reset bits below lz
        s |= (lz / lo / 2) - 1;      // put back right number of bits at end
    }
    cout<<"Impossible"<<endl;
}



int main() {
    
    freopen("/Users/zishirs/Documents/workspace/test/test/test.txt", "r", stdin);
    freopen("/Users/zishirs/Documents/workspace/test/test/output.txt", "w", stdout);
    
    
    int T;
    cin >> T;
    for (int index = 1; index <= T; ++index) {
        cout<<"Case #"<<index<<":"<<endl;
        process();
        //cout<<"Case #"<<index<<": "<<endl;
    }
    
    /*
     int F;
     cin >> F;
     int n;
     vector<int> v;
     while (cin >> n) {
     v.push_back(n);
     }
     vector<int> v1(v.begin(), v.begin() + v.size()/2), v2(v.begin() + v.size()/2, v.end());
     */
    
    return 0;
}

#endif