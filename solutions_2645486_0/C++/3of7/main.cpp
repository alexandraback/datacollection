#include <cmath>
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int E, R, N, v[10];

int dfs(int i, int e, int mv) {
    if(i >= N) return mv;
    int m = 0;
    for(int u = 0; u <= e; u++) {
        int ne = std::min(e-u+R, E);
        m = std::max(m, dfs(i+1, ne, mv+v[i]*u));
    }
    return m;
}

int main() {
    int T;
    cin>>T;
    for(int casenum=1; casenum<=T; casenum++) {
        cin >> E >> R >> N;
        for(int n=0; n<N; n++) cin >> v[n];
        int ans = dfs(0, E, 0);
        cout<<"Case #"<<casenum<<": "<<ans<<endl;
    }
    return 0;
}