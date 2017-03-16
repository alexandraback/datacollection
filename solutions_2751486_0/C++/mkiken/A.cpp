#include <iostream>
//#include <cstdio>
//#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
//#include <map>
//#include <set>
//#include <queue>
//#include <limits>
//#include <sstream>
//#include <functional>
using namespace std;

#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(i, s, e) for(int i = s;i < e;i++)
#define rrep(i, e, s) for(int i = e;s <= i;i--)
#define mfill(a, v) fill(a, a + len(a), v)
#define mfill2(a, v, t) fill((t *)a, (t *)(a + len(a)), v)
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v, t) sort(v.begin(), v.end(), greater<t>())
#define asort(a) sort(a, a + len(a))
#define rasort(a, t) sort(a, a + len(a), greater<t>())
#define dmax(a, b) (a < b? b : a)
#define dmin(a, b) (a > b? b : a)
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
//const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
//const int weight[] = {0,1,10,100,1000,10000,100000,1000000,10000000};
typedef struct _Node {
  _Node(int arg1 = 0, int arg2 = 0 , int arg3 = 0) {
	i = arg1;
	j = arg2;
	k = arg3;
  }
  int i,j,k;
  bool operator <(const struct _Node &e) const{
    return i == e.i? j < e.j : i < e.i;
  }
  bool operator >(const struct _Node &e) const{
    return i == e.i? j > e.j : i > e.i;
  }
}node;


void doIt(){
  int t, n, seq = 0, mem;
  int dp[1000001];
  ll sum;
  string s;
  cin >> t;
  rep(ii, 0, t){
	cin >> s >> n;
	mfill(dp, s.length());
	mem = s.length();
	seq = 0;
	//cout << "n = " << n << endl;
	rrep(i, s.length() - 1, 0){
	  if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u'){
		seq++;
		if(n <= seq){
		  //cout << "i = " << i << ", seq 0 " << seq << endl;
		  dp[i] = i;
		  mem = i;
		}
		else if(mem + n <= s.length()) dp[i] = mem;

	  }
	  else{
		seq = 0;
		if(mem + n <= s.length()) dp[i] = mem;
	  }
	}
	sum = 0;
	rep(i, 0, s.length()){
	  //cout << "dp[" << i << "] = " << dp[i] << endl;
	  if(dp[i] + n <= s.length()){
		//cout << "dp[" << i << "] = " << dp[i] << endl;
		sum += s.length() - (dp[i] + n) + 1;
	  }
	}
	cout << "Case #" << ii+1 << ": " << sum << endl;
  }
}

int main() {
  doIt();
  return 0;
}
