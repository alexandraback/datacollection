#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>

#define MAXL 52

using namespace std;

class FairNum {
 public:
  FairNum(char* str) : numstr(str) {
  }
  string numstr;

  void print() {
    printf("%s\n", numstr.c_str());
  }

  bool operator<(const FairNum& other) {
    if (numstr.size() < other.numstr.size())
      return true;
    else if (numstr.size() > other.numstr.size())
      return false;
    return numstr < other.numstr;
  }
};

vector<FairNum> fair;

int pat[55];
int sqr[110];

bool try_sqr(int len) {
  memset(sqr, 0x00, sizeof(sqr));
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      sqr[i + j] += pat[i] * pat[j];
      if (sqr[i + j] > 9)
        return false;
    }
  }
  return true;
}

void pat_set(int pos, int val, int len) {
  pat[pos] = val;
  pat[len - pos - 1] = val;
}

char buf[110];

void pattern(int pos, int len) {
  if (pos > (len - 1) / 2) {
    try_sqr(len);
    int i = 0;
    for (i = 0; i < (2 * len - 1); i++)
      buf[i] = '0' + sqr[i];
    buf[i] = 0;
    fair.push_back(FairNum(buf));
  }
  else {
    int low = pos == 0 ? 1 : 0;
    int lim = 1;
    if (pos == 0)
      lim = 2;
    if (len % 2 == 1 && pos == (len + 1) / 2 - 1)
      lim = 2;
    for (int i = low; i <= lim; i++) {
      pat_set(pos, i, len);
      if (try_sqr(len))
        pattern(pos + 1, len);
    }
    pat_set(pos, 0, len);
  }
}

int T = 0;
char read_buf[120];

int main() {
  memset(pat, 0x0, sizeof(pat));
  fair.push_back(FairNum((char*)"1"));
  fair.push_back(FairNum((char*)"4"));
  fair.push_back(FairNum((char*)"9"));
  for (int i = 2; i <= MAXL; i++) {
    pattern(0, i);
  }

  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%s", read_buf);
    FairNum a(read_buf);
    scanf("%s", read_buf);
    FairNum b(read_buf);
    int low_i = lower_bound(fair.begin(), fair.end(), a) - fair.begin();
    int high_i = lower_bound(fair.begin(), fair.end(), b) - fair.begin();
    if (b.numstr != fair[high_i].numstr)
      high_i--;
    int count = high_i - low_i + 1;
    if (count < 0)
      count = 0;
    printf("Case #%d: %d\n", t + 1, count);
  }
}
