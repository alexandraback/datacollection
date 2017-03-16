#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << (x) << endl;

const int MAX_XY = 220;
string INF_S;
int T, X, Y;
map < pair<int, int>, string > memo;
int n_covered;

bool valid(pair<int, int> p) {
    return abs(p.first <= 120) && abs(p.second <= 120);
}

int main() {
    for(int i = 0; i < 1000; i++)
        INF_S += 'X';
    queue< pair<int, int> > q;
    pair<int, int> start (0, 0);
    q.push(start);
    for(int jump = 1; jump < 510; jump++) {
        // DEBUG(jump);
        int n_points = q.size();
        for(int i = 0; i < n_points; i++) {
            pair<int, int> point = q.front(); q.pop();
            pair<int, int> north (point.first, point.second + jump);
            pair<int, int> south (point.first, point.second - jump);
            pair<int, int> east (point.first + jump, point.second);
            pair<int, int> west (point.first - jump, point.second);
            if(memo.find(north) == memo.end()) {
                memo[north] = memo[point] + "N";
                n_covered += valid(north);
                q.push(north);
            }
            if(memo.find(south) == memo.end()) {
                memo[south] = memo[point] + "S";
                n_covered += valid(south);
                q.push(south);
            }
            if(memo.find(east) == memo.end()) {
                memo[east] = memo[point] + "E";
                n_covered += valid(east);
                q.push(east);
            }
            if(memo.find(west) == memo.end()) {
                memo[west] = memo[point] + "W";
                n_covered += valid(west);
                q.push(west);
            }
        }
        if(n_covered >= 500 * 500) break;
    }
    cin >> T;
    for(int Ti = 1; Ti <= T; Ti++) {
        cin >> X >> Y;
        cout << "Case #" << Ti << ": " << memo[make_pair(X, Y)] << endl;
    }
}