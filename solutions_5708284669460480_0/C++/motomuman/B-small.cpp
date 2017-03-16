#include<bits/stdc++.h>
using namespace std;


long cal(string st, string ta){
  long ret = 0;
  if(st.size() < ta.size()){
    return 0;
  }
  for(int i = 0; i <= st.size() - ta.size(); i++){
    bool flag = true;
    for(int j = 0; j < ta.size(); j++){
      if(st[i+j] != ta[j]){
        flag = false;
        break;
      }
    }
    if(flag){
      ret++;
    }
  }
  return ret;
}



void solve(int CASE){
  double ans;
  int lK, lL, lS;
  string K, L;
  cin >> lK >> lL >> lS >> K >> L;
  queue<string> Q;
  for(int i = 0; i < lK; i++){
    string tmp = K.substr(i, 1);
    Q.push(tmp);
  }
  while(Q.front().size() != lS){
    string tmp = Q.front();
    Q.pop();
    for(int i = 0; i < lK; i++){
      Q.push(tmp+K[i]);
    }
  }
  long ma = 0;
  double sub = 0;
  double size = Q.size();
  while(!Q.empty()){
    long tmp = cal(Q.front(), L);
    ma = max(ma, tmp);
    sub += tmp/size;
    Q.pop();
  }
  printf("Case #%d: %.10f\n", CASE, (double)ma - sub);
}


int main(){
  long T;
  cin >> T;
  for(int i = 0; i < T; i++){
    solve(i+1);
  }
}

