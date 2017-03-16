#include <fstream>
#include <iostream>
#include <string>
using namespace std;

string state[5];

int main() {
          //ifstream in("A-small-attempt0.in");
          //ofstream out("A-small-attempt0.out");
          int T;
          cin >> T;
          for (int tc=1; tc<=T; tc++) {
                    for(int x=0; x<4; x++) {
                              cin >> state[x];
                    }

                    bool hasEmpty = false;
                    bool Xwon = false;
                    bool Owon = false;

                    // row
                    for(int x=0; x<4; x++) {
                              int sumX, sumO;
                              sumX = sumO = 0;
                              for(int y=0; y<4; y++) {
                                        if (state[x][y] == '.') hasEmpty = true;
                                        sumX += state[x][y];
                                        sumO += state[x][y];
                              }
                              if (sumX == 352 || sumX == 348) Xwon = true;
                              if (sumO == 316 || sumO == 321) Owon = true;
                    }

                    // column
                    for(int y=0; y<4; y++) {
                              int sumX,sumO;
                              sumX = sumO = 0;
                              for(int x=0; x<4; x++) {
                                        sumX += state[x][y];
                                        sumO += state[x][y];
                              }
                              if (sumX == 352 || sumX == 348) Xwon = true;
                              if (sumO == 316 || sumO == 321) Owon = true;
                    }

                    // diagonal
                    {
                              int sumX,sumO;
                              sumX = sumO = 0;
                              for(int x=0; x<4; x++) {
                                        sumX += state[x][x];
                                        sumO += state[x][x];
                              }
                              if (sumX == 352 || sumX == 348) Xwon = true;
                              if (sumO == 316 || sumO == 321) Owon = true;

                              sumX = sumO = 0;
                              for(int x=0; x<4; x++) {
                                        sumX += state[x][3-x];
                                        sumO += state[x][3-x];
                              }
                              if (sumX == 352 || sumX == 348) Xwon = true;
                              if (sumO == 316 || sumO == 321) Owon = true;
                    }

                    string result;
                    if (Xwon) result = "X won";
                              else if (Owon) result = "O won";
                                        else if (hasEmpty) result = "Game has not completed";
                                                  else result = "Draw";

                    cout << "Case #" << tc << ": " << result << endl;
          }
          return 0;
}
