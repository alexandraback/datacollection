#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int a[1001],test;
char ch;
int main(){
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    a['a']='y'; a['b']='h'; a['c']='e'; a['d']='s'; a['e']='o';
    a['f']='c'; a['g']='v'; a['h']='x'; a['i']='d'; a['j']='u';
    a['k']='i'; a['l']='g'; a['m']='l'; a['n']='b'; a['o']='k';
    a['p']='r'; a['q']='z'; a['r']='t'; a['s']='n'; a['t']='w';
    a['u']='j'; a['v']='p'; a['w']='f'; a['x']='m'; a['y']='a';
    a['z']='q';
    scanf("%d\n",&test);
    for (int i=1;i<=test;i++)
    {
        printf("Case #%d: ",i);
        while (ch=getchar(),ch!='\r' && ch!='\n') 
            if (ch==' ') printf(" ");
            else printf("%c",a[ch]);
        printf("\n");
    }
}
        
