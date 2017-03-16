#include <cstdio>
#include <algorithm>

char to[300];

int main() {
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
   
   char* cl = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
   char* x = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";

   for(int i = 0; i < strlen(cl); i++) {
      to[x[i]] = cl[i];
   }
   
   to['y'] = 'a';
   to['e'] = 'o';
   to['q'] = 'z';
   to['z'] = 'q';
   
   int n;
   scanf("%d\n", &n);
   char buf[10000];
   for(int i = 0; i < n; i++) {
      gets(buf);
      
      printf("Case #%d: ", i+1);
      for(int j = 0; j < strlen(buf); j++) {
         printf("%c", to[buf[j]]);
      }
      
      printf("\n");
   }
}
