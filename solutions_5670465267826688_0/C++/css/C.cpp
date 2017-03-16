#include <cstdio>
#include <utility>
#include <cstring>
#include <fstream>
using namespace std;
const int maxN = 1e4+7;
char str[maxN];
int k;
int T, len;
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
}
bool check() {
  pair<bool, char> t = make_pair(true, '1');
  bool get_i = false, get_j = false;
  for (int j = 0; j < k; j++)
    for (int i = 0; i < len; i++) {
      t = muti(t, str[i]);
      if (get_i) {
        if (!get_j && t==make_pair(true, 'j')) t = make_pair(true, '1'), get_j = true;
      } else {
        if (t == make_pair(true, 'i')) t = make_pair(true, '1'), get_i = true;
      }
    }
  return get_i && get_j && t==make_pair(true, 'k');
}
int main()
{
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  scanf("%d", &T);
  for (int count = 1; count <= T; count++) {
    scanf("%d%d", &len, &k);
    scanf("%s", str);
    printf("Case #%d: %s\n", count, check()?"YES":"NO");
  }
}
