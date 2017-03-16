#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

const int N = 4e5 + 5;
string s;
int cnt[300];
int main(){
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  for(int cs = 1; cs <= t; cs++){
    cin >> s;
    int n = s.length();
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; i++){
      cnt[s[i]]++;
    }
    s = "";
    int a[10];

    a[0] = cnt['Z'];
    a[2] = cnt['W'];
    a[4] = cnt['U'];
    a[6] = cnt['X'];
    a[7] = cnt['S'] - a[6];
    a[8] = cnt['G'];
    a[5] = cnt['F'] - a[4];
    a[1] = cnt['O'] - a[0] - a[4] - a[2];
    a[9] = cnt['I'] - a[6] - a[8] - a[5];
    a[3] = cnt['H'] - a[8];
    for(int i = 0; i < 10; i++){
      for(int j = 0; j < a[i]; j++){
        s += char(i + '0');
      }
    }
    cout << "Case #" << cs <<": "<< s << endl;
  }

  return 0;
}
