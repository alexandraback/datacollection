#include <stdio.h>
char* input[] = {
"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"our language is impossible to understand",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"there are twenty six factorial possibilities",
"de kr kd eoya kw aej tysr re ujdr lkgc jv",
"so it is okay if you want to just give up"
};
char mp[1000], s[1000];
char* s1, *s2;
int n;
int main()
{
mp['q'] = 'z';
mp['e'] = 'o';
mp['y'] = 'a';
for(int i=0;i<3;i++)
   {
   s1 = input[i<<1];
   s2 = input[(i<<1)+1];
   for(int j=0;s1[j];j++)
      mp[s1[j]] = s2[j];
   }
mp['z'] = 'q';
for(int i='a';i<='z';i++)
   printf("%c %c\n",i, mp[i]);
freopen("A-small.in","r",stdin);
freopen("A-small.out","w",stdout);
scanf("%d\n",&n);
for(int i=1;i<=n;i++)
   {
   printf("Case #%d: ", i);
   gets(s);
   for(int j=0;s[j];j++)
      putchar(mp[s[j]]);
   printf("\n");
   }
return 0;
}
