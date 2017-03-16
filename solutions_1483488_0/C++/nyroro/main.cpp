#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char map[200];
int main()
{
    map['a']='y';
    map['b']='h';
    map['c']='e';
    map['d']='s';
    map['e']='o';
    map['f']='c';
    map['g']='v';
    map['h']='x';
    map['i']='d';
    map['j']='u';
    map['k']='i';
    map['l']='g';
    map['m']='l';
    map['n']='b';
    map['o']='k';
    map['p']='r';
    map['q']='z';//
    map['r']='t';
    map['s']='n';
    map['t']='w';
    map['u']='j';
    map['v']='p';
    map['w']='f';
    map['x']='m';
    map['y']='a';
    map['z']='q';//

    char str[500];

    int ti=1;

    int t;
    scanf("%d",&t);
    getchar();
    for(ti=1;ti<=t;ti++)
    {
        gets(str);
        cout<<"Case #"<<ti<<": ";
        for(int i=0;i<strlen(str);i++)
        {
            if(islower(str[i]))
                putchar(map[str[i]]);
            else
                putchar(str[i]);
        }
        cout<<endl;
    }


    return 0;
}
