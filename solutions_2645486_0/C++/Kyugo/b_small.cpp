#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int E,R,N;
vector<int>v;

void dfs(int now,int e,int sum,int& res){

   if(now == N){
      res = max(res,sum);
      return;
   }

   for(int i = 0 ; i <= e ; i++){
      dfs(now+1,min(E,e-i+R),sum + i*v[now],res);
   }

}

void solve(){
   v.clear();
   cin >> E >> R >> N;
   for(int i = 0 ; i < N ; i++){
      int tmp; cin >> tmp; v.push_back(tmp);
   }
   int res = 0;
   dfs(0,E,0,res);
   cout << res << endl;
}

int main(){
   int tc;
   cin >> tc;
   for(int i = 1 ; i <= tc ; i++){
      cout << "Case #" << i << ": ";
      solve();
   }
   return 0;
}
