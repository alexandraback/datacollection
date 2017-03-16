//program A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;

map<char,char> New;

void Calc()
{
  New['a']='y';
  New['b']='h';
  New['c']='e';
  New['d']='s';
  New['e']='o';
  New['f']='c';
  New['g']='v';
  New['h']='x';
  New['i']='d';
  New['j']='u';
  New['k']='i';
  New['l']='g';
  New['m']='l';
  New['n']='b';
  New['o']='k';
  New['p']='r';
  New['q']='z';
  New['r']='t';
  New['s']='n';
  New['t']='w';
  New['u']='j';
  New['v']='p';
  New['w']='f';
  New['x']='m';
  New['y']='a';
  New['z']='q';
}

int main()
{
  freopen("Input.txt","r",stdin);
  freopen("Output.txt","w",stdout);
  Calc();
  int TotalTest,Test=0;scanf("%d",&TotalTest);
  while(Test++<TotalTest)
    {
	  printf("Case #%d: ",Test);
	  char c=getchar();
	  if(c!=10)putchar(New[c]);
	  while(c=getchar(),c!=10)
	    putchar((c==' ')?' ':New[c]);
	  putchar('\n');
	}
  return 0;
}
