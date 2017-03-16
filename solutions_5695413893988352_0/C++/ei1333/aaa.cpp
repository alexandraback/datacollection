#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef pair< int64, pair< int64, int64 > > State;

string C, J;

State rec(int64 a, int64 b, int idx)
{
  if(idx == C.size()) return(make_pair(llabs(a - b), make_pair(a, b)));
  State s = {1e9, {1e9, 1e9}};
  for(int i = 0; i <= 9; i++) {
    if(C[idx]  == char(i + '0') || C[idx] == '?') {
      for(int j = 0; j <= 9; j++) {
        if(J[idx] == char(j + '0') || J[idx] == '?') {
          s = min(s, rec(a * 10 + i, b * 10 + j, idx + 1));
        }
      }
    }
  }
  return(s);
}
void Solve()
{
  cin >> C >> J;
  pair< int64, int64 > ret = rec(0, 0, 0).second;
  printf("%0*lld %0*lld\n", C.size(), ret.first, C.size(), ret.second);
}
int main()
{
  int T;
  cin >> T;
  for(int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    Solve();
  }
}
