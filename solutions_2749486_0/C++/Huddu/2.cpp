#include "stdio.h"
#include <string.h>
#include <string>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  for(int x=1; x<=t; x++) {
    int a,b;
    scanf("%d %d", &a, &b);
    string shor = "WE";
    if (a < 0) {
      shor = "EW";
      a *= -1;
    }
    string sver = "SN";
    if (b < 0) {
      sver = "NS";
      b *= -1;
    }
    string ans = "";
    for (int c=0; c<a; c++) {
      ans += shor;
    }
    for (int c=0; c<b; c++) {
      ans += sver;
    }
    printf("Case #%d: %s\n", x, ans.c_str());
  }
}