#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N;
vector<vector<int> > adj;
vector<bool> visited;
int nvisited;
vector<string> zip;
string minzip;

void go(int cityfrom, string actsofar, vector<int> canreturn, string zipsofar) {
    // figure out whether this is first-time visit or return one
    bool firsttimevisit = false;
    string newzip;
    if (!visited[cityfrom]) {
        firsttimevisit = true;
        visited[cityfrom] = true;
        ++nvisited;
        // will mark zip-code
        newzip = zipsofar + zip[cityfrom];
    } else {
        newzip = zipsofar;
    }
    // if this is last city to be visited, zipsofar + current zip as possible outcome
    if (nvisited == N) {
        if (minzip == "" || minzip > newzip) {
            minzip = newzip;
//            cerr << actsofar << " " << newzip << endl;
        }
    }
    else {
        // or try going to each unvisited yet neighbor OF THIS CITY
        string newact;
        for (int j = 0; j < adj[cityfrom].size(); ++j) {
            int cityto = adj[cityfrom][j];
            if (!visited[cityto]) {
                newact = actsofar + char('0' + cityto);
                canreturn.push_back(cityto);
                go(cityto, newact, canreturn, newzip);
                canreturn.pop_back();
            }
        }
        // or try returning to previously visited city, if can (while keeping this one visited)
        newact = actsofar + 'r';
        if (canreturn.size() > 1) {
            canreturn.pop_back();
            go(canreturn[canreturn.size() - 1], newact, canreturn, newzip);
        }
    }
    
    if (firsttimevisit) {
        // unmark this city as visited
        visited[cityfrom] = false;
        --nvisited;
    }
}

void solve(int ind) {
    // input
    int M;
    cin >> N >> M;
    zip = vector<string>(N);
    for (int i = 0; i < N; ++i) {
        cin >> zip[i];
    }
    adj = vector<vector<int> >(N, vector<int>(0));
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // we can always start with the city with the smallest zip (and go to the smallest of its neighbors)
    int startc = 0;
    for (int i = 1; i < N; ++i) {
        if (zip[i] < zip[startc]) {
            startc = i;
        }
    }
    visited = vector<bool>(N, false);
    nvisited = 0;
    minzip = "";
    string start = "";
    start += char('0' + startc);
    go(startc, start, vector<int>(1, startc), "");
    
    // output
    cout << "Case #" << ind << ": " << minzip << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        solve(i);
    }
}