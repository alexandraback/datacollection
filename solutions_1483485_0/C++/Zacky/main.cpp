#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 300;
char hash[maxn],str[102];
int n;

void init()
{
    hash['a'] = 'y';
    hash['b'] = 'h';
    hash['c'] = 'e';
    hash['d'] = 's';
    hash['e'] = 'o';
    hash['f'] = 'c';
    hash['g'] = 'v';
    hash['h'] = 'x';
    hash['i'] = 'd';
    hash['j'] = 'u';
    hash['k'] = 'i';
    hash['l'] = 'g';
    hash['m'] = 'l';
    hash['n'] = 'b';
    hash['o'] = 'k';
    hash['p'] = 'r';
    hash['q'] = 'z';
    hash['r'] = 't';
    hash['s'] = 'n';
    hash['t'] = 'w';
    hash['u'] = 'j';
    hash['v'] = 'p';
    hash['w'] = 'f';
    hash['x'] = 'm';
    hash['y'] = 'a';
    hash['z'] = 'q';
    return;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    init();
    int cas,i = 0;
    scanf("%d",&cas);
    getchar();
    while(i < cas)
    {
        gets(str);
        printf("Case #%d: ",++i);
        for(int j=0;str[j] != '\0';j++)
        {
            if(str[j] == ' ')
            {
                printf(" ");
            }
            else
            {
                printf("%c",hash[str[j]]);
            }
        }
        printf("\n");
    }
    return 0;
}
