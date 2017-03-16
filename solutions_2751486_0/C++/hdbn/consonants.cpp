#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

bool isConsonant(char c){
  bool isV = 'a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c;
  return (!isV);
}

int solve(const string & s, int n){
  vector<int> closest(s.size(), -1);
  int i, j, p, cnt, result;
  p = 0;
  result = 0;
  for(i = cnt = 0; i < s.size(); i++){
    char c = s[i];
    if(isConsonant(c)){
      cnt++;
      if(cnt >= n){
	while(p <= i - n + 1){
	  closest[p] = i; p++;
	}
      }
    } else {
      cnt = 0;
    }
  }
  for(i = 0; i < s.size(); i++){
    if(closest[i] >= 0)
      result += (s.size() - closest[i]);
  }
  return result;
}

int main(int argc, char * argv[]){
  int i, T, n;
  cin >> T;
  for(i = 1; i <= T; i++){
    string s;
    cin >> s >> n;
    int r = solve(s,n);
    cout << "Case #" << i << ": " << r << endl;
  }
}
