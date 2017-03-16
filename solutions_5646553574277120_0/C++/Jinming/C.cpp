#include<bits/stdc++.h>
using namespace std;

set<int> reachable;
vector<int> coins;

void backtrack(int i, int sum){
    if(i == coins.size()){
        reachable.insert(sum);
        return;
    }

    backtrack(i + 1, sum);
    backtrack(i + 1, sum + coins[i]);
}


int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        reachable.clear();
        coins.clear();
        int C, D, V;
        cin >> C >> D >> V;
        for(int i = 0; i < D; i++){
            int x;
            cin >> x;
            coins.push_back(x);
        }

        backtrack(0, 0);

        int ret = 0;
        for(int i = 1; i <= V; i++){
            if(reachable.find(i) == reachable.end()){
                ret++;
                coins.push_back(i);
                backtrack(0, 0);
            }
        }
        printf("Case #%d: %d\n", t, ret);
    }
    return 0;
}
