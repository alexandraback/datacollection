#include<stdio.h>
#include<string.h>
int n;
char c[300];
char a[300];
char map[300];
int main()
{
    int i,j,k;
    int p,q,r;
    char cc;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&n);
    scanf("%c",&cc);

map['a'] = 'y';
map['b'] = 'h';
map['c'] = 'e';
map['d'] = 's';
map['e'] = 'o';
map['f'] = 'c';
map['g'] = 'v';
map['h'] = 'x';
map['i'] = 'd';
map['j'] = 'u';
map['k'] = 'i';
map['l'] = 'g';
map['m'] = 'l';
map['n'] = 'b';
map['o'] = 'k';
map['p'] = 'r';
map['q'] = 'z';
map['r'] = 't';
map['s'] = 'n';
map['t'] = 'w';
map['u'] = 'j';
map['v'] = 'p';
map['w'] = 'f';
map['x'] = 'm';
map['y'] = 'a';
map['z'] = 'q';
map[' '] = ' ';

   for(i=0;i<n;i++)
    {
      gets(c);
      printf("Case #%d: ",i+1);
      for(j=0;c[j]!='\0';j++)
       {
         printf("%c",map[c[j]]);
       }
      if(i<n-1)printf("\n");
    }

  
  /*  for(i=0;i<300;i++)map[i]='.';
    for(i=0;i<n;i++)
     {
       gets(c);
       gets(a);
       for(j=0;c[j]!='\0';j++)
        {
          if(map[c[j]]=='.')
           {
             map[c[j]]=a[j];
           }
          else 
           {
             if(map[c[j]]!=a[j])printf("fuck");
           }
        }
     }
    map['q']='z';
   map['z']='q';
    for(i='a';i<='z';i++)
     {
       printf("map['%c'] = '%c';\n",i,map[i]);
     }
     */
    
    
    scanf(" ");
    return 0;
}
// http://code.google.com/codejam
/*
3
ejp mysljylc kd kxveddknmc re jsicpdrysi
our language is impossible to understand
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
there are twenty six factorial possibilities
de kr kd eoya kw aej tysr re ujdr lkgc jv
so it is okay if you want to just give up
*/
