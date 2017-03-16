#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t){
        int R, C, M;
        cin >> R >> C >> M;
        M = R*C - M;
        bool tr = false;
        bool possible = false;
        if (C < R){
              tr = true;
              swap(R, C);
        }
        vector <vector <int> > MM(R, vector <int> (C, 0));
        if (R == 1){
              possible = true;
              MM[0][0] = 2;
              for (int i = 1; i < M; ++i) MM[0][i] = 1;
        }
        else{
             if (2*R <= M){
                     if (R == 2){
                           if (M%2 == 1) possible = false;
                           else{
                                 for (int i = 1; i < M; ++i) MM[i%R][i/R] = 1;
                                 possible = true;
                                 MM[0][0] = 2;
                           }
                     }
                     /*else if (R == 3){
                           if (M == 7) possible = false;
                           else{
                                for (int i = 1; i < M; ++i) MM[i%R][i/R] = 1;
                                possible = true;
                                MM[0][0] = 2;
                     }*/
                     else {
                          if (M%R != 1){
                                  for (int i = 1; i < M; ++i) MM[i%R][i/R] = 1;
                                  possible = true;
                                  MM[0][0] = 2;
                          }
                          else{
                               if (M/R > 2){
                                      for (int i = 1; i < M; ++i) MM[i%R][i/R] = 1;
                                      possible = true;
                                      MM[0][0] = 2;
                                      MM[M%R][M/R] = 1;
                                      MM[R-1][M/R - 1] = 0;
                               }
                               else{
                                    if (R > 3){
                                       for (int i = 1; i < M; ++i) MM[i%(R-1)][i/(R-1)] = 1;
                                       possible = true;
                                       MM[0][0] = 2;
                                    }
                               }
                          }
                     }
             }
             else if (M == 1){
                   MM[0][0] = 2;
                   possible = true;
             }
             else if (M != 2 and M != 3 and M != 5 and M != 7){
                  possible = true;
                  if (M%2 == 0){
                          for (int i = 0; i < M/2; ++i) MM[0][i] = MM[1][i] = 1;
                  }
                  else{
                       M -= 3;
                       for (int i = 0; i < M/2; ++i) MM[0][i] = MM[1][i] = 1;
                       for (int i = 0; i < 3; ++i) MM[2][i] = 1;
                  }
                  MM[0][0] = 2;
             }
        }
        cout << "Case #" << t << ":" << endl;
        if (possible){
            if (tr){
                    for (int i = 0; i < C; ++i){
                        for (int j = 0; j < R; ++j){
                            if (MM[j][i] == 0) cout << "*";
                            else if (MM[j][i] == 1) cout << ".";
                            else cout << "c";
                        }
                        cout << endl;
                    }
            }
            else{
                 for (int i = 0; i < R; ++i){
                     for (int j = 0; j < C; ++j){
                         if (MM[i][j] == 0) cout << "*";
                         else if (MM[i][j] == 1) cout << ".";
                         else cout << "c";
                     }
                     cout << endl;
                 }
            }
        }
        else cout << "Impossible" << endl;
    }
}
        
                  
