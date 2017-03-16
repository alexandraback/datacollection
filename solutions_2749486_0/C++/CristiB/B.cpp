#include <iostream>
#include <queue>
#include <cstring>
#include <iomanip>
#include <utility>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>
#include <boost/lexical_cast.hpp>

//#define log false && cerr
#define log cerr

using namespace std;

const int MAX_N = 1000;
const int OFF = MAX_N / 2;

int dx[4] = {0, 0, 1, -1}; // NSEW
int dy[4] = {1, -1, 0, 0};
char dir[4] = {'N', 'S', 'E', 'W'};

int d[MAX_N][MAX_N];
int move[MAX_N][MAX_N];

typedef pair<int, int> pr;
#define mp make_pair

void precomp() {
    memset(d, -1, sizeof(d));

    queue<pr> q;
    q.push(mp(0 + OFF, 0 + OFF));
    d[0 + OFF][0 + OFF] = 0;
    move[0 + OFF][0 + OFF] = -1;
//    log << "Push: 0 0 " << endl;

    while (!q.empty()) {
        pr t = q.front();
        q.pop();

        int x = t.first;
        int y = t.second;
        int dist = d[x][y];
        int ndist = dist + 1;
//        log << "Pop: " << x << " " << y << endl;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i] * ndist;
            int ny = y + dy[i] * ndist; 

//            log << "Try: " << nx << " " << ny << endl;

            int ix = nx;
            int iy = ny;

            if (ix >= MAX_N || iy >= MAX_N || ix < 0 || iy < 0)
                continue;

//            log << "d: " << d[ix][iy] << endl;
            if (d[ix][iy] == -1) {
                d[ix][iy] = ndist;
                move[ix][iy] = i;

                q.push(mp(ix, iy));
//                log << "Push: " << nx << " " << ny << endl;
            }
        }
    }
}

string solve(int x, int y) {
    if (d[x + OFF][y + OFF] == -1)
        cerr << "OOPS!";

    string res;
    int ix = x + OFF, iy = y + OFF;
    while (ix != OFF || iy != OFF) {
        int count = d[ix][iy];
        int mv = move[ix][iy];
        //log << "c: " << count << "mv :" << mv << " x: " << ix - OFF << " y: " << iy - OFF <<  endl;
        res.push_back(dir[mv]);
        ix -= dx[mv] * count;
        iy -= dy[mv] * count;
    }

    reverse(res.begin(), res.end());
    return res;
}

void printmatrix() {
    for (int i = -10; i <= 10; ++i) {
        for (int j = -10; j <= 10; ++j)
            log << d[j + OFF][i + OFF] << " ";
        log << endl;
    }

}
int main() {
    int T;
    cin >> T;

    precomp();
    printmatrix();
    for (int t = 1; t <= T; ++t) {
        int x, y;
        cin >> x >> y;
        string res = solve(x, y);
        cout << "Case #" << t << ": " << res << endl;
    }

    return 0;
}

