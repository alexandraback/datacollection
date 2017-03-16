#include <cstdio>
#include <cstdint>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int m[256], d[10];

int main() {
  int n;
  scanf("%d\n", &n);
  for (int i=0; i<n; ++i) {
    memset(m, 0, sizeof(m));
    memset(d, 0, sizeof(d));
    char s[2001]; scanf("%s\n", s);
    for (int j=0; j<strlen(s); ++j) m[s[j]]++;
    d[0] = m['Z']; m['O'] -= d[0];
    d[2] = m['W']; m['O'] -= d[2]; m['T'] -= d[2];
    d[4] = m['U']; m['O'] -= d[4]; m['F'] -= d[4];
    d[6] = m['X']; m['I'] -= d[6];
    d[8] = m['G']; m['I'] -= d[8]; m['T'] -= d[8];
    d[1] = m['O'];
    d[5] = m['F']; m['V'] -= d[5]; m['I'] -= d[5];
    d[7] = m['V'];
    d[9] = m['I'];
    d[3] = m['T'];
    printf("Case #%d: ", i+1);
    for (int j=0; j<10; ++j) for (int k=0; k<d[j]; ++k) printf("%d", j); printf("\n");
  }
}
