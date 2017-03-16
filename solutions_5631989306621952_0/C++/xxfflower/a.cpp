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
  string line;


  cin>>t;
  getline(cin, line);
  for(int c=1;c<=t;++c)
  {
    getline(cin, line);

    string ans;

    ans = line[0];

    for(int i=1;i<line.length();++i)
      if (line[i] >= ans[0]) ans = line[i] + ans;
      else ans += line[i];    

    cout<<"Case #"<<c<<": "<<ans<<endl;  
  }

  return  0;
}