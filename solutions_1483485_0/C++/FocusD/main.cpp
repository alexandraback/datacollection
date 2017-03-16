#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char hash[500];

string a1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
string a2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
string a3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
string b1 = "our language is impossible to understand";
string b2 = "there are twenty six factorial possibilities";
string b3 = "so it is okay if you want to just give up";

void init() {
  int i;
  memset(hash, 0, sizeof(hash));
  for(i = 0; i < a1.length(); ++i)
    hash[a1[i]] = b1[i];
  for(i = 0; i < a2.length(); ++i)
    hash[a2[i]] = b2[i];
  for(i = 0; i < a3.length(); ++i)
    hash[a3[i]] = b3[i];
  hash['z'] = 'q';
  hash['q'] = 'z';
}

int main() {
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.txt", "w", stdout);
  init();
  int n, cas = 0;
  char tmp;
  scanf("%d", &n);
  while(scanf("%c", &tmp) != EOF) {
    if(tmp == '\n') {
      ++cas;
      if(cas != 1 && cas <= n)
        printf("\n");
      if(cas <= n)
        printf("Case #%d: ", cas);
    }
    else {
      if(tmp == ' ')
        printf(" ");
      else
        printf("%c", hash[tmp]);
    }
  }
  return 0;
}
