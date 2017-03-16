#include<bits/stdc++.h>
using namespace std;

vector<int> dp(1000001, 0);

void init(){
    dp[1] = 1;
    
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur + 1 <= 1000000 && dp[cur + 1] == 0){
            dp[cur + 1] = dp[cur] + 1;
            q.push(cur + 1);
        }
        
        string tmp = to_string(cur);
        reverse(tmp.begin(), tmp.end());
        int rev = atoi(tmp.c_str());
        if(rev <= 1000000 && dp[rev] == 0){
            dp[rev] = dp[cur] + 1;
            q.push(rev);
        }
    }
}

int main(){
    init();
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int n;
        cin >> n;
        printf("Case #%d: %d\n", t, dp[n]);
    }
    return 0;
}
