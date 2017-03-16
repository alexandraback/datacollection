#include <iostream>
#include <set>
#include <functional>
#include <vector>
#include <cstring>

using namespace std;
int J, P, S, K;
int choose[3];

vector<vector<int>> v;

vector<int> current(3);
void DFS(int pos) {
    if (pos == 3) {
        v.push_back(current);
        return;
    }

    for (int i=0; i<choose[pos]; ++i) {
        current[pos] = i;
        DFS(pos + 1);
    }
}

int used[4][4][11][11];
int taken;
vector<size_t> bestTaken;
vector<size_t> curTaken;

bool donttake;

void DFS1(size_t pos) {
    if (pos == v.size()) {
        if (curTaken.size() > bestTaken.size()) {
            bestTaken = curTaken;
        }
        return;
    }

    // take it
    const vector<int>& cur = v[pos];
    
    if (!(used[0][1][cur[0]][cur[1]] == K || 
          used[1][2][cur[1]][cur[2]] == K ||
          used[0][2][cur[0]][cur[2]] == K)) {
        ++used[0][1][cur[0]][cur[1]];
        ++used[1][2][cur[1]][cur[2]];
        ++used[0][2][cur[0]][cur[2]];

        curTaken.push_back(pos);
        DFS1(pos + 1);
        curTaken.pop_back();

        --used[0][1][cur[0]][cur[1]];
        --used[1][2][cur[1]][cur[2]];
        --used[0][2][cur[0]][cur[2]];
    }

    // don't take it
    if (donttake)
    DFS1(pos + 1);
}


void solve(int test) {
    cout << "Case #" << test << ": ";

    cin >> J >> P >> S >> K;
    choose[0] = J;
    choose[1] = P;
    choose[2] = S;

    v.clear();

    DFS(0);

    //cerr << "v.size(): " << v.size() << endl;

    memset(used, 0, sizeof used);
    bestTaken.clear();
    curTaken.clear();

    donttake = true;
    if (K >= 3)
        donttake = false;
    DFS1(0);

    cout << bestTaken.size() << endl;
    for (const size_t index : bestTaken) {
        const vector<int>& cur = v[index];
        cout << cur[0] + 1 << ' ' << cur[1] + 1 << ' ' << cur[2] + 1 << endl;
    }
}

int main() {
    int t; cin >> t;
    for (int e=1; e<=t; ++e)
        solve(e);
}
