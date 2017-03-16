#include <bits/stdc++.h>

using namespace std;

long long reverse(long long n){
  stringstream ss;
  ss << n;
  string s = ss.str();
  reverse(s.begin(),s.end());
  int i = 0;
  while(s[i] == '0') i++;
  long long ret = 0;
  while(i < (int)s.size()){
    ret *= 10;
    ret += s[i]-'0';
    i++;
  }
  return ret;
}

long long search(long long num){
  queue<long long> q;
  q.push(1);
  map<long long, long long> dist;
  dist[1] = 1;
  while(!q.empty()){
    long long curr = q.front();
    q.pop();
    if( curr == num )
      return dist[curr];
    if( dist.count(curr+1) == 0 ){
      q.push(curr+1);
      dist[curr+1] = dist[curr] + 1;
    }
    int rev = reverse(curr);
    if( dist.count(rev) == 0 ){
      q.push(rev);
      dist[rev] = dist[curr] + 1;
    }
  }
  return -1;
}

int main(){
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
  int t;
  cin >> t;
  int tc = 1;
  while(t--){
    long long a;
    cin >> a;
    cout << "Case #" << tc++ << ": " << search(a) << endl;
  }
}
