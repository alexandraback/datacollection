#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

string toStr(int i, int n){
  stringstream ss;
  ss << setw(n) << setfill('0') << i;
  return ss.str();
}

bool match(string a, string b){
  int n = a.size();
  for(int i = 0; i < n; ++i){
    if(a[i] == '?') continue;
    if(a[i] != b[i]) return false;
  }
  return true;
}

int main(){ IO;
  int t;
  cin >> t;

  for(int ncase = 1; ncase <= t; ++ncase){
    cout << "Case #" << ncase << ": ";
    
    string I, J;
    cin >> I >> J;

    int n = I.size();

    vector<string> v;
    for(int i = 0; i < 1000; ++i){
      string ii = toStr(i, n);
      v.push_back(ii);
    }
    
    int diff = INT_MAX;
    int a, b;
    for(int i = 0; i < 1000; ++i){
      string ii = v[i];
      if(ii.size() != n) continue;
      for(int j = 0; j < 1000; ++j){
        string jj = v[j];
        if(jj.size() != n) continue;
        if(match(I, ii) and match(J, jj)){
          if(abs(i - j) < diff){
            a = i;
            b = j;
            diff = abs(a - b);
          }else if(abs(i - j) == diff){
            if(i < a){
              a = i;
              b = j;
              diff = abs(a - b);
            }else if(i == a){
              if(j < b){
                a = i;
                b = j;
                diff = abs(a - b);
              }
            }
          }
        }
      }
    }

    cout << v[a] << " " << v[b] << endl;
  }

  return 0;
}
