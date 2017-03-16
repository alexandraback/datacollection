#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

long long rev(long long n) {
  long long r = 0;
  while (n) {
    r = r * 10 + (n % 10);
    n = n / 10;
  }
  return r;
}

vector<pair<int, long long> > a;

int main() {
  int n, m;
  long long n2;
  for (int i = 1; i <= 9999; ++i) {
    // i + rev(i) : odd length
    n = i, m = i / 10;
    while (m) { n = n * 10 + (m % 10); m = m / 10; }
    //printf("%d\n", n);

    n2 = (long long)n * n;
    if (rev(n2) == n2 && n2 <= 100000000000000LL) {
      a.push_back(make_pair(n, n2));
      //printf("%d %Ld\n", n, n2);
    }
    
    // i + rev(i) : even length
    n = i, m = i;
    while (m) { n = n * 10 + (m % 10); m = m / 10; }

    n2 = (long long)n * n;
    if (rev(n2) == n2 && n2 <= 100000000000000LL) {
      a.push_back(make_pair(n, n2));
    //printf("%d %Ld\n", n, n2);
    }    
  }
  sort(a.begin(), a.end());

  int T;
  scanf("%d", &T);
  long long A, B;
  for (int cn = 1; cn <= T; ++cn) {
    scanf("%Ld %Ld", &A, &B);
    int ret = 0;
    for (int i = 0; i < a.size(); ++i) {
      if (A <= a[i].second && a[i].second <= B) ret++;
    }
    printf("Case #%d: %d\n", cn, ret);
  }
}
