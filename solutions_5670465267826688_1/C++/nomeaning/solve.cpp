#include <iostream>
#include <boost/math/quaternion.hpp>
#include <map>
#include <tuple>
using namespace std;
using namespace boost::math;

quaternion<int> I(0,1,0,0);
quaternion<int> J(0,0,1,0);
quaternion<int> K(0,0,0,1);
string S;
typedef tuple<int,int,int,int,int,int> Memo;
map<Memo, bool> memo;

bool rec(int pos, int cur, quaternion<int> now) {
  Memo m_now = Memo(pos, cur, now.R_component_1(), now.R_component_2(), now.R_component_3(), now.R_component_4());
  if(pos == S.size()) {
    if(cur == 2 && now == K) return true;
    return false;
  }
  if(memo.count(m_now)) return memo[m_now];
  bool result = false;
  if((now == I && cur == 0) || (now == J && cur == 1)) {
    if(rec(pos, cur + 1, quaternion<int>(1, 0, 0, 0))) result = true;
  }
  if(S[pos] == 'i') {
    result |= rec(pos + 1, cur, now * I);
  }
  if(S[pos] == 'j') {
    result |= rec(pos + 1, cur, now * J);
  }
  if(S[pos] == 'k') {
    result |= rec(pos + 1, cur, now * K);
  }
  return memo[m_now] = result;
}
int main() {
  int T;
  cin>>T;
  for(int tc = 1; tc <= T; tc++) {
    int X, L;
    cin >> L >> X;
    string s;
    cin >> s;
    X = min(X, 40 + X % 4);
    S = "";
    for(int i = 0; i < X; i++) {
      S += s;
    }
    memo.clear();
    bool ret = rec(0, 0, quaternion<int>(1, 0, 0, 0));
    cout << "Case #" << tc << ": " << (ret ? "YES" : "NO") << endl;
  }
}
