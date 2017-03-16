#include<stdio.h>
#include<iostream>
#include<map>

using namespace std;

int main()
{
  map<char, char> abc;
  char G[150];
  int T,t,i;
  abc[' ']=' ';
  abc['y']='a';
  abc['n']='b';
  abc['f']='c';
  abc['i']='d';
  abc['c']='e';
  abc['w']='f';
  abc['l']='g';
  abc['b']='h';
  abc['k']='i';
  abc['u']='j';
  abc['o']='k';
  abc['m']='l';
  abc['x']='m';
  abc['s']='n';
  abc['e']='o';
  abc['v']='p';
  abc['z']='q';
  abc['p']='r';
  abc['d']='s';
  abc['r']='t';
  abc['j']='u';
  abc['g']='v';
  abc['t']='w';
  abc['h']='x';
  abc['a']='y';
  abc['q']='z';
  scanf("%d\n",&T);
  for(t=1;t<=T;t++)
  {
    gets(G);
    for(i=0;G[i];i++)
    {
      G[i]=abc[G[i]];
    }
    printf("Case #%d: ",t);
    puts(G);
  }
  return 0;
}