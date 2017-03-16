#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <cstring>
using namespace std;

int dp[1010][1010];

int main(){

  int T;
  ifstream in;
  ofstream out;
  
  in.open("a.in");
  out.open("a.out");
  in >> T;
  
  for(int tt=1; tt<=T; tt++){
  
    int N;
    in >> N;
    vector<vector<int> > adj_list;
    adj_list.resize(N);
    for(int i=0; i<N; i++){
      int M;
      in >> M;
      for(int j=0; j<M; j++){
        int a;
        in >> a;
        adj_list[i].push_back(a-1);
      }
    }
  
    memset(dp,0,sizeof(dp));
    
    for(int i=0; i<N; i++){
      for(int j=0; j<adj_list[i].size(); j++){
        dp[i][adj_list[i][j]] = 1;
      }
    }
  
    // i from j
    for(int k=0; k<N; k++){
      for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
          if(i==j)
            continue;
          dp[i][j] = dp[i][j]+ dp[i][k]*dp[k][j];
          if(dp[i][j] > 2)
            dp[i][j] = 2;
        }
      
      }
    
    }
  
    bool pass = false;
    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
        if(dp[i][j] > 1)
          pass = true;
    
    if(pass)
      out << "Case #" << tt << ": Yes" << endl;
    else
      out << "Case #" << tt << ": No" << endl;
  
  }

}
