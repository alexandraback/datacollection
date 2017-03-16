#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small.out", "w", stdout);
    int T, R, C, M;
    cin >> T;
    vector< vector< char > > v(50, vector<char>(50));
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ":\n";
        cin >> R >> C >> M;
        if(M == 0) {
             for(int i = 0; i < R; i++) {
                for(int j = 0; j < C; j++) {
                    if(i == 0 && j == 0) v[i][j] = 'c';
                    else v[i][j] = '.';
                    cout << v[i][j];
                }
                cout << endl;
            }
            continue;
        }
        if(M == (R*C) - 1) {
            for(int i = 0; i < R; i++) {
                for(int j = 0; j < C; j++) {
                    if(i == 0 && j == 0) v[i][j] = 'c';
                    else v[i][j] = '*';
                    cout << v[i][j];
                }
                cout << endl;
            }
            continue;
        }
        if(R == 1 || C == 1) {
            int sp = (R*C) - 1 - M;
            for(int i = 0; i < R; i++) {
                for(int j = 0; j < C; j++) {
                    if(i == 0 && j == 0) v[i][j] = 'c';
                    else if(sp) {
                        v[i][j] = '.';
                        sp--;
                    } else {
                        v[i][j] = '*';
                    }
                    cout << v[i][j];
                }
                cout << endl;
            }
            continue;
        }
        if((R*C) - M < 4) {
            cout << "Impossible\n";
            continue;
        }
        if(R == 2 || C == 2) {
            if(M & 1) {
                cout << "Impossible\n";
                continue;
            }
            for(int i = 0; i < R; i++) {
                for(int j = 0; j < C; j++) {
                    v[i][j] = '.';
                }
            }
            v[0][0] = 'c';
            if(R == 2) {
                for(int j = C - 1; j > 1; j--) {
                    for(int i = 0; i < R; i++) {
                        if(M) {
                            v[i][j] = '*';
                            M--;
                        }
                    }
                }
            } else {
                for(int i = R - 1; i > 1; i--) {
                    for(int j = 0; j < C; j++) {
                        if(M) {
                            v[i][j] = '*';
                            M--;
                        }
                    }
                }
            }
            for(int y = 0; y < R; y++) {
                for(int x = 0; x < C; x++) {
                    cout << v[y][x];
                }
                cout << endl;
            }
            continue;
        }
        {
            int xx = C - 2;
            int yy = R - 2;
            if(xx * yy >= M) {
                for(int i = 0; i < R; i++) {
                    for(int j = 0; j < C; j++) {
                        v[i][j] = '.';
                    }
                }
                v[0][0] = 'c';
                for(int i = 0; i < yy; i++) {
                    for(int j = 0; j < xx; j++) {
                        if(M) {
                            v[R-i-1][C-j-1] = '*';
                            M--;
                        }
                    }
                }
                for(int i = 0; i < R; i++) {
                    for(int j = 0; j < C; j++) {
                        cout << v[i][j];
                    }
                    cout << endl;
                }
                continue;
            }
        }
        {
            bool possible = false;
            int ax=0, ay=0, anx=0, any=0;
            for(int x = 1; x < C - 1; x++) {
                for(int y = 1; y < R - 1; y++) {
                    int xx = C - x;
                    int yy = R - y;
                    for(int nx = 0; nx <= x; nx++) {
                        for(int ny = 0; ny <= y; ny++) {
                            int total = (x * y) + (nx * yy) + (ny * xx);
                            if(total == M) {
                                possible = true;
                                ax = x;
                                ay = y;
                                anx = nx;
                                any = ny;
                            }
                        }
                    }
                }
            }
            if(possible) {
                for(int i = 0; i < R; i++) {
                    for(int j = 0; j < C; j++) {
                        v[i][j] = '.';
                    }
                }
                v[0][0] = 'c';
                for(int x = 0; x < ax; x++) {
                    for(int y = 0; y < ay; y++) {
                        v[R-y-1][C-x-1] = '*';
                    }
                }
                int xx = C - ax;
                int yy = R - ay;
                for(int x = 0; x < anx; x++) {
                    for(int y = 0; y < yy; y++) {
                        v[y][C-x-1] = '*';
                    }
                }
                for(int y = 0; y < any; y++) {
                    for(int x = 0; x < xx; x++) {
                        v[R-y-1][x] = '*';
                    }
                }
                for(int y = 0; y < R; y++) {
                    for(int x = 0; x < C; x++) {
                        cout << v[y][x];
                    }
                    cout << endl;
                }
                continue;
            }
        }
        {
            cout << "Impossible\n";
            continue;
        }
    }
}