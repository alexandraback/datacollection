#include <cstdio>
#include <cstring>
using namespace std;
char str[10005]="";
char ch[256]="";
int main()
{int n,m,i,j,k,l,T,tt;
 freopen("A.in","r",stdin);
 freopen("A.txt","w",stdout);
 scanf("%d\n",&T);
 ch['a']='y';
 ch['b']='h';
 ch['c']='e';
 ch['d']='s';
 ch['e']='o';
 ch['f']='c';
 ch['g']='v';
 ch['h']='x';
 ch['i']='d';
 ch['j']='u';
 ch['k']='i';
 ch['l']='g';
 ch['m']='l';
 ch['n']='b';
 ch['o']='k';
 ch['p']='r';
 ch['q']='z';
 ch['r']='t';
 ch['s']='n';
 ch['t']='w';
 ch['u']='j';
 ch['v']='p';
 ch['w']='f';
 ch['x']='m';
 ch['y']='a';
 ch['z']='q';
 ch[' ']=' ';
 tt=0;
 while(T--)
 {tt++;
  gets(str);
  printf("Case #%d: ",tt);
  for(int i=0;str[i]!='\0';i++)putchar(ch[str[i]]);
  putchar('\n');
 }
 return 0;
}
