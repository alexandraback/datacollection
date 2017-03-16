#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef pair<LL, LL> PLL;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

vector<string> num = {
  "ZERO",
  "ONE",
  "TWO",
  "THREE",
  "FOUR",
  "FIVE",
  "SIX",
  "SEVEN",
  "EIGHT",
  "NINE",
};
void f(VI& cnt, int x, int n){
  for(int i=0;i<SZ(num[x]);++i)
	cnt[num[x][i]-'A'] -= n;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  FOR(t,1,T+1){
	string s; cin >> s;
	VI cnt(26);
	REP(i,SZ(s)) cnt[s[i]-'A']++;
	VI ans(10);

	ans[0] = cnt['Z'-'A'];
	f(cnt, 0, ans[0]);
	ans[2] = cnt['W'-'A'];
	f(cnt, 2, ans[2]);
	ans[6] = cnt['X'-'A'];
	f(cnt, 6, ans[6]);
	ans[8] = cnt['G'-'A'];
	f(cnt, 8, ans[8]);
	ans[7] = cnt['S'-'A'];
	f(cnt, 7, ans[7]);
	ans[5] = cnt['V'-'A'];
	f(cnt, 5, ans[5]);
	ans[3] = cnt['T'-'A'];
	f(cnt, 3, ans[3]);
	ans[4] = cnt['R'-'A'];
	f(cnt, 4, ans[4]);
	ans[1] = cnt['O'-'A'];
	f(cnt, 1, ans[1]);
	ans[9] = cnt['I'-'A'];
	f(cnt, 9, ans[9]);

	string ans_s;
	REP(i,10) ans_s += string(ans[i], '0'+i);
	cout << "Case #" << t << ": " << ans_s << endl;
  }
  
  return 0;
}
