#include <cstdio>
#include <cstring>

const char* m = "yhesocvxduiglbkrztnwjpfmaq";
char b[2000000];

main() {
  int t,cid=1;
  scanf("%d ", &t);
  while (t--) {
    fgets(b, sizeof(b), stdin);
    for (char* c = b; *c; c++) if (*c <= 'z' && *c >= 'a') *c = m[*c-'a'];
    printf("Case #%d: %s", cid++, b);
  }
}

/*char s1[200], s2[200];
char map[30];

void run() {
  gets(s1);
  gets(s2);
  //scanf("%s %s", s1, s2);
  int len = strlen(s1);
  for (int i = 0; i < len; i++) map[s1[i]-'a'] = s2[i];
}

main() {
  int n;
  scanf("%d ", &n);
  while (n--) run();
  map['q'-'a'] = 'z';
  map['z'-'a'] = 'q';
  for (char i = 'a'; i <= 'z'; i++) {
    putchar(map[i-'a']);
//    printf("%c: %c\n", i, map[i-'a'] ? map[i-'a'] : '_');
  }
  puts("");
}*/