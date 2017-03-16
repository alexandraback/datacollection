
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>

using namespace std;

int charmap[] = { 24, 7, 4,18,14, 2,21,23, 3,20, 8, 6,11, 1,10,17,25,19,13,22, 9,15, 5,12, 0,16 };
int main(){
  string tmp;
  getline( cin , tmp );
  stringstream ss;
  ss << tmp;
  int n;
  ss >> n;
  for(int tidx = 1; tidx<=n; tidx++){
    string str;
    getline(cin,str);
    string ans = str;
    for(int i=0; i<(int)str.size(); i++){
      if( str[i] == ' ' )continue;
      int tmp = str[i] - 'a';
      ans[i] = charmap[tmp] + 'a';
    }
    printf("Case #%d: %s\n",tidx,ans.c_str());
  }
  return 0;
}
