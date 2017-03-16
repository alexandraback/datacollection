#include <bits/stdc++.h>

using namespace std;

char a[10][10] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};


int check(int n,vector<int> cnt) {
  for(int i = 0;a[n][i];i++) {
    int c = a[n][i] - 'A';
    if(!cnt[c]) return 0;
    cnt[c]--;
  }
  return 1;
}

void reduce(int n,vector<int> &cnt) {
  for(int i = 0;a[n][i];i++) {
    int c = a[n][i] - 'A';
    cnt[c]--;
  }
}

void solve() {
  string s; cin>>s;
  vector<int> cnt(26,0);
  for(int i = 0;i < s.length();i++) {
    cnt[s[i] - 'A']++;
  }
  vector<int> ans;
  int order[] = {0,2,4,6,8,1,3,5,7,9};
  for(int i = 0;i < 10;i++) {
    int cc = order[i];
    while(check(cc,cnt)) {
      reduce(cc,cnt);
      ans.push_back(cc);
    }
  } 
  sort(ans.begin(),ans.end());
  for(int i = 0;i < ans.size();i++) {
    cout<<ans[i];
  }
  cout<<endl;
}

int main() {
  assert(freopen("input.txt","r",stdin));
  assert(freopen("output.txt","w",stdout));
  int t; cin>>t;
  for(int i = 1;i <= t;i++) {
    cerr<<"Executing Case #"<<i<<endl;
    cout<<"Case #"<<i<<": ";
    solve();
  }

}
