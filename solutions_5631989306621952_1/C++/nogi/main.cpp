#include <iostream>
#include <algorithm>
using namespace std;
using i64 = long long;

template<typename T>
class Range{private:struct I{T x;T operator*(){return x;}bool operator!=(I& lhs){return x<lhs.x;}void operator++(){++x;}};I i,n;
public:Range(T n):i({0}),n({n}){}Range(T i,T n):i({i}),n({n}){}I& begin(){return i;}I& end(){return n;}};
using range = Range<i64>;

string f(string s) {
  int n = s.size();
  string res = string({s[0]});
  for(auto&& i : range(1, n)) {
    if(res[0] > s[i]) {
      res += s[i];
    } else if(res[0] <= s[i]) {
      res.insert(res.begin(), s[i]);
    }
  }
  return res;
}

int main(void) {
  int t; scanf("%d", &t);
  for(auto&& i : range(t)) {
    string s; cin >> s;
    string res = f(s);
    cout << "Case #" << (i+1) << ": " << res << endl;
  }
  return 0;
}
