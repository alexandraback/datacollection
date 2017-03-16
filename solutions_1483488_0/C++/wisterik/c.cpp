#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream>

#define rep(i,n) for(int i = 0; i < n; i++)
#define SZ(v) ((int)(v).size())
#define pb push_back
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef vector<int> vi;

bool used[2000005];

int toInt(string s){ stringstream ss; ss << s; int ans; ss >> ans; return ans; }

string toString(int i){ stringstream ss; ss << i; return ss.str(); }

int solve(int a, int b){

  int ans = 0;
  memset(used, false, sizeof(used));

  for(int i = a; i <= b; i++){

    if(used[i]) continue;
    used[i] = true;

    string s = toString(i);
    int cnt = 0;
    rep(_, SZ(s)){
      rotate(s.begin(), s.begin()+1, s.end());
      int x = toInt(s);
      if(x < a || x > b || used[x]) continue;
      used[x] = true;
      cnt++;
    }

    ans += cnt * (cnt+1) / 2;
    
  }

  return ans;

}

int main(){

  int t;
  cin >> t;

  rep(i,t){
    int a,b;
    cin >> a >> b;
    cout << "Case #" << i+1 << ": " << solve(a,b) << endl;
  }
  return 0;

}
