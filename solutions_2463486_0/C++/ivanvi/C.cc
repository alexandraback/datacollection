#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

#define MAX 10000005

typedef long long LL;

void init(void);
void input(void);
void solve(void);
bool isPalindrom(LL num);
int minIndex(LL a);
int maxIndex(LL b);

vector <LL> FS;
LL A, B;
int case_cnt = 1;

int main(void) {
  init();

  int t;
  scanf("%d", &t);
  while (t--) {
    input();
    solve();
  }
  return 0;
}

void init(void) {
  FS.clear();
  for (LL i = 1; i < MAX; i++) {
    if (!isPalindrom(i)) continue;
    LL j = i * i;
    if (!isPalindrom(j)) continue;
    FS.push_back(j);
  }
}

void input(void) {
  scanf("%lld %lld", &A, &B);
}

void solve(void) {
  int left = minIndex(A);
  int right = maxIndex(B);
  printf("Case #%d: %d\n", case_cnt++, (left > right) ? 0 : right - left + 1);
}

bool isPalindrom(LL num) {
  int n = 0;
  int digits[32];
  while (num > 0) {
    digits[n++] = num % 10;
    num /= 10;
  }
  
  for (int i = 0; i < n / 2; i++) {
    if (digits[i] != digits[n - i - 1]) return false;
  }

  return true;
}

int minIndex(LL a) {
  int left = 0;
  int right = FS.size() - 1;
  int index = MAX;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (FS[mid] >= a) {
      index = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return index;
}

int maxIndex(LL b) {
  int left = 0;
  int right = FS.size() - 1;
  int index = -MAX;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (FS[mid] <= b) {
      index = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return index;
}

