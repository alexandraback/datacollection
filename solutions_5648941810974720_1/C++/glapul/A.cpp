//Michał Glapa
#include<bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define FORD(i,j,k) for(int i=j;i>=k;i--)
#define ll long long
//Make sure no overflow problems
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define ld long double
#define mini(x,y) x=min(x,y)
#define maxi(x,y) x=max(x,y)
#define CLR(a,x) memset(a,x,sizeof(a))
#define SIZE(x) ((int)x.size())
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;
const ld EPS = 10e-9;
typedef vector<int> vi;
typedef pair<int,int> pii;

///////////////////////////////////////////////////////////////
//
//
void wtf(string s, int n, vector<int>& cnt) {
  for(auto i : s)
    cnt[i - 'A'] -= n;
}
void solve() {
  vector<int> cnt(26);
  string s;
  cin >> s;
  for (auto i : s)
    cnt[i-'A']++;
  vector<int> cnt2(10);
  cnt2[0] = cnt['Z' - 'A'];
  wtf("ZERO", cnt2[0], cnt);
  cnt2[6] = cnt['X' - 'A'];
  wtf("SIX", cnt2[6], cnt);
  cnt2[8] = cnt['G' - 'A'];
  wtf("EIGHT", cnt2[8], cnt);
  cnt2[4] = cnt['U' - 'A'];
  wtf("FOUR", cnt2[4], cnt);
  cnt2[2] = cnt['W' - 'A'];
  wtf("TWO", cnt2[2], cnt);
  cnt2[1] = cnt['O' - 'A'];
  wtf("ONE", cnt2[1], cnt);
  cnt2[7] = cnt['S' - 'A'];
  wtf("SEVEN", cnt2[7], cnt);
  cnt2[5] = cnt['V' - 'A'];
  wtf("FIVE", cnt2[5], cnt);
  cnt2[3] = cnt['T' - 'A'];
  wtf("THREE", cnt2[3], cnt);
  cnt2[9] = cnt['E' - 'A'];

  REP(i, 10)
    REP(j, cnt2[i])
      cout << i;
  cout << endl;


}
#undef int
int main()
#define int long long
{
  int z;
  cin >> z;
  FOR(i,1, z) {
    cout <<"Case #" <<i << ": ";
    solve();
  }

}
