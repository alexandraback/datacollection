#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int S = 50;
const int INF = 10000000;

vector<string> dic;

main(){
  ifstream ifs("garbled_email_dictionary.txt");
  string in;
  while(ifs >> in){
    dic.push_back(in);
  }
  int T;
  cin >> T;
  for(int t=1;t<=T;t++){
    string s;
    cin >> s;
    int size = s.size();
    int dp[S][S];
    fill(dp[0], dp[S], INF);
    vector<string> data;
    for(int i=0;i<size;i++) data.push_back(s.substr(i));
    for(int i=0;i<size;i++){
      for(int j=0;j<dic.size();j++){
        if(dic[j].size() <= data[i].size()){
          int cnt = 0;
          int pre = -1;
          for(int k=0;k<dic[j].size();k++){
            if(dic[j][k] != data[i][k]){
              cnt++;
              if(pre == -1) pre = k;
              else if(abs(pre - k) < 5){
                cnt = INF;
                break;
              }
            }
          }
          dp[i][i+(int)dic[j].size()-1] = min(dp[i][i+(int)dic[j].size()-1], cnt);
        }
      }
    }
    for(int i=0;i<size;i++){//length
      for(int j=0;j+i<size;j++){//start
        for(int k=j;k<i+j;k++){
          dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j]);
        }
      }
    }
    int ans = min(size, dp[0][size-1]);
    cout << "Case #" << t << ": " << ans << endl;
  }
}
