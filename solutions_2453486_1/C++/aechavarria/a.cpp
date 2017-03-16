using namespace std;
#include <iostream>
#include <string>

#define D(x) cout << #x " = " << (x) << endl;

string board [5];

int di [] = {+1, 0, +1, -1};
int dj [] = {0, +1, +1, +1};

bool in(int i, int j){
     if (i >= 0 and i < 4 and j >= 0 and j < 4) return true;
     return false;     
}

bool match(char c, int i, int j){
      if (c == '.') return false;
      assert(c == 'O' or c == 'X');
      if (board[i][j] == c) return true;
      if (board[i][j] == 'T') return true;
      return false;
}

void solve(){
    int won = -1;
    bool dot_found = false;
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            if (board[i][j] == '.'){
               dot_found = true;
               continue;
            }
            for (int k = 0; k < 4; ++k){
                char winner = board[i][j];
                if (winner == 'T'){
                   if (in(i + di[k], j + dj[k])) winner = board[i + di[k]][j + dj[k]];
                   else continue;                              
                }
                //printf("i = %d, j = %d, k = %d, c = %c\n", i, j,k, winner);
                int count = 0;
                for (; count < 4; ++count){
                    int cur_i = i + count * di[k];
                    int cur_j = j + count * dj[k];
                    if (!in(cur_i, cur_j) or !match(winner, cur_i, cur_j)) break;
                } 
                if (count == 4){
                   //printf("Match starts at (%d, %d) with k = %d\n", i, j, k);                   
                   printf("%c won\n", winner);
                   return;        
                }  
            } 
        }
    }
    if (dot_found){
       printf("Game has not completed\n");
       return;
    }
    printf("Draw\n");  
}

int main(){
    int cases; cin >> cases;
    for (int run = 1; run <= cases; ++run){
        for (int i = 0; i < 4; ++i){
            cin >> board[i];
            //D(board[i]);
        }        
        printf("Case #%d: ", run); 
        solve();
        
        
        
    }
    
    return 0;
        
}
