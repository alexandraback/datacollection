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





inline i64 recur(i64 pos, i64 root, vector<vector<i64>> &children)
{
  i64 res = 1;
  i64 longest = 0;
  for(i64 child: children[pos])if(child != root){
    longest = max(longest, recur(child, root, children));
  }
  return res + longest;
}


i64 brute(vector<i64> parents)
{
  i64 n = sz(parents);
  vector<i64> v;
  rep(i, n) v.push_back(i);

  i64 ans = 0;
  do{
    for(i64 l = 2; l <= sz(v); ++l){
      bool ok = true;
      rep(i, l){
        i64 next = (i + 1) % l;
        i64 bef = (i - 1 + l) % l;
        if(parents[v[i]] != v[next] && parents[v[i]] != v[bef]) ok = false;
      }
      if(ok) ans = max(ans, l);
    }
  }while(next_permutation(all(v)));
  return ans;
}


int main()
{
  i64 T;
  cin >> T;
  rep(test_case, T){
    i64 n;
    bool debug = false;
    if(debug){
      n = 8;
    }else{
      cin >> n;
    }

    vector<i64> parents(n);
    rep(i, n){
      if(debug){
        do{
          parents[i] = rand() % n;
        }while(parents[i] == i);
      }else{
        cin >> parents[i];
        parents[i] -= 1;
      }
    }

    vector<vector<i64>> children(n);
    rep(i, n) children[parents[i]].push_back(i);

    i64 ans = 0;

    // One Loop
    rep(i, n){
      unordered_set<i64> used;
      i64 cur = i;
      while(used.count(cur) == 0){
        used.insert(cur);
        cur = parents[cur];
      }
      //if(cur == i) DEBUG(i, sz(used));
      if(cur == i) ans = max(ans, sz(used));
    }

    // Mutual loop + tails
    i64 total = 0;
    rep(i, n){
      if(parents[parents[i]] != i) continue;
      i64 i0 = i;
      i64 i1 = parents[i0];
      i64 tail0 = 0;
      i64 tail1 = 0;
      for(i64 child: children[i0]){
        if(child == parents[i0]) continue;
        tail0 = max(tail0, recur(child, i0, children));
      }
      for(i64 child: children[i1]){
        if(child == parents[i1]) continue;
        tail1 = max(tail1, recur(child, i1, children));
      }
      //DEBUG(i0, i1, 2 + tail0 + tail1);
      total += 2 + tail0 + tail1;
    }
    ans = max(ans, total / 2);

    printf("Case #%d: %d\n", (int)test_case + 1, (int)ans);
    //cout << brute(parents) << endl;
    //if(ans != brute(parents)) DEBUG(parents, ans, brute(parents));
  }
}





















