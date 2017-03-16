#include <cstdio>
#include <cstring>

const int MAXN = 500;
const char a[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i',
                     'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 
                      'f', 'm', 'a', 'q'};

int n;
char s[MAXN];
char t[MAXN];

void init()
{
   int i;
   for (i = 0; i < 255; ++i)
      t[i] = i;
   for (i = 0; i < 26; ++i)
      t['a' + i] = a[i];
}

int main()
{
   init();
   scanf("%d\n", &n);
   int cases;
   char *i;
   for (cases = 1; cases <= n; ++cases)
   {
      gets(s);
      for (i = s; (*i) != '\0'; ++i)
         (*i) = t[*i];
      printf("Case #%d: %s\n", cases, s);
   }
   return 0;
}