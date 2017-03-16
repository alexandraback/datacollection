#include"stdio.h"
#include"map"
using namespace std;
int main(){
  map<char,char> m;
  m['a']='y';
m['b']='h';
m['c']='e';
m['d']='s';
m['e']='o';
m['f']='c';
m['g']='v';
m['h']='x';
m['i']='d';
m['j']='u';
m['k']='i';
m['l']='g';
m['m']='l';
m['n']='b';
m['o']='k';
m['p']='r';
m['q']='z';
m['r']='t';
m['s']='n';
m['t']='w';
m['u']='j';
m['v']='p';
m['w']='f';
m['x']='m';
m['y']='a';
m['z']='q';
m[' ']=' ';
    char inp[10000];
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++){
      gets(inp);
      int j=0;
      printf("Case #%d: ",i+1);
      while(inp[j])
	printf("%c",m[inp[j]]),j++;
      printf("\n");
    }
}