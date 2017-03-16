#include <iostream>
#include <deque>
#include <bitset>
#include <cstring>

using namespace std;

bitset<200> v;
int go(int l, int r, bool b){
  if(l>r)
    return 0;
  if(v[r]!=b)
    return go(l,r,!b)+1;
  while(l<=r && b==v[r])
      r--;
  return min(go(l,r,b),1+go(l,r,!b));
}

int main(){
  int t;
  cin >> t;
  for(int i = 0;i<t;i++){
    string s;
    cin >> s;
    v.reset();
    bool b = true;
    deque<bool> d;
    for(int j =0;j<s.size();j++)
      v[j] = (s[j]=='+');
    cout << "Case #" << i+1 << ": "<< go(0,s.size()-1,true) << endl;
  }
  return 0;
}
