#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
  int t;
  cin >> t;
  for(int i = 0;i<t;i++){
    map<string,int> a,b;
    map<string,bool> l,r;
    vector<pair<string,string> > v;
    int n;
    cin >> n;
    int  t = 0;
    for(int j = 0;j<n;j++){
      string x,y;
      cin >> x >> y;
      a[x]++;
      b[y]++;
      v.push_back(make_pair(x,y));
    }
    for(auto j : v){
      if(a[j.first] > 1 && b[j.second] > 1){
        t++;
        if(!l[j.first]){
          a[j.first]--;
          l[j.first] = true;
        }
        if(!r[j.second]){
          b[j.second]--;
          r[j.second] = true;
        }
      }
    }
    cout << "Case #" << i+1 << ": " << t << endl;
  }
}
