#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[150];
char hash[300];
int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("1.txt", "w", stdout);
hash['a']='y';
hash['b']='h';
hash['c']='e';
hash['d']='s';
hash['e']='o';
hash['f']='c';
hash['g']='v';
hash['h']='x';
hash['i']='d';
hash['j']='u';
hash['k']='i';
hash['l']='g';
hash['m']='l';
hash['n']='b';
hash['o']='k';
hash['p']='r';
hash['q']='z';
hash['r']='t';
hash['s']='n';
hash['t']='w';
hash['u']='j';
hash['v']='p';
hash['w']='f';
hash['x']='m';
hash['y']='a';
hash['z']='q';
hash[' ']=' ';
    int casenum;
    scanf("%d",&casenum);
    getchar();
    int num=1;
    while(casenum--)
    {
        gets(str);
        int len=strlen(str);
        printf("Case #%d: ",num++);
        for(int i=0;i<len;++i)
           printf("%c",hash[str[i]]);
        printf("\n");
    }
    return 0;
}
