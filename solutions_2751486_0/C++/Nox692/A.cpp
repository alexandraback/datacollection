#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
using namespace std;

bool isVowel(char c){
  if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') return true;
  return false;
}

int main(){
  int N;
  cin >> N;
  for(int cs = 1 ; cs <= N ; cs++){
    string s;
    int n;
    cin >> s >> n;
    vector<string> v;
    for(int i = 0 ; i < s.size() ; i++){
      for(int j = i ; j <= s.size() ; j++){
	int cnt = 0, con=-1;
	for(int k = i ; k < j ; k++){
	  if(!isVowel(s[k])) cnt++;
	  else cnt = 0;
	  con = max(cnt, con);
	}
	if(con >= n){
	  //cout << s.substr(i, j) << endl;
	  v.push_back(s.substr(i, j));	
	}
      }
    }
    cout << "Case #" << cs << ": " << v.size() << endl;
  }
  return 0;
}
