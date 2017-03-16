using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl


bool board[105][105];

bool drop_left(int x, int y){
    int i = 50, j = 51;
    while (true){
        if (!board[i][j]) j--;
        else if (board[i][j] and board[i-1][j] and board[i+1][j]) break;
        else if (board[i][j] and board[i-1][j]) i++;
        else i--;
        if (j < 0) break;
    }
    board[i][max(j, 0)] = board[i][j+2] = true;
    board[i-1][j+1] = board[i][j+1] = board[i+1][j+1] = true;
    
    // printf("Dropping left:\n");
    // 
    // for (j = 3; j >= 0; --j){
    //     for (int i = 47; i <= 53; ++i){
    //         printf("%d ", board[i][j]);
    //     }
    //     printf("\n");
    // }
    if (x+50 < 105 and x+50 >= 0 and y < 105 and y >= 0 and board[x+50][y]) return true;
    return false;
}

bool drop_right(int x, int y){
    int i = 50, j = 51;
    while (true){
        if (!board[i][j]) j--;
        else if (board[i][j] and board[i+1][j] and board[i-1][j]) break;
        else if (board[i][j] and board[i+1][j]) i--;
        else i++;
        if (j < 0) break;
    }
    board[i][max(j, 0)] = board[i][j+2] = true;
    board[i-1][j+1] = board[i][j+1] = board[i+1][j+1] = true;
    
    // printf("Dropping right:\n");
    // 
    // for (j = 3; j >= 0; --j){
    //     for (int i = 47; i <= 53; ++i){
    //         printf("%d ", board[i][j]);
    //     }
    //     printf("\n");
    // }
    if (x+50 < 105 and x+50 >= 0 and y < 105 and y >= 0 and board[x+50][y]) return true;
    return false;
}


int main(){
    int cases; cin >> cases;
    
    for (int run = 1; run <= cases; ++run){
        int n, x, y;
        cin >> n >> x >> y;
        int reached = 0;
        for (int mask = 0; mask < (1 << n); ++mask){
            memset(board, false, sizeof board);
            for (int i = 0; i < n; ++i){
                bool ans = false;
                if (mask & (1 << i)) ans = drop_left(x, y);
                else  ans = drop_right(x, y);
                if (ans){
                    reached++;
                    break;
                }
            }
        }
        double p = 1.0 * reached / (1 << n);
        printf("Case #%d: %.6lf\n", run, p);
    }
    return 0;
}
