#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;
using std::set;
using std::endl;
using std::cout;

string work(string str) {
  
  if (str.size()<=1) return str;
  int k = -1, max = -1;
  for (int i=str.size()-1; i>=0; i--) {
    if (str[i]>max) {
      k = i;
      max = str[i];
    }
  }
  cout<<k<<endl;
  return str[k]+work(str.substr(0, k))+str.substr(k+1, str.size()-k-1);
}
int main() {
  ifstream fin("a_in.txt");
  ofstream fout("a_out.txt");
  int T = 0;
  fin >> T;
  for (int i = 0; i<T; i++) {
    string str;
    fin >> str;
    fout << "CASE #"<<i+1<<": "<<work(str)<<endl;
  }
  return 0;
}
