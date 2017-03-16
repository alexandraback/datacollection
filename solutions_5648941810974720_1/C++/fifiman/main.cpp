  //freopen("test.txt", "r", stdin);
#include <bits/stdc++.h>
using namespace std;

#define llj(a,b,c) for (int (a) = (b); (a) < (c); (a)++)
#define lli(a,b) llj(i,a,b)
#define lll(i, x) llj(i, 0, x)
#define fori(x) lll(i, x)
#define forj(x) lll(j, x)
#define fork(x) lll(k, x)

#define all(X) (X).begin(), (X).end()
#define ever ;;
#define fe(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)

#define LINF ((ll) 1e18 + 10)
#define pb push_back
#define mp make_pair
#define ms(arr,val) memset(arr , val , sizeof(arr))
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rlong(x);
#define rfloat(x) scanf("%lf", &(x))
#define endl "\n"
#define trace(X) cout << (X) << endl;
#define trace2(X,Y) cout << (X) << ' ' << (Y) << endl;
#define trace3(X,Y,Z) cout << (X) << ' ' << (Y) << ' ' << (Z) << endl;
#define trace4(X,Y,Z,A) cout << (X) << ' ' << (Y) << ' ' << (Z) << ' ' << (A) << endl;
#define tp(X) trace2(X.first ,X.second)
#define vi vector<int>
#define vvi vector<vector<int> >
#define pvi(a) fe(thing ,a) cout << thing << ' '; cout << "\n";

typedef long long ll;
typedef pair<int,int> pii;
#define sz(A) ((int)A.size())
#define x first
#define y second
#define read_speed ios::sync_with_stdio(false); cin.tie(0)
#define LINE cout << endl << "--------------------------" << endl
/*--------------------------THE END---------------------------------*/




map<char,int> cnt;
vector<char> ans;
map<string,char> memo;

vector<string> numbers = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};


void remove_num(string thing)
{
  fori(sz(thing))
    cnt[thing[i]]--;

  ans.pb(memo[thing]);
}


void solve(string s)
{
  cnt.clear(); ans.clear();

  fori(sz(s))
    cnt[s[i]]++;


  while(cnt['Z'])
    remove_num("ZERO");

  while(cnt['W'])
    remove_num("TWO");

  while(cnt['X'])
    remove_num("SIX");

  while(cnt['G'])
    remove_num("EIGHT");

  while(cnt['U'])
    remove_num("FOUR");

  while(cnt['F'])
    remove_num("FIVE");

  while(cnt['R'])
    remove_num("THREE");

  while(cnt['O'])
    remove_num("ONE");

  while(cnt['V'])
    remove_num("SEVEN");

  while(cnt['I'])
    remove_num("NINE");



  sort(all(ans));
  fe(c, ans)
    cout << c;

  cout << endl;

}



int main()
{
  freopen("test.txt", "r", stdin);
  //freopen("tractor.in", "r", stdin);
  freopen("test.out", "w", stdout);
  read_speed;

  fori(10){
    memo[numbers[i]] = i + '0';
    //trace2(numbers[i], i);
  }

  int t;
  cin >> t;

  string s;

  llj(z,1,t+1)
  {
    cout << "Case #" << z << ": ";
    cin >> s;
    solve(s);
  }


}


