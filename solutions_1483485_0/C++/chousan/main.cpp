#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;
map<char,char>a;
int main()
{
    freopen("in1.txt","r",stdin);
    freopen("out.txt","w",stdout);
    a['a']='y';
     a['b']='h';//
      a['c']='e';
       a['d']='s';
        a['e']='o';
         a['f']='c';
          a['g']='v';
       a['h']='x';
        a['i']='d';
         a['j']='u';
          a['k']='i';
       a['l']='g';
        a['m']='l';
         a['n']='b';
          a['o']='k';
       a['p']='r';
        a['q']='z';//
         a['r']='t';
          a['s']='n';
       a['t']='w';
        a['u']='j';
         a['v']='p';
          a['w']='f';
       a['x']='m';
        a['y']='a';
         a['z']='q';
         int n;
         char x[10];
         scanf("%d",&n);gets(x);
         for(int cas=1;cas<=n;++cas)
         {
             char str[110];
             gets(str);
             int i,len=strlen(str);
             char ans[110];
             for(i=0;i<len;++i)
             {
                 if(str[i]>='a'&&str[i]<='z')
                 ans[i]=a[str[i]];
                 else ans[i]=str[i];
             }
             ans[i]='\0';
             printf("Case #%d: ",cas);
             puts(ans);
         }
}
