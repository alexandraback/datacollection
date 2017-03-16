#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
#define intin(a) scanf("%d",&a)
#define intsin(a,b) scanf("%d%d",&a,&b)
#define swap(a,b) c=a;a=b;b=c
#define MIN(a,b) a<b?a:b
using namespace std;
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    ofstream file1("output.txt");
    int cases,l,x=0;
    char s[201];
    int map[123];
    map['a']='y';    map['b']='h';    map['c']='e';
    map['d']='s';    map['e']='o';    map['f']='c';
    map['g']='v';    map['h']='x';    map['i']='d';
    map['j']='u';    map['k']='i';    map['l']='g';
    map['m']='l';    map['n']='b';    map['o']='k';
    map['p']='r';    map['q']='z';    map['r']='t';
    map['s']='n';    map['t']='w';    map['u']='j';
    map['v']='p';    map['w']='f';    map['x']='m';
    map['y']='a';    map['z']='q';

    intin(cases);getchar();
    while(++x<=cases)
    {
        gets(s);
        l=strlen(s);
        for(int i=0;i<l;i++)
            if(s[i]!=32)
                s[i]=map[s[i]];

        //cout<<s<<endl;
        //printf("Case #%d: %s\n",x,s);
        file1<<"Case #"<<x<<": "<<s<<endl;

    }
    return 0;
}
