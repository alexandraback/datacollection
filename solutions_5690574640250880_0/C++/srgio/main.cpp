#include <iostream>
#include <cstring>
using namespace std;

int f[50][50], m, c, r, s, t = 1;
bool solve(int, int, int);
void helper(int, int);

int main()
{
    int tests;
    cin >> tests;
    while(tests--){
        cin >> r >> c >> m;
        s = r*c;
        memset(f, 0, sizeof f);
        bool solved = false;
        if(s - 1 == m){
            solved = true;
            cout << "Case #" << t << ":" << endl;
            bool click = false;
            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){
                    if(!click){
                        cout << 'c';
                        click = true;
                    }
                    else{
                        cout << '*';
                    }
                }
                cout << endl;
            }
        }
        if(!solved){
            for(int i = 0; i < c; ++i){
                for(int j = 0; j < r; ++j){
                    if(solve(i, j, 1)){
                        solved = true;
                        break;
                    }
                }
                if(solved) break;
            }
        }
        if(!solved) cout << "Case #" << t << ":" << endl << "Impossible" << endl;
        t++;
    }
    return 0;
}


int ff[50][50];
int fff[50][50];

bool solve(int x, int y, int n)
{
    f[x][y] = 1;
    if(n < (s - m)){
        for(int dx = -1; dx <= 1; ++dx){
            for(int dy = -1; dy <= 1; ++dy){
                if(!dx && !dy) continue;
                int nx = x + dx;
                int ny = y + dy;
                if( (nx < c && nx >= 0) && (ny < r && ny >= 0) ){
                    if(!f[nx][ny])
                        if(solve(nx, ny, n+1)) return true;
                }
            }
        }

    }
    else{
        for(int i = 0; i < c; ++i){
            for(int j = 0; j < r; ++j){
                ff[i][j] = f[i][j] - 1;
            }
        }



        //mark number of mines adjacent to empty cells
        for(int i = 0; i < c; ++i){
              for(int j = 0; j < r; ++j){
                if(ff[i][j] == -1){
                    for(int dx = -1; dx <= 1; ++dx){
                        for(int dy = -1; dy <= 1; ++dy){
                            if(!dx && !dy) continue;
                            int nx = i + dx;
                            int ny = j + dy;
                            if( (nx < c && nx >= 0) && (ny < r && ny >= 0) ){
                                if(ff[nx][ny] > -1)
                                    ++ff[nx][ny];
                            }
                        }
                    }
                }
              }
        }

        //check that all empty cells adjacent to mines are also adjacent to empty cells which are not adjacent to mines
        bool disconnected = false; //if graph as a whole is disconnected
        for(int i = 0; i < c; ++i){
              for(int j = 0; j < r; ++j){
                if(ff[i][j] > 0){
                    bool connected = false; //is this cell connected with zeros
                    for(int dx = -1; dx <= 1; ++dx){
                        for(int dy = -1; dy <= 1; ++dy){
                            if(!dx && !dy) continue;
                            int nx = i + dx;
                            int ny = j + dy;
                            if( (nx < c && nx >= 0) && (ny < r && ny >= 0) ){
                                if(!ff[nx][ny]){
                                    connected = true;
                                    break;
                                }

                            }
                        }
                        if(connected) break;
                    }
                    if(!connected){
                        disconnected = true;
                        break;
                    }
                }
              }
              if(disconnected) break;
        }


        //count number of zeros
        bool chooseStart = true;
        int stX, stY;
        int zerosCnt = 0;
        for(int i = 0; i < c; ++i){
            for(int j = 0; j < r; ++j){
                fff[i][j] = ff[i][j];
                if(fff[i][j] == 0){
                    if(chooseStart){
                        stX = i;
                        stY = j;
                    }
                    zerosCnt++;
                }
            }
        }


        //check if zeros are all connected together
        bool connectedZeros = true;
        if(zerosCnt > 0){
            helper(stX, stY);
            //check if all zeros has been connected
            int connCnt = 0;
            for(int i = 0; i < c; ++i){
                for(int j = 0; j < r; ++j){
                    if(fff[i][j] == -2){
                        connCnt++;
                    }
                }
            }
            if(zerosCnt > connCnt) connectedZeros = false;
        }






        if(!disconnected && connectedZeros){
            cout << "Case #" << t << ":" << endl;
            bool click = false;
            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){
                    if(ff[j][i] > -1){
                        if(!click && !ff[j][i]){
                            cout << 'c';
                            click = true;
                        }
                        else{
                            cout << '.';
                        }
                    }
                    else{
                        cout << '*';
                    }
                }
                cout << endl;
            }

            return true;
        }

    }
    f[x][y] = 0;
    return false;
}

void helper(int x, int y)
{
    fff[x][y] = -2;
    for(int dx = -1; dx <= 1; ++dx){
        for(int dy = -1; dy <= 1; ++dy){
            if(!dx && !dy) continue;
            int nx = x + dx;
            int ny = y + dy;
            if( (nx < c && nx >= 0) && (ny < r && ny >= 0) ){
                if(!fff[nx][ny]){
                    helper(nx,ny);
                }

            }
        }
    }
}
