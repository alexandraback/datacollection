#include<iostream>
#include<cstdio>
#define SIZE 256
using namespace std;
char m[SIZE];
void init();
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    FILE* fp = fopen("A.out","w");
    init();
    char s[128];
    int n;
    cin>>n;
    cin.get();
    for(int q = 1 ;q<= n ;q++)
    {
        gets(s);
        char *p = s;
        fprintf(fp,"Case #%d: ",q);
        while(*p)
        {
            fprintf(fp,"%c",m[*p]);
            p++;
        }
        fprintf(fp,"\n");
//        putchar('\n');
    }

    return 0;
}
void init()
{
m['a'] = 'y';m['b'] = 'h';m['c'] = 'e';m['d'] = 's';m['e'] = 'o';
m['f'] = 'c';m['g'] = 'v';m['h'] = 'x';m['i'] = 'd';m['j'] = 'u';
m['k'] = 'i';m['l'] = 'g';m['m'] = 'l';m['n'] = 'b';m['o'] = 'k';
m['p'] = 'r';m['q'] = 'z';m['r'] = 't';m['s'] = 'n';m['t'] = 'w';
m['u'] = 'j';m['v'] = 'p';m['w'] = 'f';m['x'] = 'm';m['y'] = 'a';
m['z'] = 'q';
m[' '] = ' ';


}
