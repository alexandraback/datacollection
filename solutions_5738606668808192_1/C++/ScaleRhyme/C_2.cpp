#ifndef FLLD
#ifdef WIN32
#define FLLD "%I64d"
#else
#define FLLD "%lld"
#endif
#endif

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <ctime>
#include <tuple>
#include <random>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define NOKEY(x,y) ((x).find(y) == (x).end())
#define EXISTKEY(x,y) ((x).find(y) != (x).end())
#define INCMAP(x, y) ((x)[y] = MAPINTV(x, y) + 1)
#define MAPINTV(x, y) (EXISTKEY(x, y) ? (x)[y] : 0)
typedef long long ll;

using namespace std;

string to2(int x, int len)
{
  string result = "";
  for (int i = 0; i < len; i ++, x /= 2) {
    if (x % 2 == 0)
      result = '0' + result;
    else
      result = '1' + result;
  }
  return result;
}

long long to10(string x, int base) {
  long long result = 0;
  for (int i = 0; i < x.length(); i ++) {
    result = result * base + x[i] - '0';
  }
  return result;
}

int main() {
  freopen("c-large2.ans", "w", stdout);
  printf("Case #1:\n");
  int n = 32;
  int bigj = 500;
  for (int i = 0; i < bigj; i ++)
  {
    string a = "1" + to2(i, n / 2 - 2) + "1";
    printf("%s%s", a.c_str(), a.c_str());
    for (int j = 2; j <= 10; j ++)
      printf(" " FLLD, to10(a, j));
    printf("\n");
  }
  return 0;
}
