#include <iostream>
#include <vector>
#include <map>

using namespace std;

int dig(int a){
  int d = 0;
  while(a){
    a = a / 10;
    d++;
  }
  return d;
}

int pow10(int n){
  int i, ret = 1;
  for(i = 0; i < n; i++)
    ret *= 10;
  return ret;
}

int rec(int a, int j){
  int b, ret, d;
  d = dig(a);
  if(j == 0)
    return a;
  b = a % pow10(j);
  a = a / pow10(j);
  ret = a +  b * pow10(d - j);
  return ret;
}

//viはsを要素して持つか
bool search(vector<int> vi, int s){
  int max = vi.size();
  for(int i = 0; i < max; ++i){
    if(vi.at(i) == s)
      return true;
  }
  return false;
}

int main(void){
  int a, b, t, t0, d;
  int ans;
  int n, m;
  map<int, vector<int> > mp;

  cin >> t;
  t0 = t;
  for( ;t-- ; ){
    ans = 0;
    cin >> a >> b;
    d = dig(a);
    for(int i = a; i < b; ++i){
      n = i;
      //      cout << n << endl;
      for(int j = 0; j < d; ++j){
        n = rec(i, j);
        for(int k = j + 1; k < d; ++k){//k = j + 1?
          m = rec(i, k);
          if(a <= n && n < m && m <= b){
            if(!search(mp[n], m)){
              ans++;
              mp[n].push_back(m);
               // cout << "(" << n << ", " << m << ")";
               // cout << " !OK";
               // cout << endl;
            }
          }
        }
      }
    }
    cout << "Case #" << t0 - t << ": " << ans << endl;
    for(int i = a; i <= b; ++i)
      mp.erase(i);
  }
  return 0;
}

