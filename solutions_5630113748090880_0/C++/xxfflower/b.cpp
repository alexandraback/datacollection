#include <iostream>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
  int t, N, n;
  int ans = 0;  

  cin>>t;

  for(int c=1;c<=t;++c)
  {
    map<int, int> count;
    set<int> ans; 
    int height;

    cin >> N;

    for(int i=0;i<2*N-1;++i)
      for(int j=0;j<N;++j)
      {
        cin>>height;
        ++count[height];
      }

      for(auto kv : count)
        if(kv.second % 2 == 1) ans.insert(kv.first);

    cout<<"Case #"<<c<<":";

    for(auto v : ans)
      cout<<" "<<v;
    cout<<endl;
  }

  return  0;
}