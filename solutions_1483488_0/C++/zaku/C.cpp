#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXM = 10;

int A, B;

int get_len(int x, int &jie)
{
  jie = 1;
  int len = 0;
  for (; x; x /= 10) ++len, jie *= 10;
  jie /= 10;
  return len;
}

void solve()
{
  int res = 0;
  int num[MAXM];
  for (int i = A; i <= B; ++i) {
    int pw;
    int len = get_len(i, pw);
    
    num[0] = i;
    for (int j = 1; j < len; ++j) {
      num[j] = num[j-1]%10 * pw + num[j-1]/10;
    }

    sort(num+1, num + len);
    for (int j = 1; j < len; ++j) {
      if (num[j] != num[j-1] && num[j] != num[0] &&
	  A <= num[j] && num[j] <= B) 
	++res;
    }
  }

  printf("%d\n", res/2);
}

int main()
{
  int t;
  scanf("%d", &t);
  for (int l = 1; l <= t; ++l) {
    scanf("%d%d", &A, &B);
    printf("Case #%d: ", l);
    solve();
  }
  return 0;
}
