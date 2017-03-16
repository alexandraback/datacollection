#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RANGE(i,b,e) for(int (i)=(b);(i)<(int)(e);(i)++)
#define CRANGE(i,b,e) for(int (i)=(b);(i)<=(int)(e);(i)++)
#define RRANGE(i,b,e) for(int (i)=(b);(i)>=(int)(e);(i)--)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define PI 3.1415926535897932384626433832795
#define INF 0x7FFFFFFF

int T;
int R, C, M;
int I, J;
char mine[52][52];
bool ok;

void print()
{
    char tmp = mine[I][J];
    mine[I][J] = 'c';
    REP(i, R) {
        REP(j, C) {
            cout << mine[i][j];
        }
        cout << endl;
    }
    mine[I][J] = tmp;
}

int count()
{
    int cnt = 0;
    REP(i, R) REP(j, C) cnt += (mine[i][j] == '*');
    return cnt;
}

void solve(int i, int j)
{
    if (count() == M) {
        //cout << "Success" << endl;
        print();
        ok = true;
        return;
    } else if (count() < M) {
        return;
    }

    vector<pair<int, int> > vpair;
    vector<char> vchar;
    for (int di = -1;di <= 1;di++) {
        for (int dj = -1;dj <= 1;dj++) {
            if (di == 0 && dj == 0) continue;
            if (mine[i + di][j + dj] != '*') continue;
            if (i + di >= 0 && i + di < R && j + dj >= 0 && j + dj < C) {
                vpair.push_back(make_pair(i + di, j + dj));
                vchar.push_back(mine[i + di][j + dj]);
                mine[i + di][j + dj] = '.';
            }
        }
    }
    for (auto p : vpair) {
        solve(p.first, p.second);
        if (ok) return;
    }
    for (int k = 0;k < vpair.size();k++) {
        pair<int, int> p = vpair[k];
        mine[p.first][p.second] = vchar[k];
    }
}

int main(int argc, char **argv)
{
    cin >> T;
    for (int t = 0;t < T;t++) {
        cin >> R >> C >> M;
        REP(i, R) REP(j, C) {
            mine[i][j] = '*';
        }
        ok = false;

        cout << "Case #" << t + 1 << ": " << endl;
        REP(i, R) {
            REP(j, C) {
                I = i;
                J = j;
                char tmp = mine[i][j];
                mine[i][j] = '.';
                solve(i, j);
                if (ok) break;
                mine[i][j] = tmp;
            }
            if (ok) break;
        }
        if (!ok) cout << "Impossible" << endl;
    }

    return 0;
}
