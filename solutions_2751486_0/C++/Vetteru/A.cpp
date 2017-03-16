#include<iostream>

using namespace std;

bool isVowel(char c){
  string vowel = "aiueo";

  for(int i = 0; i < vowel.length(); i++)
    if(vowel[i] == c) return true;
  return false;
}

bool isValid(string s, int v){
  int m = 0;
 
  for(int i = 0; i < s.length(); i++){
    int tmp = 0;
    for(int j = i; j < s.length(); j++){
      if(isVowel(s[j])) break;
      tmp++;
    }
    m = max(m,tmp);
  }
  // cout << "s " << s << " " << tmp << endl;
  return m >= v;
}
int solve(){
  string s;
  int n;
  cin >> s >> n;
  int ans = 0;

  for(int i = 0; i < s.length(); i++)
    for(int j = 1; j < s.length()-i+1; j++)
      if(isValid(s.substr(i,j),n)) ans++;

  return ans;
}

int main(){
  int T;
  cin >> T;
  for(int x = 0; x < T; x++){
    cout << "Case #" << x+1 << ": " << solve() << endl;
  }
  return 0;
}
