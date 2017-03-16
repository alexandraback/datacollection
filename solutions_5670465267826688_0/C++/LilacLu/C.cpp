#include <cstdio>

#define small
//#define large

int t, l, x;
char inp[10005], s[10005];

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

int main()
{
#ifdef small
  freopen("small.in", "r", stdin);
  freopen("small.out", "w", stdout);
#endif
#ifdef large
  freopen("large.in", "r", stdin);
  freopen("large.out", "w", stdout);
#endif
  scanf("%d", &t);
  for (int Case = 1; Case <= t; ++Case) {
    scanf("%d %d", &l, &x);
    scanf("%s", inp);
    for (int i = 0; i < x; ++i)
      for (int j = 0; j < l; ++j)
        s[i * l + j] = inp[j];
    char key[] = {'i', 'j', 'k'}, now = ' ';
    int neg = 0, top = 0;
    for (int i = 0; i < x * l; ++i) {
      change(now, neg, s[i]);
      if (top == 3)
        continue;
      if (now == key[top])
        ++top, now = ' ';
//      printf("%c %d\n", now, neg);
    }
    printf("Case #%d: ", Case);
    if (top == 3 && now == ' ' && neg == 0)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
