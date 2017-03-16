#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 110;
const int MAXA = 26;

const char* orig[3] = {
  "ejp mysljylc kd kxveddknmc re jsicpdrysi",
  "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
  "de kr kd eoya kw aej tysr re ujdr lkgc jv",
};

const char* res[3] = {
  "our language is impossible to understand",
  "there are twenty six factorial possibilities",
  "so it is okay if you want to just give up",
};

char mp[MAXA];
char s[MAXN];

void pre()
{
  memset(mp, 0, sizeof(mp));
  for (int i = 0; i < 3; ++i) {
    int len = strlen(orig[i]);
    for (int j = 0; j < len; ++j) {
      if (orig[i][j] == ' ') continue;
      mp[orig[i][j]-'a'] = res[i][j];
    }
  }
  mp['z'-'a'] = 'q';
  mp['q'-'a'] = 'z';

  //  for (int i = 0; i < MAXA; ++i) printf("%c %c\n", 'a' + i, mp[i]);
}

void solve()
{
  int len = strlen(s);
  for (int i = 0; i < len; ++i) {
    if (s[i] == ' ') continue;
    s[i] = mp[s[i]-'a'];
  }
  puts(s);
}

int main()
{
  pre();

  int t;
  scanf("%d", &t);
  getchar();
  for (int l = 1; l <= t; ++l) {
    printf("Case #%d: ", l);
    gets(s);
    solve();
  }
  return 0;
}

