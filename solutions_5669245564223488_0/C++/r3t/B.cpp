#include <algorithm>
#include <iterator>
#include <iostream>
#include <utility>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;

ll ans = 0LL;

bool check(const string& s)
{
  string tmp;
  int n = s.size();

  for(int i = 0; i < n - 1; i++)
    if( s[i] != s[i+1] )
      tmp += s[i];
  
  tmp += s[s.size()-1];
  
  int m = tmp.size();
  for(int i = 0; i < m; i++)
    if( count(tmp.begin(), tmp.end(), tmp[i]) != 1 )
      return false;
  
  //cout << tmp << " " << s << endl;
  return true;
}

//void go(const string& cur, const vector<string>& can_take, vector<bool>& used)
void go(const string& cur, const vector<string>& can_take, ll mask)
{
  if( mask == ((1LL << can_take.size()) - 1) )
  {
    ans = (ans + check(cur)) % MOD;
    return;
  }
  
  for(int i = 0; i < (int) can_take.size(); i++)
    if( !(mask & (1LL << i)) )
      go(cur + can_take[i], can_take, (mask | (1LL << i)) );

}

int solve()
{
  ans = 0;
  int n;
  cin >> n;
  
  vector<string> v(n);
  
  for(int i = 0; i < n; i++)
    cin >> v[i];
  
  //vector<bool> used(n);
  ll mask = 0;
  go("", v, mask);
  return ans;
}

int main()
{
  int tests;
  
  cin >> tests;
  
  for(int test = 1; test <= tests; test++)
  {
    ll out = solve();
    std::cout << "Case #" << test << ": " << out << endl;
  }
	return 0;
}
