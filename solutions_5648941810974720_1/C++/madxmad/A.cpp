#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int order[] = {0, 2, 4, 6, 3, 5, 7, 8, 9, 1};
string number[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

bool take(vector<int> &v, int i){
  for(auto c : number[i]){
    v[c - 'A']--;

    if(v[c - 'A'] < 0){
      return false;
    }
  }

  return true;
}

bool takeAll(vector<int> &v, int i){
  int cnt = INT_MAX;
  for(auto c : number[i]){
    if(i == 3 and c == 'E'){
      cnt = min(cnt, 2 * v[c -'A']);
    }else if(i == 9 and c == 'N'){
      cnt = min(cnt, 2 * v[c -'A']);
    }else{
      cnt = min(cnt, v[c -'A']);
    }
  }

  for(auto c : number[i]){
    v[c -'A'] -= cnt;
  }

  return true;
}

bool valid(vector<int> v, int i){
  bool ret = take(v, i);
  if(ret == false) return false;

  for(auto i : order){
    takeAll(v, i);
  }

  for(auto c : v){
    if(c) return false;
  }

  return true;
}

string f(vector<int> &v){
  string ans;

  for(int i = 0; i < 10; ++i){
    while(valid(v, i)){
      take(v, i);
      ans.push_back(i + '0');
    }
  }
  return ans;
}

int main(){ IO;
  int t;
  cin >> t;

  for(int ncase = 1; ncase <= t; ++ncase){
    cout << "Case #" << ncase << ": ";

    string s;
    cin >> s;

    vector<int> v(30);
    for(auto &c : s){
      v[c - 'A']++;
    }

    string ans = f(v);
    cout << ans << endl;
  }

  return 0;
}
