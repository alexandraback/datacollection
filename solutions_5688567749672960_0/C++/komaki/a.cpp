#ifndef KOMAKI_LOCAL
#define NDEBUG
#endif

#include <bits/stdc++.h>
#include <sys/time.h>
#include <unistd.h>
using namespace std;
#define i64         int64_t
#define rep(i, n)   for(i64 i = 0; i < ((i64)(n)); ++i)
#define sz(v)       ((i64)((v).size()))
#define bit(n)      (((i64)1)<<((i64)(n)))
#define all(v)      (v).begin(), (v).end()

std::string dbgDelim(int &i){ return (i++ == 0 ? "" : ", "); }
#define dbgEmbrace(exp) { int i = 0; os << "{"; { exp; } os << "}"; return os; }
template <class T> std::ostream& operator<<(std::ostream &os, std::vector<T> v);
template <class T> std::ostream& operator<<(std::ostream &os, std::set<T> v);
template <class T> std::ostream& operator<<(std::ostream &os, std::queue<T> q);
template <class T> std::ostream& operator<<(std::ostream &os, std::priority_queue<T> q);
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::pair<T, K> p);
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::map<T, K> mp);
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::unordered_map<T, K> mp);
template <int INDEX, class TUPLE> void dbgDeploy(std::ostream &os, TUPLE tuple){}
template <int INDEX, class TUPLE, class H, class ...Ts> void dbgDeploy(std::ostream &os, TUPLE t)
{ os << (INDEX == 0 ? "" : ", ") << get<INDEX>(t); dbgDeploy<INDEX + 1, TUPLE, Ts...>(os, t); }
template <class T, class K> void dbgDeploy(std::ostream &os, std::pair<T, K> p, std::string delim)
{ os << "(" << p.first << delim << p.second << ")"; }
template <class ...Ts> std::ostream& operator<<(std::ostream &os, std::tuple<Ts...> t)
{ os << "("; dbgDeploy<0, std::tuple<Ts...>, Ts...>(os, t); os << ")"; return os; }
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::pair<T, K> p)
{ dbgDeploy(os, p, ", "); return os; }
template <class T> std::ostream& operator<<(std::ostream &os, std::vector<T> v)
{ dbgEmbrace( for(T t: v){ os << dbgDelim(i) << t; }); }
template <class T> std::ostream& operator<<(std::ostream &os, std::set<T> s)
{ dbgEmbrace( for(T t: s){ os << dbgDelim(i) << t; }); }
template <class T> std::ostream& operator<<(std::ostream &os, std::queue<T> q)
{ dbgEmbrace( for(; q.size(); q.pop()){ os << dbgDelim(i) << q.front(); }); }
template <class T> std::ostream& operator<<(std::ostream &os, std::priority_queue<T> q)
{ dbgEmbrace( for(; q.size(); q.pop()){ os << dbgDelim(i) << q.top();   }); }
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::map<T, K> mp)
{ dbgEmbrace( for(auto p: mp){ os << dbgDelim(i); dbgDeploy(os, p, "->"); }); }
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::unordered_map<T, K> mp)
{ dbgEmbrace( for(auto p: mp){ os << dbgDelim(i); dbgDeploy(os, p, "->"); }); }
#define DBG_OUT std::cerr
#define DBG_OVERLOAD(_1, _2, _3, _4, _5, _6, macro_name, ...) macro_name
#define DBG_LINE() { char s[99]; sprintf(s, "line:%3d | ", __LINE__); DBG_OUT << s; }
#define DBG_OUTPUT(v) { DBG_OUT << (#v) << "=" << (v); }
#define DBG1(v, ...) { DBG_OUTPUT(v); }
#define DBG2(v, ...) { DBG_OUTPUT(v); DBG_OUT << ", "; DBG1(__VA_ARGS__); }
#define DBG3(v, ...) { DBG_OUTPUT(v); DBG_OUT << ", "; DBG2(__VA_ARGS__); }
#define DBG4(v, ...) { DBG_OUTPUT(v); DBG_OUT << ", "; DBG3(__VA_ARGS__); }
#define DBG5(v, ...) { DBG_OUTPUT(v); DBG_OUT << ", "; DBG4(__VA_ARGS__); }
#define DBG6(v, ...) { DBG_OUTPUT(v); DBG_OUT << ", "; DBG5(__VA_ARGS__); }

#define DEBUG0() { DBG_LINE(); DBG_OUT << std::endl; }
#define DEBUG(...)                                                      \
  {                                                                     \
    DBG_LINE();                                                         \
    DBG_OVERLOAD(__VA_ARGS__, DBG6, DBG5, DBG4, DBG3, DBG2, DBG1)(__VA_ARGS__); \
    DBG_OUT << std::endl;                                               \
  }


i64 pow(i64 n)
{
  i64 t = 1;
  rep(i, n) t *= 10;
  return t;
}

i64 calc(string base)
{
  vector<string> next({"1"});
  set<string> used({"1"});
  rep(dist, bit(25)){
    vector<string> v;
    for(string s: next){
      if(s == base) return dist + 1;
      i64 t;
      stringstream ss0, ss1;
      ss0 << s;
      ss0 >> t;
      ss1 << t + 1;
      ss1 >> s;
      if(used.count(s)) continue;
      used.insert(s);
      v.push_back(s);
    }
    for(string s: next){
      reverse(all(s));
      i64 t;
      stringstream ss0, ss1;
      ss0 << s;
      ss0 >> t;
      ss1 << t;
      ss1 >> s;
      if(used.count(s)) continue;
      used.insert(s);
      v.push_back(s);
    }
    next = v;
  }
}

i64 solve(string s)
{
  if(sz(s) == 1) return s[0] - '0';
  
  i64 total = 10;
  for(i64 len = 2; len < sz(s); ++len){
    total += 2 * (pow(len / 2) - 1);
    total += 1;
    if(len % 2) total += pow(len / 2) * 9;
  }

  i64 left = 0, right = 0;
  rep(i, sz(s) / 2) left += pow(i) * (s[i] - '0');
  rep(i, sz(s) / 2) right += pow(i) * (s[sz(s) - 1 - i] - '0');
  left -= 1;
  if(sz(s) % 2) right += pow(sz(s) / 2) * (s[sz(s) / 2] - '0');
  if(right == 0 && left != 0){
    i64 digit = 0;
    while(pow(digit + 1) <= left) ++digit;
    left -= pow(digit);
    left += pow(sz(s) / 2) - pow(digit + 1);
    right += pow(sz(s) / 2) - 1 + 1;
    //if(sz(s) / 2 != 1) total += 2;
    if(sz(s) % 2) right += pow(sz(s) / 2) * 9;
  }
  //DEBUG(left, right, total);
  return left + right + total + (left == 0 ? 0 : 1);
}

int main()
{
  rep(i, 0){
    i64 t = rand() % 1000000;
    cin >> t;
    stringstream ss;
    ss << t;
    string s;
    ss >> s;
    DEBUG(t, solve(s), calc(s));
    sleep(1);
    assert(solve(s) == calc(s));
  }
  i64 T;
  cin >> T;
  rep(test_case, T){
    string s;
    cin >> s;
    i64 res = solve(s);
    cout << "Case #" << test_case + 1 << ": " << res << endl;
  }
}












