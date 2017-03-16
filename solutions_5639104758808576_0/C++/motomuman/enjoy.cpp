#include<bits/stdc++.h>
using namespace std;



void solve(int CASE){
  int S;
  cin >> S;
  string st;
  cin >> st;
  int num = 0;
  int ans = 0;
  for(int i = 0; i < st.size(); i++){
    if(i <= num){
      num += st[i]-'0';
    }else{
      ans += abs(i- num);
      num += abs(i- num);
      num += st[i]-'0';
    }
  }
  cout <<"Case #" << CASE<< ": " <<  ans << endl;
}


int main(){
  int N;
  cin >> N;
  for(int i = 0; i < N; i++){
    solve(i+1);
  }
}

