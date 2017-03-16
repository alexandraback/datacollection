#include <cstdio>
using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) {
  if(b==0)
    return a;
  return gcd(b, a%b);
}

int main() {
  int T, case_no = 0;
  scanf("%d", &T);
  char c;
  int n;
  LL a, b, g, temp;
  while(T--) {
    case_no++;
    scanf("%Ld %c %Ld", &a, &c, &b);
    g = gcd(a, b);
    a /= g;
    b /= g;
    if((b & (b-1)) == 0) {
      if(a*2 > b) {
        n = 1;
      }
      else {
        n = 1;
        temp = b;
        while(2*a < temp) {
          n++;
          temp/=2;
        }
      }
      printf("Case #%d: %d\n", case_no, n);
    }
    else {
      printf("Case #%d: impossible\n", case_no);
    }
  }
  return 0;
}

