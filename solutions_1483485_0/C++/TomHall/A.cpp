#include<iostream>
#include<stdio.h>
#include<cstring>
#include <fstream>

using namespace std;

char encry[200],decry[200];

FILE *in,*out;

char mapping(char a)
{
    if (a=='y')
        return 'a';
    if (a=='n')
        return 'b';
    if (a=='f')
        return 'c';
    if (a=='i')
        return 'd';
    if (a=='c')
        return 'e';
    if (a=='w')
        return 'f';
    if (a=='l')
        return 'g';
    if (a=='b')
        return 'h';
    if (a=='k')
        return 'i';
    if (a=='u')
        return 'j';
    if (a=='o')
        return 'k';
    if (a=='m')
        return 'l';
    if (a=='x')
        return 'm';
    if (a=='s')
        return 'n';
    if (a=='e')
        return 'o';
    if (a=='v')
        return 'p';
    if (a=='z')
        return 'q';
    if (a=='p')
        return 'r';
    if (a=='d')
        return 's';
    if (a=='r')
        return 't';
    if (a=='j')
        return 'u';
    if (a=='g')
        return 'v';
    if (a=='t')
        return 'w';
    if (a=='h')
        return 'x';
    if (a=='a')
        return 'y';
    if (a=='q')
        return 'z';
    return a;
}

int main()
{
    in=freopen("A-small.in","r",stdin);
    out=freopen("output.txt","w",stdout);
    int n,j;
    scanf("%d\n",&n);
    for (int i=0;i<n;i++)
    {
        cin.getline(encry,300);
        j=0;
        while (encry[j]!='\0')
        {

            decry[j]=mapping(encry[j]);
            j++;
        }
        cout<<"Case #"<<i+1<<": "<<decry<<endl;
        memset(encry,0,sizeof(encry));
        memset(decry,0,sizeof(decry));
    }
    return 0;
}
