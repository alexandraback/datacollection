#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cmath>

using namespace std;

typedef long long ll;
string ans_a;
string ans_b;

ll compute_dis(const string& a, const string& b) {
  ll a1 = 0;
  ll b1 = 0;
  for(int i=0;i<a.length();++i) {    
    if(a[i]=='?' || b[i] == '?')  {     
      break;
    }

    a1 += a[i] * pow(10, a.length() - i -1);
    b1 += b[i] * pow(10, a.length() - i -1);
  }

  ll dis = abs(a1 - b1);

  // cerr<<"dist "<<a<<" "<<b<<" = "<<dis<<endl;

  return dis;
}

int dfs(int s, string a, string b, ll& max_diff, int r = 1) {
  if(s == a.length()) {
    int dist = compute_dis(a, b);
    if(dist < max_diff) {
      max_diff = dist;
      ans_a = a;
      ans_b = b;
      cerr<<"ans = "<<a<<" "<<b<<" dist = "<<max_diff<<endl;
    }
    return 0;
  }

  if(a[s] == '?' && b[s] == '?') {        
    for(int i=0;i<=9;++i)  {
      a[s] = i+'0';
      for(int j=0;j<=9;++j) {      
        b[s] = j+'0';        
        dfs(s+1, a, b, max_diff);
      }
    }      
  } else if(a[s] == '?') {    
    for(int i=0;i<=9;++i) {      
        a[s] = '0' + i;        
        dfs(s+1, a, b, max_diff);
      }
  } else if(b[s] == '?') {    
    for(int i=0;i<=9;++i) {      
      b[s] = '0' + i;      
      dfs(s+1, a, b, max_diff);
    }
  } else {
    dfs(s+1, a, b, max_diff, 0);
  }
}

int main() {
  int t, N, n;
  int ans = 0;
  string line;
  
  cin>>t;  
  for(int c=1;c<=t;++c)
  {
    string a,b;
    cin>>a>>b;

    ll max_diff = 9*pow(10, 18);

    dfs(0, a, b, max_diff, 0);

    cout<<"Case #"<<c<<": "<<ans_a<<" "<<ans_b<<endl;    
  }   

  return  0;
}