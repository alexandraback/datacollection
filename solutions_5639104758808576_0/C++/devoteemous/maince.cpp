#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> ParseString(string s, string d) {
  size_t pos = 0;
  std::string token;
  vector<string> vec;
  
  while ((pos = s.find(d)) != std::string::npos) {
    token = s.substr(0, pos);
    vec.push_back(token);
    s.erase(0, pos + d.length());
  }
  vec.push_back(s);
  return vec;
}

vector<int> seperate_into_digits(unsigned int value) {
    vector<int> digits;
    for( ; value > 0; value /= 10) digits.push_back(value % 10);
    reverse( digits.begin(), digits.end() ) ;
    return digits;
}   

int main(int argc, char** argv) {
  // ifstream ifi("input.txt");
  ifstream ifi("A-small-attempt2.in");
  int cn;
  ifi >> cn;
  vector<int> smax(cn);
  string line;  
  getline(ifi, line);
  vector<int> s(cn);
  for (int i = 0; i < cn; i++) {
    string line;
    getline(ifi, line);
    vector<string> vec = ParseString(line, " ");
    if (vec.size() == 1) {
      smax[i] = atoi(vec[0].c_str());
      s[i] = -1;
    } else {
      smax[i] = atoi(vec[0].c_str());
      s[i] = atoi(vec[1].c_str());
    }     
  }  
  ifi.close();
  vector<int> ans(cn, 0);
  for (int i = 0; i < cn ; i++) {
    if (s[i] == -1) continue;
    vector<int> vec = seperate_into_digits(s[i]);
    int lzn = smax[i] + 1 - vec.size();
    if (lzn > 0) vec.insert(vec.begin(), lzn, 0);
    int up = vec[0];
    for (int j = 1; j < smax[i] + 1; j++) {      
      int num = vec[j];
      int need = j - up;
      if (need > 0) {
        ans[i] += need;
        up += need;
      }
      up += num;      
    }
  }
  ofstream ofi("output.txt");
  for (int i = 0; i < cn; i++) {    
    ofi << "Case #" << i + 1 << ": " << ans[i] << endl;
  }
  ofi.close();
  return 0;
}