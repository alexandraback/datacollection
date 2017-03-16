#include <iostream>
using namespace std;

typedef long long LL;

LL rev(LL a) {
  LL r = 0;
  while (a) {
    r = r * 10 + (a%10);
    a/=10;
  }
  return r;
}
int rev(int a) {
  int r = 0;
  while (a) {
    r = r * 10 + (a%10);
    a/=10;
  }
  return r;
}

#define UP 100000000

LL table[] = {
1,
4,
9,
121,
484,
10201,
12321,
14641,
40804,
44944,
1002001,
1234321,
4008004,
100020001,
102030201,
104060401,
121242121,
123454321,
125686521,
400080004,
404090404,
10000200001,
10221412201,
12102420121,
12345654321,
40000800004,
1000002000001,
1002003002001,
1004006004001,
1020304030201,
1022325232201,
1024348434201,
1210024200121,
1212225222121,
1214428244121,
1232346432321,
1234567654321,
4000008000004,
4004009004004,
100000020000001,
100220141022001,
102012040210201,
102234363432201,
121000242000121,
121242363242121,
123212464212321,
123456787654321,
400000080000004,
};

int main() {
  /* used to generate table above */
  if (0) {
    for (int i=1; i<=UP; i++) {
      if (i == rev(i)) {
        LL ii = LL(i)*LL(i);
        if (ii == rev(ii)) {
          cout << ii << "," << endl;
        }
      }
    }
  }
  int T; scanf("%d", &T);
  for (int cs=1; cs<=T; cs++) {
    printf("Case #%d: ", cs);
    LL A, B; scanf("%Ld %Ld", &A, &B);
    int num = sizeof(table)/sizeof(table[0]);
    int cnt = 0;
    for (int i=0;i<num;i++) {
      if (A <= table[i] && table[i] <= B) {
        cnt++;
      }
    }
    printf("%d\n", cnt);
  }
}
