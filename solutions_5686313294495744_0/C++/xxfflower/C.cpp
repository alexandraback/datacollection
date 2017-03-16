#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <array>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int max_fakers;

void print(const map<string, int>& w) {
  for(auto kv : w) {
    cout<<kv.first<<":"<<kv.second<<" ";
  }
  cout<<endl;
}

// choose k from n
void dfs(int start, int d, int k, int n, set<int>& c, map<string, int>& f, map<string, int>& s, const vector<array<string,2>>& words) {
  if(d == k) {
    // cout<<"-------------------"<<endl;
    // cout<<"FIRST"<<endl;
    // print(f);
    // cout<<"SEC"<<endl;
    // print(s);
    // cout<<"*********************"<<endl;

    int fakers = 0;
    for(int i=0;i<n;++i) {
      if(c.count(i)) continue;
      auto& w1 = words[i][0];
      auto& w2 = words[i][1];
      if(f[w1] > 0 && s[w2] > 0) {
        cerr<<"faker = "<<w1<<" "<<w2<<endl;
        fakers++;
      }
    }

    if(fakers > max_fakers) max_fakers = fakers;
    return;
  }

  for(int i=start;i<n;++i) {
    c.insert(i);
    auto& w1 = words[i][0];
    auto& w2 = words[i][1];
    ++f[w1];
    ++s[w2];
    dfs(i+1, d+1, k, n, c, f, s, words);
    --f[w1];
    --s[w2];
    c.erase(i);
  }
}

int main() {
  int t, N, n;
  int ans = 0;
  string line;


  cin>>t;
  for(int c=1;c<=t;++c)
  {
    string a, b;

    cin>>n;

    vector<array<string,2>> words(n);

    for(int i=0;i<n;++i) {
      cin>>words[i][0]>>words[i][1];
    }    

    max_fakers = 0;

    for(int k=1;k<=n;++k) {
      map<string, int> f, s;
      set<int> ch; // chosen      
      dfs(0, 0, k, n, ch, f, s, words);      
    }

    cout<<"Case #"<<c<<": "<<max_fakers<<endl;  
  }

  return  0;
}