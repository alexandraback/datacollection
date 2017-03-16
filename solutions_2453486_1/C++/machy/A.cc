#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool checkLine(vector<string>& board, int x, int y, int dx, int dy, char player){
    for(int i = 0; i < 4; i++){
        if(board[y][x] != player && board[y][x] != 'T') return false;
        x += dx; y += dy;
    }
    return true;
}

bool checkWon(vector<string>& board, char player){
    for(int i = 0; i < 4; i++){
        if(checkLine(board, i, 0, 0, 1, player)) return true;
        if(checkLine(board, 0, i, 1, 0, player)) return true;
    }
    if(checkLine(board, 0, 0, 1, 1, player)) return true;
    if(checkLine(board, 3, 0, -1, 1, player)) return true;
    return false;
}

string gameState(vector<string>& board){
    if(checkWon(board, 'X')) return "X won";
    if(checkWon(board, 'O')) return "O won";
    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){
            if(board[y][x] == '.') return "Game has not completed";
        }
    }
    return "Draw";
}

int main(){
    string line;
    getline(cin, line);
    stringstream sst(line);
    int T;
    sst >> T;
    for(size_t t = 1; t <= T; t++){
        vector<string> board;
        for(int i = 0; i < 4; i++){
            getline(cin, line);
            board.push_back(line);
        }
        string res = gameState(board);
        cout << "Case #" << t << ": " << res << endl;
        getline(cin, line);
    }
    return 0;
}

