#include <cstdio>
#include <algorithm>

using namespace std;

//#define small
#define large

int t, l, x;
char inp[10005], s[100005];

void change(char& now, int& neg, const char& c) {
  if (now == ' ')
    now = c;
  else if (now == 'i') {
    if (c == 'i')
      now = ' ', neg ^= 1;
    else if (c == 'j')
      now = 'k';
    else
      now = 'j', neg ^= 1;
  } else if (now == 'j') {
    if (c == 'i')
      now = 'k', neg ^= 1;
    else if (c == 'j')
      now = ' ', neg ^= 1;
    else
      now = 'i';
  } else {
    if (c == 'i')
      now = 'j';
    else if (c == 'j')
      now = 'i', neg ^= 1;
    else
      now = ' ', neg ^= 1;
  }
}

void doAll(char& c, int& neg, const char* sss) {
  for (int i = 0; i < l; ++i)
    change(c, neg, sss[i]);
}

int main()
{
#ifdef small
  freopen("small.in", "r", stdin);
  freopen("small_1.out", "w", stdout);
#endif
#ifdef large
  freopen("large.in", "r", stdin);
  freopen("large.out", "w", stdout);
#endif
  scanf("%d", &t);
  for (int Case = 1; Case <= t; ++Case) {
    scanf("%d %d", &l, &x);
    scanf("%s", inp);
    char lastC = ' ';
    int lastN = 0;
    doAll(lastC, lastN, inp);
    for (int i = 0; i < x && i < 10; ++i)
      for (int j = 0; j < l; ++j)
        s[i * l + j] = inp[j];
    s[min(x, 10) * l] = '\0';
    char key[] = {'i', 'j', 'k'}, now = ' ';
    int neg = 0, top = 0;
    for (int i = 0; i < min(x, 10) * l; ++i) {
      change(now, neg, s[i]);
      if (top == 3)
        continue;
      if (now == key[top])
        ++top, now = ' ';
    }
    bool ans = false;
    if (top == 3) {
      if (x <= 10) {
        if (neg == 0 && now == ' ')
          ans = true;
      } else {
        if (lastC == now || now == ' ') {
          if (lastC == ' ') {
            if (lastN == 0) {
              if (neg == 0)
                ans = true;
            } else {
              lastN = ((x - 10) & 1);
              lastN ^= neg;
              if (lastN == 0)
                ans = true;
            }
          } else {
            if (now != ' ') {
              if (x & 1) {
                if (lastN == 1)
                  lastN = ((x - 10) & 1);
                lastN ^= (((x - 9) / 2) & 1);
                lastN ^= neg;
                if (lastN == 0)
                  ans = true;
              }
            } else {
              if (!(x & 1)) {
                if (lastN == 1)
                  lastN = ((x - 10) & 1);
                lastN ^= (((x - 10) / 2) & 1);
                lastN ^= neg;
                if (lastN == 0)
                  ans = true;
              }
            }
          }
        }
      }
    }
//    printf("%d %c %d %c %d %d %d\n", top, now, neg, lastC, lastN, l, x);
    printf("Case #%d: ", Case);
    if (ans)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
