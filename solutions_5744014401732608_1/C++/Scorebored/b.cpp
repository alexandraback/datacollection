#include <bits/stdc++.h>
using namespace std;

static const int dbg = 0;
#define dout if(dbg)cout


void solve(int N) {
    cout << "Case #" << N << ": ";
    unsigned long long nodes, goal;
    cin >> nodes >> goal;
    vector<unsigned long long> dynprog(nodes, 1ULL);
    vector<vector<bool>> answer(nodes, (vector<bool>(nodes, false)));
    //solution here
    int currentgoal = goal;
    for(int i=2; i<nodes; ++i) {
        dynprog[i]=dynprog[i-1]*2ULL;
        dout << i << " : " << dynprog[i] << endl;
    }
    for(int i=0; i<(nodes-1); ++i) { //targets
        for(int j=0; j<i; ++j) { //sources
            answer[j][i] = true;
        }
    }
    if(dynprog[nodes-1]<goal) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for(int i=nodes-2; i>=0; --i) {
        if(dynprog[i] <= goal) {
            goal -= dynprog[i];
            answer[i][nodes-1]=true;
        }
    }
    cout << "POSSIBLE" << endl;
    for(int i=0; i<nodes; ++i) {
        for(int j=0; j<nodes; ++j) {
            if(answer[i][j]) cout << "1";
            else cout << "0";
        }
        cout << endl;
    }
}

int main() {
    int testcases = 0;
    cin >> testcases;
    for(int i=0; i<testcases; ++i) {
        solve(i+1);
    }
}
