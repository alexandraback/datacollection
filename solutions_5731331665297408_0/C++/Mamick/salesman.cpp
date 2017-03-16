#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

vector<pair<int, int> > zips;
bool flight[55][55];
int visited[55];
// vector<int> visit;
// int visitcount = 0;
int next = 0;
int n;
vector<int> order;
map<int, int> citytozip;

bool visitWorks() {
    if (next == n) return true;
    int here = order[next];
    while (next == 0 || flight[order[next-1]][order[next]]) {
        next++;
        visitWorks();
        if (next == n) return true;
        else {
            while (flight[here][order[next]]) {
                next++;
                visitWorks();
                if (next == n) return true;
            }
        }
    }
    return false;
}

bool visitDo(int l) {
    if (l == 0) {
        next = 0;
        // for (int i = 0; i < order.size(); i++) {
        //     cout << order[i] << " ";
        // }
        // cout << endl;
        visitWorks();
        // cout << next << endl;
        if (next == n) return true;
        return false;
    }
    for (int i = 0; i < n; i++) {
        int tmp = zips[i].second;
        if (visited[tmp]) continue;
        visited[tmp] = true;
        order.push_back(tmp);
        if (visitDo(l-1)) return true;
        order.pop_back();
        visited[tmp] = false;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    for (int cases = 1; cases <= t; cases++) {
        int  m;
        cin >> n >> m;
        memset(flight, 0, sizeof(flight));
        order.clear();
        zips.clear();
        citytozip.clear();
        // visit.clear();
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            zips.push_back(make_pair(tmp, i+1));
            citytozip[i + 1] = tmp;
        }
        sort(zips.begin(), zips.end());
        for (int i = 0; i < m; i++) {
            int a,b;
            cin >> a >> b;
            flight[a][b] = true;
            flight[b][a] = true;
        }
        visitDo(n);
        cout << "Case #" << cases << ": ";
        for (int i = 0; i < order.size(); i++) {
            cout << citytozip[order[i]];
        }
        cout << endl;
    } 
}