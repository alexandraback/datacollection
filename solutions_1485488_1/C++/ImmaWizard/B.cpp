#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <cassert>
#include <limits>
#include <map>
#define FOREACH(it, C) for(typeof((C).begin()) it = (C).begin(); it != (C).end(); ++it)
using namespace std;
typedef long long int ll;


int h;
int n, m;
vector<vector<int> > ceiling;
vector<vector<int> > floor;
bool before = true;

struct pos {
    int y;
    int x;
    int c;
};

bool operator<(const pos& lhs, const pos& rhs) {
    return lhs.c > rhs.c;
}

pos make_pos(int y, int x, int c) {
    pos result;
    result.y = y;
    result.x = x;
    result.c = c;
    return result;
}

bool can_pass(const pos &src, pos &dest) {
    if(dest.y < 0 || dest.y >= n || dest.x < 0 || dest.x >= m)
        return false;
    int water_level = max(0, h - src.c);
    int src_floor = floor[src.y][src.x];
    int src_ceiling = ceiling[src.y][src.x];
    int dest_floor = floor[dest.y][dest.x];
    int dest_ceiling = ceiling[dest.y][dest.x];
    dest.c = src.c;
    if(water_level > dest_ceiling - 50) {
        if(before) {
            return false;
        } else {
            //cout << "Lowering the water level:" << endl;
            int water_diff = water_level - (dest_ceiling - 50);
            //cout << "Current: " << water_level << " ";
            dest.c += water_diff;
            water_level = dest_ceiling - 50;
            //cout << "New: " << water_level << " diff: " << water_diff << endl;
        }
    }
    if(!before) {
        if(water_level - src_floor >= 20) {
            dest.c += 10;
        } else {
            dest.c += 100;
        }
    }
    if(src_floor > dest_ceiling - 50)
        return false;
    if(dest_floor > dest_ceiling - 50)
        return false;
    if(dest_floor > src_ceiling - 50)
        return false;
    return true;
}


void dijkstra(priority_queue<pos> &q, vector<vector<int> > &best) {
    int sides[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(!q.empty()) {
        pos cur = q.top();
        q.pop();
        if(cur.c > best[cur.y][cur.x]) {
            continue;
        }
        for(int i = 0; i < 4; ++i) {
            pos next = make_pos(cur.y + sides[i][0], cur.x + sides[i][1], cur.c);
            if(can_pass(cur, next)) {
                if(next.c < best[next.y][next.x]) {
                    best[next.y][next.x] = next.c;
                    q.push(next);
                }
            }
        }
    }
    return;
}
int solve() {
    vector<vector<int> > best(n, vector<int>(m, numeric_limits<int>::max()));
    priority_queue<pos> q;
    best[0][0] = 0;
    q.push(make_pos(0, 0, 0));
    dijkstra(q, best);
    before = false;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(best[i][j] < numeric_limits<int>::max()) {
                q.push(make_pos(i, j, best[i][j]));
            }
        }
    }
    dijkstra(q, best);
    return best[n - 1][m - 1];
}

int main() {
    int numberOfCases;
	cin >> numberOfCases;
	for(int testCase = 1; testCase <= numberOfCases; ++testCase) {
        before = true;
        floor.clear();
        ceiling.clear();
        cin >> h >> n >> m;
        ceiling.resize(n, vector<int>(m));
        floor.resize(n, vector<int>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> ceiling[i][j];
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> floor[i][j];
            }
        }
        int res = solve();
		cout << "Case #" << testCase << ": " << res / 10 << "." << res % 10 << endl;
	}
}
