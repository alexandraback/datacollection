#include <bits/stdc++.h> 
using namespace std; 
bool vis[5000010] ; 
int dp[5000010];
int reverse(int n){
    int ret = 0 ; 
    while(n){
        ret = ret*10 + n%10 ; 
        n /= 10 ; 
    }   
    return ret ;
}

int main(){
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    ios_base::sync_with_stdio(0) ;
    int tc,N; 
    cin >> tc;
    for(int i = 1 ; i<= 5000000 ; ++i){
        dp[i] = 1000000000;
        vis[i]=false;
    }
    for(int t = 1 ; t <= tc ; ++t){
        cout << "Case #"<<t<<": " ; 
        cin >> N ;
        deque<int> bfs ;
        bfs.push_back(1) ;
        dp[1] = 0 ; 
        for(int i = 1 ; i <= 1000000 ; ++i){
            vis[i] = false; 
        }
        while(!bfs.empty()){
            int curr = bfs.front() ;
            bfs.pop_front() ; 
           // cout << curr << "\n" ; 
            if(curr==N){
                break ; 
            }
            vis[curr] = true ;
            int rev = reverse(curr) ; 
            if(!vis[curr+1]){
                dp[curr+1] = min(dp[curr]+1,dp[curr+1]);
                vis[curr+1] = true ;
                bfs.push_back(curr+1) ; 
            }
            if(!vis[rev]){
                bfs.push_back(rev) ; 
                vis[rev] = true; 
                dp[rev] = min(dp[rev] , dp[curr]+1);
            }
        }
        cout << dp[N] + 1 << "\n" ; 
    }
    return 0 ;
}