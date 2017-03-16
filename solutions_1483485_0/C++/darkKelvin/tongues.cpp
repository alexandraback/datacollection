#include <stdio.h>
#include <string.h>

char map[256];
char in[300];

char sf[3][100] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
                   "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                   "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
char st[3][100] = {"our language is impossible to understand",
                   "there are twenty six factorial possibilities",
                   "so it is okay if you want to just give up"};

inline void init() {
   map['z']='q';
   map['q']='z';
   for(int i=0;i<3;i++) {
      int l=strlen(sf[i]);
      for(int j=0;j<l;j++)
         map[sf[i][j]]=st[i][j];
   }
}

int main(void)
{
   int t,cas=1;
   init();
   scanf("%d",&t);
   gets(in);
   while(t--) {
      gets(in);
      printf("Case #%d: ",cas++);
      for(int i=0;in[i];i++)
         printf("%c",map[in[i]]);
      puts("");
   }
   return 0;
}
