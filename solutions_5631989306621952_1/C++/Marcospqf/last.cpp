#include <cstring>
#include <iostream>
#include <bitset>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <utility>
#include <list>
#include <algorithm>
#include <iomanip>
#define BUFF ios::sync_with_stdio(false);
#define mp make_pair
#define pb push_back
#define imprime(v)                                        \
  for (int X = 0; X < v.size(); X++) cout << v[X] << " "; \
  cout << endl;
#define grid(v)                                                   \
  for (int X = 0; X < v.size(); X++) {                            \
    for (int Y = 0; Y < v[X].size(); Y++) cout << v[X][Y] << " "; \
    cout << endl;                                                 \
  }
#define endl "\n"
using namespace std;
const int INF = 0x3f3f3f3f;
const long double pi = acos(-1);
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
const int MOD = 1e9 + 7;
void solve(int t)
{
  string s;
  cin >> s;
  cout << "Case #" << t << ": ";
  list<char> lista;
  lista.pb(s[0]);
  for (int i = 1; i < s.size(); i++) {
    char f = lista.front();
    if (f > s[i])
      lista.pb(s[i]);
    else
      lista.push_front(s[i]);
  }
  list<char>::iterator it;
  string r;
  for (it = lista.begin(); it != lista.end(); ++it) r += *it;
  cout << r << endl;
}
int main()
{
  BUFF;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) solve(i);
  return 0;
}
