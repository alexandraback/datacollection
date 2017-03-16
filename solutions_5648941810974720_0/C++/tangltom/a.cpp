#include <bits/stdc++.h>
using namespace std;

string abc[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int cnt[10][30];
pair<char, int> to[] = {{'Z',0}, {'W',2}, {'U',4}, {'O',1}, {'X',6},{'G',8}, {'H',3}, {'F',5}, {'V',7}, {'E',9}};

void sub(vector<int> &v, int l, int factor=1){
  for(int i=0;i<26;i++){
    v[i] -= cnt[l][i]*factor;
  }
}

int main(){
  int T;
  cin>>T;
  for(int d=0;d<10;d++){
    for(char c:abc[d])
      cnt[d][c-'A']++;
  }
  for(int t=1;t<=T;t++){
    vector<int> total(26,0);

    string s;
    cin>>s;
    for(char c:s){
      total[c-'A']++;
    }
    vector<int> digits;
    for(auto t:to){
      while(total[t.first-'A']){
	digits.push_back(t.second);
	sub(total, t.second);
      }
    }

    sort(digits.begin(),digits.end());
    cout<<"Case #"<<t<<": ";
    for(int d:digits)
      cout<<d;
    cout<<endl;
  }
  return 0;
}
