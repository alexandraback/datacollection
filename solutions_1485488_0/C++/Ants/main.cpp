/* 
 * File:   main.cpp
 * Author: Ants
 *
 * Created on May 5, 2012, 6:55 PM
 */

#include <cstdlib>
#include <iostream>
#include <limits>
#include <queue>

using namespace std;

const long long INF = numeric_limits<long long>::max();

long long toa[110][110]; //time of accessibility (in 100 ms)
long long btoa[110][110]; // best time of arrival; (in 100 ms)
long long fh[110][110]; // floor height (in cm)
long long ch[110][110]; // ceiling height (in cm)
bool visited[110][110];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(int argc, char** argv) {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int wl, Y, X; // water level, X, Y
        cin >> wl >> Y >> X;
        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++) {
                cin >> ch[x][y];
            }
        }
        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++) {
                cin >> fh[x][y];
            }
        }
        
        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++) {
                if (ch[x][y] - fh[x][y] < 50) toa[x][y] = INF;
                else toa[x][y] = (wl - ch[x][y] + 50);
                if (toa[x][y] < 0) toa[x][y] = 0;
            }
        }
        
        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++) {
                visited[x][y] = 0;
                btoa[x][y] = INF;
            }
        }
        btoa[0][0] = 0;
        
        while (true) {
            long long minbtoa = INF;
            int minx, miny;
            for (int y = 0; y < Y; y++) {
                for (int x = 0; x < X; x++) {
                    if (visited[x][y]) continue;
                    if (btoa[x][y] < minbtoa) {
                        minbtoa = btoa[x][y];
                        minx = x;
                        miny = y;
                    }
                }
            }            
            visited[minx][miny] = true;
            for (int i = 0; i < 4; i++) {
                int nx = minx + dx[i];
                int ny = miny + dy[i];
                if (nx < 0 || nx >= X || ny < 0 || ny >= Y) continue;
                if (visited[nx][ny]) continue;
                if (ch[nx][ny] - fh[minx][miny] < 50) continue;
                if (ch[minx][miny] - fh[nx][ny] < 50) continue;
                long long alt;
                if (toa[nx][ny] > btoa[minx][miny]) {
                    if (toa[nx][ny] <= wl - fh[minx][miny] - 20) {
                        alt = toa[nx][ny] + 10;
                    } else {
                        alt = toa[nx][ny] + 100;
                    }
                } else {
                    if (btoa[minx][miny] == 0) {
                        alt = 0;
                    } else if (btoa[minx][miny] <= wl - fh[minx][miny] - 20) {
                        alt = btoa[minx][miny] + 10;
                    } else {
                        alt = btoa[minx][miny] + 100;
                    }
                }
                if (alt < btoa[nx][ny]) {
                    btoa[nx][ny] = alt;
                }
            }
            if (minx == X-1 && miny == Y-1) break;
        }
        
        cout << "Case #" << t << ": " << btoa[X-1][Y-1]/10 << "." << btoa[X-1][Y-1]%10 << endl;
        
    }
    return 0;
}

