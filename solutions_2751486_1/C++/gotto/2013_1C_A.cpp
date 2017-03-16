#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<int> v;
int main(void){
  int T;
  cin >> T;
  for(int k = 1; k <= T; k++){
    string s;
    int n;
    cin >> s >> n;
    int c = 0;
    v.clear();
    for(int i = 0; i < (int)s.size(); i++){
      if(s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o'){
	c = 0;
	continue;
      }else{
	c++;
	if(c >= n){
	  v.push_back(i-n+1);
	}
      }
    }
    long long ret = 0;
    int j = 0;
    for(int i = 0; i < (int)s.size(); i++){
      if(v[j] < i) j++;
      if((int)v.size() <= j) break;
      ret += (int)s.size()-v[j]-n+1;
    }
    cout << "Case #" << k << ": " << ret << endl;
  }
}
