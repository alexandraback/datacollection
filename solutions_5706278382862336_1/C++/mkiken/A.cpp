#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <sstream>
#include <functional>
#include <complex>

using namespace std;

#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(i, s, e) for(int i = (s);i < (e);i++)
#define Rep(i, e) for(int i = 0;i < (e);i++)
#define rrep(i, e, s) for(int i = (e);(s) <= i;i--)
#define Rrep(i, e) for(int i = e;0 <= i;i--)
#define mrep(i, e, t1, t2) for(map<t1, t2>::iterator i = e.begin(); i != e.end(); i++)
#define vrange(v) v.begin(), v.end()
#define vrrange(v) v.rbegin(), v.rend()
#define vsort(v) sort(vrange(v))
#define vrsort(v) sort(vrrange(v))
#define arange(a) a, a + len(a)
#define asort(a) sort(arange(a))
#define arsort(a, t) sort(arange(a), greater<t>())
#define afill(a, v) fill(arange(a), v)
#define afill2(a, v, t) fill((t *)(a), (t *)((a) + len(a)), v)
#define fmax(a, b) ((a) < (b)? (b) : (a))
#define fmin(a, b) ((a) > (b)? (b) : (a))
#define fabs(a) ((a) < 0? -(a) : (a))
#define pb push_back
#define fst(e) (e).first
#define snd(e) (e).second
#define rg(e, s, t) (s <= e && e < t)
#define PQDecl(name, tp) priority_queue< tp, vector<tp>, greater<tp> > name
#define dq(q) q.top();q.pop();
#define sz(v) ((int)(v).size())
#define lg(s) ((int)(s).length())
//#define X real()
//#define Y imag()
//typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
//typedef complex<double> p;
const int INF = (int)2e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
//const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
//const ll weight[] = {1e0,1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9,1e10,1e11,1e12,1e13};
typedef struct _Datum {
  int fst,snd,trd;
  _Datum(int arg1 = 0, int arg2 = 0 , int arg3 = 0) {
	fst = arg1; snd = arg2; trd = arg3;
  }
  bool operator <(const struct _Datum &e) const{
    return fst == e.fst? (snd == e.snd? trd < e.trd : snd < e.snd) : fst < e.fst;
  }
  bool operator >(const struct _Datum &e) const{
    return fst == e.fst? (snd == e.snd? trd > e.trd : snd > e.snd) : fst > e.fst;
  }
}datum;


#define MAX_N 100005


vector<string> split( string s, string c )
{
  vector<string> ret;
  for(int i = 0, n; i <= s.length(); i = n + 1 ){
	n = s.find_first_of( c, i );
	if( n == string::npos ) n = s.length();
	string tmp = s.substr( i, n-i );
	ret.push_back(tmp);
  }
  return ret;
}

//string to int
ll s2i(string Text){
  ll Number;
  // if ( ! (stringstream(Text) >> Number) ) Number = -1;
  stringstream sstr(Text);
  sstr >> Number;
  return Number;
}

ll gcd(ll a, ll b){
    return b==0? a : gcd(b, a % b);
}


ll rec(ll p, ll q){
    // printf("%lld, %lld\n", p, q);
    if(p == q){
        // printf("eq, %lld, %lld\n", p, q);
        return 0;
    }
    ll g = gcd(p, q);
    p /= g;
    q /= g;

    if(q % 2){
        return -1;
    }

    q /= 2;
    if(p > q){
        ll tmp = rec(p % q, q);
        if(tmp != -1){
            return 1;
        }
        else{
            return -1;
        }
    }
    else{
        ll tmp = rec(p, q);
        if(tmp != -1){
            return tmp + 1;
        }
        else{
            return -1;
        }
    }


    return -1;
}

int test_case = 0;
void solve(){
    ll p, q;
    string s;
    cin >> s;
    vector<string> v = split(s, "/");
    p = s2i(v[0]);
    q = s2i(v[1]);
    ll g = gcd(p, q);
    // printf("gcd = %lld\n", g);
    p /= g;
    q /= g;
    ll ret = rec(p, q);
    if(ret == -1) printf("Case #%d: impossible\n", test_case);
    else printf("Case #%d: %lld\n", test_case, ret);
}

void doIt(){
  int t = 1;
  cout << s2i("1000000000000") << endl;
  scanf("%d", &t);
  while(t--){
      test_case++;
    solve();
  }
}

int main() {
  doIt();
  return 0;
}
