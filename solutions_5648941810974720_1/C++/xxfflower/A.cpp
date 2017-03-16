#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
  int t, N, n;
  int ans = 0;
  string line;

  vector<string> S{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
  vector<char> U{'Z', 'X', 'U', 'G', 'W', 'T', 'O', 'F', 'I', 'S'};
  vector<int>  I{0, 6, 4, 8, 2, 3, 1, 5, 9, 7};

  cin>>t;
  getline(cin, line);
  for(int c=1;c<=t;++c)
  {
    map<int, int> count;
    map<int, int> ans;

    getline(cin, line);    

    for(auto ch : line)
      ++count[ch];

    for(int k=0;k<10;++k) {
      int d = count[U[k]];
      if(d>0) {
        ans[I[k]] = d;
        for(auto ch : S[I[k]])
          count[ch] -=d;
      }
    }

    cout<<"Case #"<<c<<": ";

    for(int i=0;i<10;++i)
      for(int j=0;j<ans[i];++j)
        cout<<i;
    
    cout<<endl;  
  }   

  return  0;
}