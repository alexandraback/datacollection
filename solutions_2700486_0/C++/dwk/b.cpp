#include <iostream>
#include <cstdio>

double simulate(int board[420][210], int n, int x, int y);

double drop(int board[420][210], int n, int i, int j, int x, int y) {
    while(j > 0) {
        bool downblocked = board[i][j-2];
        bool leftblocked = board[i-1][j-1];
        bool rightblocked = board[i+1][j-1];
        
        if(leftblocked && rightblocked) {
            break;  // done
        }
        else if(leftblocked && !rightblocked) {
            i ++, j --;
        }
        else if(!leftblocked && rightblocked) {
            i --, j --;
        }
        else if(downblocked) {
            return 0.5 * drop(board, n, i-1, j-1, x, y)
                + 0.5 * drop(board, n, i+1, j-1, x, y);
        }
        else if(j > 1) {  // fall
            j -= 2;
        }
        else break;
    }
    
    double chance = 0.0;
    
    board[i][j] = 1;
    //std::cout << i << " " << j << std::endl;
    if(n > 0) {
        chance = simulate(board, n, x, y);
    }
    else {
#if 0
        for(int s = 20; s >= 0; s --) {
            for(int r = 0; r < 42; r ++) {
                std::cout << board[r][s];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
#endif
        
        if(board[210+x][y]) {
            chance = 1.0;
        }
    }
    board[i][j] = 0;
    
    return chance;
}

double simulate(int board[420][210], int n, int x, int y) {
    if(n > 0) {
        return drop(board, n-1, 210, 200, x, y);
    }
    return 0;
}

int main() {
    int cases;
    std::cin >> cases;
    for(int c = 0; c < cases; c ++) {
        int n, x, y;
        std::cin >> n >> x >> y;
        
        int board[420][210] = {{}};
        double chance;
        if(x <= -200 || x >= 200 || y >= 200) chance = 0;
        else chance = simulate(board, n, x, y);
        
        //std::cout << "Case #" << (c+1) << ": " << chance << std::endl;
        std::printf("Case #%d: %f\n", c+1, chance);
    }
    
    return 0;
}
