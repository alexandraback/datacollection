
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi  vector<int>
#define pb  push_back
#define mp  make_pair
#define ALL(x) x.begin(),x.end()
#define M(a,x) memset(a,x,sizeof(a))
#define sci(x) scanf("%d",&x);
#define scl(x) scanf("%lld",&x);
#define scs(x) scanf("%s",x);
#define print(x) printf("%d",x);
#define nl printf("\n")
#define fr first
#define se second
#define printl(x) printf("%lld",x)
#define F(i,a,n) for(int i=a;i<n;i++)
#define INF 100000000000000000LL
#define LL long long

const int N = 1e5+5;
map<char,int> m;
int main() {
  freopen("Read.in","r",stdin);
  freopen("OUT.out","w",stdout);
  int t;
  sci(t);
  int cs = 0;
  while(t--) {
    string s;
    cin >> s;
    m.clear();
    vector<int> ans;
    for(int i=0;i<s.size();i++) {
      m[s[i]]++;
    }
    int cnt0 = m['Z'];
    while(cnt0--) {
      ans.pb(0);
      m['Z']--;
      m['E']--;
      m['R']--;
      m['O']--;
    }
    int cnt2 = m['W'];
    while(cnt2--) {
      ans.pb(2);
      m['T']--;
      m['W']--;
      m['O']--;
    }
    int cnt4 = m['U'];
    while(cnt4--) {
      ans.pb(4);
      m['F']--;
      m['O']--;
      m['U']--;
      m['R']--;
    }
    int cnt1 = m['O'];
    while(cnt1--) {
      ans.pb(1);
      m['O']--;
      m['N']--;
      m['E']--;
    }
    int cnt3 = m['R'];
    while(cnt3--) {
      ans.pb(3);
      m['T']--;
      m['H']--;
      m['R']--;
      m['E']--;
      m['E']--;
    }
    int cnt5 = m['F'];
    while(cnt5--) {
      ans.pb(5);
      m['F']--;
      m['I']--;
      m['V']--;
      m['E']--;
    }
    int cnt6 = m['X'];
    while(cnt6--) {
      ans.pb(6);
      m['S']--;
      m['I']--;
      m['X']--;
    }
    int cnt7 = m['V'];
    while(cnt7--) {
      ans.pb(7);
      m['S']--;
      m['E']--;
      m['V']--;
      m['E']--;
      m['N']--;
    }
    int cnt8 = m['G'];
    while(cnt8--) {
      ans.pb(8);
      m['E']--;
      m['I']--;
      m['G']--;
      m['H']--;
      m['T']--;
    }
    int cnt9 = m['E'];
    while(cnt9--) {
      ans.pb(9);
      m['N']--;
      m['I']--;
      m['N']--;
      m['E']--;
    }
    sort(ans.begin(),ans.end());
    printf("Case #%d: ",++cs);
    F(i,0,ans.size()) {
      cout<<ans[i];
    }
    cout<<endl;
  }
}
