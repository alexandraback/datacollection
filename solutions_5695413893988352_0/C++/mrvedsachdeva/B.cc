#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

const int N = 4e5 + 5;
set<string> a, b;
bool check(string s){
    for(int i = 0;  i < s.length(); i++){
      if(s[i] == '?') return 0;
    }
    return 1;
}

void solve(string s){
  if(check(s)){
    a.insert(s);
    return;
  }

  for(int i = 0; i < s.length(); i++){
    if(s[i] == '?'){
      for(int j = '0'; j <= '9'; j++){
        s[i] = j;
        solve(s);
      }
    }
  }
}
void solve2(string s){
  if(check(s)){
    b.insert(s);
    return;
  }

  for(int i = 0; i < s.length(); i++){
    if(s[i] == '?'){
      for(int j = '0'; j <= '9'; j++){
        s[i] = j;
        solve2(s);
      }
    }
  }
}

int dif(string a, string b){
  int x = stoi(a);
  int y = stoi(b);
  return abs(x - y);
}

int main(){
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  for(int cs = 1; cs <= t; cs++){
    string s, t;
    cin >> s >> t;
    a.clear(), b.clear();
    solve(s);
    solve2(t);
    string ansx;
    string ansy;
    int mindif = INT_MAX;
    for(auto x: a){
      for(auto y : b){
        if(dif(x, y) < mindif){
          ansx = x;
          ansy = y;
          mindif = dif(x, y);
        }
      }
    }
    cout <<"Case #" << cs <<": " << ansx <<" " << ansy << endl;
  }
  return 0;
}
