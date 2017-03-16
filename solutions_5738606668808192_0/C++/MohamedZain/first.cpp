#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007

/*
*
* Zaiiiiiin
*
*/

using namespace std;

typedef pair<int,int> ii;

int f[1<<18], T, NN, JJ;
vector<int> p, sol;

string toBinary(int x, int l){
  l -= 2;
  string ret = "";
  while(x){
    ret.push_back((char)(x % 2 + '0'));
    x /= 2;
  }
  l -= ret.size();
  while(l--) ret.push_back('0');
  ret.push_back('1');
  reverse(ret.begin(), ret.end());
  ret.push_back('1');
  return ret;
}

ll toBaseN(string s, int N){
  ll ret = 0;
  for(int i=0; i<s.size(); i++){
    ret *= N;
    ret += s[i] == '1';
  }
  return ret;
}

bool isPrime(ll x){
  for(ll i=2, e=sqrt(x); i<=e; i++){
    if(x % i == 0){
      sol.push_back(i);
      return 0;
    }
  }
  return 1;
}

bool isValid(string s){
  sol.clear();
  for(int i=2; i<=10; i++)
    if(isPrime(toBaseN(s, i))) return 0;
  return 1;
}

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> T;
  while(T--){
    puts("Case #1:");
    cin >> NN >> JJ;
    int cnt = 0;
    int i;
    for(i=0; i<(1 << (NN - 2)) && cnt < JJ; i++){
      string a = toBinary(i, NN);
      if(isValid(a)){
        cnt++;
        cout << a;
        for(auto x: sol) cout << " " << x;
        puts("");
      }
    }

  }
  return 0;
}
