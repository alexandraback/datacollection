#include <iostream>
#include <cstdio>
#include <cinttypes>
#include <vector>       // std::vector

using namespace std;

const int kSignMatrix[] = {
  1,  1,  1,  1,
  1, -1,  1, -1,
  1, -1, -1,  1,
  1,  1, -1, -1
};

const char kResMatrix[] = {
  'h', 'i', 'j', 'k',
  'i', 'h', 'k', 'j',
  'j', 'k', 'h', 'i',
  'k', 'j', 'i', 'h'
};

int multi(int as, char a, int bs, char b, char &c) {
  int aidx = static_cast<int>(a - 'h');
  int bidx = static_cast<int>(b - 'h');
  c = kResMatrix[aidx * 4 + bidx];
  return (as * bs * kSignMatrix[aidx * 4 + bidx]);
}

bool PowerFilter(int as, char a, int x) {
  int sign = 1;
  char cur = 'h';
  for (int i = 0; i < x % 4; ++i) {
    sign = multi(sign, cur, as, a, cur);
  }
  return (sign == -1 && cur == 'h');
}

int FindStart(std::string str, int x, int as, char a) {
  int sign = 1;
  char cur = 'h';
  int pos = 0;
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < str.size(); ++j) {
      sign = multi(sign, cur, 1, str[j], cur);
      if (sign == 1 && cur == 'i')
        return pos;
      ++pos;
    }
  }
  return -1;
}

int FindEnd(std::string str, int x, int as, char a) {
  int sign = 1;
  char cur = 'h';
  int pos = x * str.size();
  for (int i = 0; i < x; ++i) {
    for (int j = str.size() - 1; j >=0; --j) {
      --pos;
      sign = multi(1, str[j], sign, cur, cur);
      // fprintf(stderr, "%d %c\n", sign, cur);
      if (sign == 1 && cur == 'k')
        return pos;
    }
  }
  return -1;
}

int main(int argc, char* argv[]) {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int l;
    int64_t xx; 
    scanf("%d %" PRId64 "\n", &l, &xx);
    // int x = static_cast<int> (xx);
    int x;
    if (xx <= 16)
      x = static_cast<int> (xx);
    else 
      x = xx % 8 + 8;
    std::string str(l, ' ');
    int sign = 1;
    char cur = 'h';
    // int sign = multi(1, 'k', 1, 'k', cur);
    // fprintf(stderr, "%d %c\n", sign, cur);
    for (int j = 0; j < l; ++j) {
      scanf("%c", &str[j]);
      sign = multi(sign, cur, 1, str[j], cur);
      // fprintf(stderr, "%d %c\n", sign, cur);
    }
    bool result = PowerFilter(sign, cur, x);
    if (result) {
      int ipos = FindStart(str, x, 1, 'i');
      int kpos = FindEnd(str, x, 1, 'k');
      // fprintf(stderr, "%d %d %d\n", x, ipos, kpos);
      result = (kpos > -1) && (ipos > -1) && (kpos - ipos > 1);
    }
    printf("Case #%d: %s\n", i + 1, result ? "YES" : "NO");
  }
}
