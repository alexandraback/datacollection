#include <stdio.h>
#include <string.h>

char t[26];
char s[128];

int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T, i0;
  int i, j, n;
  const char *s1, *s2;
  s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
  s2 = "our language is impossible to understand";
  n = strlen(s1);
  for(i = 0; i < n; i++)
    if(s1[i] != ' ')
      t[s1[i]-'a'] = s2[i];
  s1 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
  s2 = "there are twenty six factorial possibilities";
  n = strlen(s1);
  for(i = 0; i < n; i++)
    if(s1[i] != ' ')
      t[s1[i]-'a'] = s2[i];
  s1 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
  s2 = "so it is okay if you want to just give up";
  n = strlen(s1);
  for(i = 0; i < n; i++)
    if(s1[i] != ' ')
      t[s1[i]-'a'] = s2[i];
  j = 'a';
  while(1){
    for(i = 0; i < 26 && t[i] != j; i++);
    if(i == 26)
      break;
    j++;
  }
  t['z'-'a'] = 'q';
  t['q'-'a'] = 'z';
  /*for(i = 0; i < 26; i++)
    putchar(t[i]);*/
  scanf("%d\n", &T);
  for(i0 = 1; i0 <= T; i0++){
    gets(s);
    n = strlen(s);
    for(i = 0; i < n; i++)
      if(s[i] != ' ')
        s[i] = t[s[i]-'a'];
    printf("Case #%d: %s\n", i0, s);
  }
}
