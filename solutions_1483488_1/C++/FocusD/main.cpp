#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char str[150];
char hash[300];

int change(int a) {
  if(a < 10)
    return 1;
  if(a < 100)
    return 10;
  if(a < 1000)
    return 100;
  if(a < 10000)
    return 1000;
  if(a < 100000)
    return 10000;
  if(a < 1000000)
    return 100000;
  if(a < 10000000)
    return 1000000;
}

int main() {
  freopen("C-large.in", "r", stdin);
  freopen("1.txt", "w", stdout);
  int casenum;
  scanf("%d", &casenum);
  int num = 1;
  int a, b;
  while(casenum--) {
    scanf("%d%d", &a, &b);
    int tmp, tb, temp;
    int ans = 0;
    for(int i = a; i <= b ; ++i) {
      temp = change(i);
      tmp = (i % 10) * temp + i / 10;
      while(tmp) {
        if(tmp == i)
          break;
        if(tmp > i && tmp >= a && tmp <= b) {
          ++ans;
        }
        tmp = (tmp % 10) * temp + tmp / 10;
      }
    }
    printf("Case #%d: %d\n",num++, ans);
  }
  return 0;
}
