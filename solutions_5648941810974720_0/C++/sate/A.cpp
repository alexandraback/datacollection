#include<bits/stdc++.h>
using namespace std;

string S[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
int main(){
  int T; cin >> T;
  for(int ttt=1;ttt<=T;ttt++){
    cout << "Case #" << ttt << ": ";
    string s; cin >> s;
    int C[300]={};
    for(int i=0;i<(int)s.size();i++){
      C[s[i]]++;
    }
    int res[10]={};
    string X = "ZWUFXVGIOT";
    int R[]={0,2,4,5,6,7,8,9,1,3};
    for(int i=0;i<10;i++){
      res[R[i]] = C[X[i]];
      int p = C[X[i]];
      for(int j=0;j<(int)S[R[i]].size();j++){
        C[S[R[i]][j]]-= p;
      }
    }
    for(int i=0;i<10;i++) {
      for(int j=0;j<res[i];j++)
        cout << i;
    }
    cout << endl;
  }
}
