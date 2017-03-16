#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int R, C, M;
        cin >> R >> C >> M;
        cout << "Case #" << t << ": " << endl;
        bool ans = false;
        vector<string> board(R, string(C, '.'));
        if((M == R*C-1)
            || (M < R*C && (R == 1 || C == 1))
            || (M <= R*C-4 && M%2 == 0 && C == 2)){
            board[R-1][C-1] = 'c';
            for(int y = 0; y < R && M > 0; y++){
                for(int x = 0; x < C && M > 0; x++){
                    board[y][x] = '*';
                    M--;
                }
            }
            ans = true;
        }else if(M <= R*C-4 && M%2 == 0 && R == 2){
            board[R-1][C-1] = 'c';
            for(int x = 0; x < C && M > 0; x++){
                for(int y = 0; y < R && M > 0; y++){
                    board[y][x] = '*';
                    M--;
                }
            }
            ans = true;
        }else if((M < R*C - 7 || M == R*C-6 || M == R*C-4)
            && (R > 2 && C > 2)){
            board[R-1][C-1] = 'c';
            int lx = -1, ly = -1;
            for(int y = 0; y < R-3 && M > 0; y++){
                for(int x = 0; x < C && M > 0; x++){
                    board[y][x] = '*';
                    lx = x; ly = y;
                    M--;
                }
            }
            if(lx == C-2){
                board[ly][lx] = '.';
                board[ly+1][0] = '*';
            }
            for(int x = 0; x < C && M > 0; x++){
                for(int y = R-3; y < R && M > 0; y++){
                    board[y][x] = '*';
                    lx = x; ly = y;
                    M--;
                }
            }
            if(ly == R-2){
                board[ly][lx] = '.';
                board[R-3][lx+1] = '*';
            }
            ans = true;
        }
        if(!ans){
            cout << "Impossible" << endl;
        }else{
            for(int i = 0; i < board.size(); i++){
                cout << board[i] << endl;
            }
        }
    }
    return 0;
}



