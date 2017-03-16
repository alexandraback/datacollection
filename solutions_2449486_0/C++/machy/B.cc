#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string solve(vector<vector<int> >& board){
    vector<int> horizontal(board.size());
    vector<int> vertical(board[0].size());
    for(int n = 0; n < board.size(); n++){
        horizontal[n] = *max_element(board[n].begin(), board[n].end());
    }
    for(int m = 0; m < board[0].size(); m++){
        int max_n = 0;
        for(int n = 1; n < board.size(); n++){
            if(board[n][m] > board[max_n][m]) max_n = n;
        }
        vertical[m] = board[max_n][m];
    }
    for(int n = 0; n < board.size(); n++){
        for(int m = 0; m < board[0].size(); m++){
            if(board[n][m] != min(horizontal[n], vertical[m])) return "NO";
        }
    }
    return "YES";
}

int main(){
    int T;
    cin >> T;
    for(size_t t = 1; t <= T; t++){
        int M, N;
        cin >> N >> M;
        vector<vector<int> > board;
        for(int n = 0; n < N; n++){
            vector<int> line;
            for(int m = 0; m < M; m++){
                int v;
                cin >> v;
                line.push_back(v);
            }
            board.push_back(line);
        }
        
        string res = solve(board);
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}

