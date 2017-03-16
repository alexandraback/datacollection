#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <sstream>
#include <functional>
using namespace std;

int main(){
  int t;
  cin >> t;
  for(int tidx = 1; tidx <= t; tidx++){
    int a,b; cin >> a >> b;
    map< string ,int > tab;
    for(int i=a; i<=b; i++){
      stringstream ss;
      string str;
      ss << i ;
      ss >> str;
      vector<string> tmp;
      for(int j=0; j<(int)str.size(); j++){
	string k = str.substr(j) + str.substr(0,j);
	tmp.push_back(k);
      }
      sort(tmp.begin(),tmp.end(),greater<string>());
      string c = tmp[0];
      if( tab.find(c) == tab.end()){
	tab.insert( make_pair(c,1) );
      } else {
	tab[c]++;
      }
    }
    long long int ans = 0;
    map< string ,int >::iterator it;
    for(it = tab.begin(); it != tab.end(); it++){
      int num = it->second;
      if( num >= 2 ){
	ans += num * (num - 1) / 2;
      }
    }
    cout << "Case #" << tidx << ": " << ans << endl;
  }
  return 0;
}
