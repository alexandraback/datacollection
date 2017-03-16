#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 1e6 + 5;

int T, n, L;
char s[MAX_N];
int a[MAX_N];
vector<int> v;

int main() {
  scanf("%d", &T);
  for(int __ = 1; __ <= T; __++) {
    scanf("%s", s+1);
    scanf("%d", &n);
    L = strlen(s+1);
    v.clear();
    for(int i = 1; i <= L; i++) {
      a[i] = a[i-1] + (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u');
      if(a[i] - a[i-n] == n) {
	v.push_back(i);
      }
    }
    long long ans = 0;
    sort(v.begin(), v.end());
    for(int i = 1; i <= L; i++) {
      vector<int>::iterator it = lower_bound(v.begin(), v.end(), i+n-1);
      if(it != v.end()) {
	ans += L - *it + 1;
      }
    }
    printf("Case #%d: %lld\n", __, ans);
  }
}
