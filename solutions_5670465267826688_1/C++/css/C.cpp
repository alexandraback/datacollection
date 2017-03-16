#include <map>
#include <set>
#include <cstdio>
#include <utility>
#include <cstring>
#include <fstream>
using namespace std;
const int maxN = 1e4+7;
const pair<bool, char> INIT = make_pair(true, '1');
int T, len;
long long k;
set<int> list;
char str[maxN];
bool get_i, get_j;
pair<bool, char> pre[maxN];
set<pair<bool, char> > used, hap;
pair<bool, char> muti(pair<bool, char> t, char q) {
  bool mus = t.first;
  if (t.second == '1') return make_pair(mus, q);
  if (t.second == 'i') {
    if (q == 'i') return make_pair(!mus, '1');
    if (q == 'j') return make_pair(mus, 'k');
    if (q == 'k') return make_pair(!mus, 'j');
  }
  if (t.second == 'j') {
    if (q == 'i') return make_pair(!mus, 'k');
    if (q == 'j') return make_pair(!mus, '1');
    if (q == 'k') return make_pair(mus, 'i');
  }
  if (t.second == 'k') {
    if (q == 'i') return make_pair(mus, 'j');
    if (q == 'j') return make_pair(!mus, 'i');
    if (q == 'k') return make_pair(!mus, '1');
  }
  return t;
}
pair<bool,char> muti(pair<bool, char> t0, pair<bool, char> t1) {
  pair<bool, char> t = muti(t0, t1.second);
  if (!t1.first) t.first = !t.first;
  return t;
}
bool Needed(pair<bool, char> t) {
  if (get_i) {
    if (t == make_pair(true, 'j')) {
      get_j = true;
      hap.clear();
      return true;
    }
  } else {
    if (t == make_pair(true, 'i')) {
      get_i = true;
      hap.clear();
      return true;
    }
  }
  return false;
}
pair<bool, char> pow(pair<bool, char> t0, long long k) {
  if (k == 0) return INIT;
  pair<bool, char> ans, t = pow(t0, k>>1);
  if (k&1) ans = t0; else ans = INIT;
  return muti(muti(ans, t), t);
}
bool check() {
  pair<bool, char> t = INIT;
  pre[0] = muti(INIT, str[0]);
  hap.clear(), used.clear(), list.clear();
  for (int p = 0; p < len; p++) {
    if (p > 0) pre[p] = muti(pre[p-1], str[p]);
    set<pair<bool, char> >::iterator it = used.find(pre[p]);
    if (it == used.end()) {
      list.insert(p);
      used.insert(pre[p]);
    }
  }
  t = INIT;
  int i = 0;
  get_i = get_j = false;
  for (; k && !(get_i && get_j);)
    if (i > 0) {
      t = muti(t, str[i]);
      i = (i+1)%len;
      if (i == 0) k--;
      if (Needed(t)) t = INIT;
    } else {
      bool flag = true;
      set<pair<bool, char> >::iterator it = hap.find(t);
      if (it == hap.end()) hap.insert(t); else return false;
      for (set<int>::iterator it = list.begin(); it != list.end(); it++)
        if (Needed(muti(t, pre[*it]))) {
          t = INIT;
          i = (*it+1)%len;
          if (i == 0) k--;
          flag = false;
          break;
        }
      if (flag) {
        t = muti(t, pre[len-1]);
        i = 0, k--;
      }
    }
  if (i != 0) k--;
  for (; i != 0; i = (i+1)%len) t = muti(t, str[i]);
  return k>=0 && get_i && get_j && (muti(t, pow(pre[len-1], k))==make_pair(true, 'k'));
}
int main()
{
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  scanf("%d", &T);
  for (int count = 1; count <= T; count++) {
    scanf("%d%lld", &len, &k);
    scanf("%s", str);
    printf("Case #%d: %s\n", count, check()?"YES":"NO");
  }
}
