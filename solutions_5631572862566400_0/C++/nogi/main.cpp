#include <iostream>
#include <algorithm>
using namespace std;
using i64 = long long;

template<typename T>
class Range{private:struct I{T x;T operator*(){return x;}bool operator!=(I& lhs){return x<lhs.x;}void operator++(){++x;}};I i,n;
public:Range(T n):i({0}),n({n}){}Range(T i,T n):i({i}),n({n}){}I& begin(){return i;}I& end(){return n;}};
using range = Range<i64>;

#ifdef DEBUG
#define debug1(x1) cerr << #x1 "=" << (x1) << endl;
#define debug2(x1, x2) cerr << #x1 "=" << (x1) << ", " << #x2 "=" << (x2) << endl;
#define debug3(x1, x2, x3) cerr << #x1 "=" << (x1) << ", " << #x2 "=" << (x2) << ", " << #x3 "=" << (x3) << endl;
#define debug4(x1, x2, x3, x4) cerr << #x1 "=" << (x1) << ", " << #x2 "=" << (x2) << ", " << #x3 "=" << (x3) << ", " << #x4 "=" << (x4) << endl;
#define debug5(x1, x2, x3, x4, x5) cerr << #x1 "=" << (x1) << ", " << #x2 "=" << (x2) << ", " << #x3 "=" << (x3) << ", " << #x4 "=" << (x4) << ", " << #x5 "=" << (x5) << endl;
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define debug(...) GET_MACRO(__VA_ARGS__, debug5, debug4, debug3, debug2, debug1)(__VA_ARGS__)
template<class T>
void debugv(vector<T> v, const char* sep) {
  const int n = v.size();
  fprintf(stderr, "'");
  for(int i=0; i<n; i++) {
    if(i!=0) { fprintf(stderr, "%s", sep); }
    cerr << v[i];
  }
  fprintf(stderr, "'\n");
}
template<class T> void debugv(vector<T> v) { debugv(v, " "); }
template<class T> void debugv(vector<vector<T>> v) { int n = v.size(); for(int i=0; i<n; i++) { debugv(v[i]); } }
template<class T> void debugv(vector<vector<vector<T>>> v) { int n = v.size(); for(int i=0; i<n; i++) { debugv(v[i]); } }
template<class T> void debugv(vector<vector<vector<vector<T>>>> v) { int n = v.size(); for(int i=0; i<n; i++) { debugv(v[i]); } }
template<class T> void debugv(vector<vector<vector<vector<vector<T>>>>> v) { int n = v.size(); for(int i=0; i<n; i++) { debugv(v[i]); } }
#else
#define debug(...) ((void)0)
#define debugv(...) ((void)0)
#endif

int main(void) {
  int t; scanf("%d", &t);
  for(auto&& loop : range(t)) {
    int n; scanf("%d", &n);
    vector<int> v(n, 0); // v[n]
    for(auto&& i : range(n)) { scanf("%d", &v[i]); --v[i]; }
    vector<int> w(n, 0);
    for(auto&& i : range(n)) { w[i] = i; }

    int haa = 0;
    for(auto&& k : range(1, n+1)) {
      int comb = (1<<k) - 1;
      while(comb < 1<<n) {
        debug(comb);
        vector<int> w;
        for(auto&& i : range(n)) {
          if(comb>>i & 1) { w.push_back(i); }
        }
        debugv(w);
        do {
          int bff = 0;
          for(auto&& i : range(k)) {
            // aさんと左の人、右の人を比較
            int a = w[i],
                left = w[(i-1+k)%k],
                right= w[(i+1)%k];
            if(v[a] == left || v[a] == right) {
              bff++;
            }
          }
          if(bff == k) {
            haa = max(haa, bff);
          }
        } while(next_permutation(w.begin(), w.end()));
        int x = comb & -comb, y = comb + x;
        comb = ((comb & ~y) / x>>1) | y;
      }
    }
    printf("Case #%lld: %d\n", loop+1, haa);
  }
  return 0;
}
