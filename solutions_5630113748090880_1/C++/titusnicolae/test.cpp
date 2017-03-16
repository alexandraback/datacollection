#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <map>
using namespace std;

int main (int argc, char* argv[]) {
  ifstream fin(argv[1]);
  ofstream fout("output.txt");
  int t,n,e;
  fin>>t; 
  for(int i=0;i<t;i++) {
    fin>>n;
    map<int,int> m;
    for(int j = 0; j < 2*n-1;j++) {
      for(int k = 0; k<n; k++) {
        fin>>e; 
        m[e]++;
      }
    }
    vector<int> ll;
    for(auto& kv:m) {
      if(kv.second%2==1) {
        ll.push_back(kv.first);
      } 
    }
    sort(ll.begin(), ll.end());
    fout<<"Case #"<<i+1<<": ";
    for(auto& e: ll) {
      fout<<e<<" ";
    }
    fout<<endl;
  }
  return 0;
}
