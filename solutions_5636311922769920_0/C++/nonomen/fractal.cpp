#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main(){
  int t;
  cin >> t;
  for(int i =0;i<t;i++){
    int k,c,s;
    cin >> k >> c >> s;
    vector<long long> req;
    for(int x = 0;x<k;x++){
      long long r = x;
      for(int y = 1;y<c;y++){
        r*=k;
        x++;
        x = min(x,k-1);
        r += x;
      }
      req.push_back(r);
    }
    cout << "Case #" << i+1 << ": ";
    if(req.size() > s)
      cout << "IMPOSSIBLE";
    else
      for(auto j : req)
        cout << j+1 << " ";
    cout << endl;
  }

  return 0;
}
