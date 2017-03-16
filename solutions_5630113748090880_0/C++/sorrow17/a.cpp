#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;
using std::set;
using std::endl;
using std::cout;
using std::map;

map<int, int> freq;

int main() {
  ifstream fin("b_in.txt");
  ofstream fout("b_out.txt");
  int T = 0;
  fin >> T;
  for (int i = 0; i<T; i++) {
    int n;
    fin >> n;
    freq.clear();
    for (int j=0; j<2*n-1; j++) {
      for (int k=0; k<n; k++) {
        int tmp;
        fin >> tmp;
        if (freq.find(tmp)==freq.end())
          freq[tmp] = 1;
        else
          freq[tmp]++;
      }
    }
    vector<int> ans;
    for (auto const& p: freq) {
      //cout << p.first << ' ' << p.second << endl;
      if (p.second%2==1)
        ans.push_back(p.first);
    }
    if (ans.size()!=n) cout <<i<< " hit "<< ans.size() << ' ' <<n <<endl;
    std::sort(ans.begin(), ans.end());
    
    fout << "CASE #"<<i+1<<":";
    for (int p : ans)
      fout<<' '<<p;
    fout<<endl;
  }
  return 0;
}
