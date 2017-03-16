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
#include <sstream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(i, s, e) for(ll i = s;i < e;i++)
#define rrep(i, e, s) for(int i = e;s <= i;i--)
#define mfill(a, v) fill(a, a + len(a), v)
#define mfill2(a, v) fill((int *)a, (int *)(a + len(a)), v)
#define vsort(v) sort(v.begin(), v.end())
#define msort(a) sort(a, a + len(a))
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int INF = INT_MAX;
const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
const int MAX_B = (int)1e7 + 2;
const ll bfairs[] = {1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002,10000001};

string num2str(ll number)
{
  stringstream ss;
  ss << number;
  return ss.str();
}

bool isPalindrome(ll num){
  string s = num2str(num);
  string t = string ( s.rbegin(), s.rend() );
  return s==t? true : false;
}

void doIt(){
  int t;
  ll a, b;
  /*vector<ll> fairs;
  rep(i, 1, MAX_B){
	if(isPalindrome(i)){
	  if(isPalindrome(i * i)) cout << i << ",";//fairs.push_back(i);
	}
  }
  cout << endl;*/
  cin >> t;

  rep(ii, 0, t){
	ll sum = 0;
	cin >> a >> b;
	rep(i, 0, (int)len(bfairs)){
	  if(a <= bfairs[i]*bfairs[i] && bfairs[i]*bfairs[i] <= b) sum++;
	}
	cout << "Case #" << ii+1 << ": " << sum << endl;

  }
}

int main() {
	doIt();
	return 0;
}
