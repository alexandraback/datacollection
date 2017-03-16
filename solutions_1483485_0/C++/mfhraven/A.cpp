#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
char a[26];
char s[1000];
int test;

int main()
{
    a[0]='y';   a[1]='h';   a[2]='e';   a[3]='s';   a[4]='o';   a[5]='c';
    a[6]='v';   a[7]='x';   a[8]='d';   a[9]='u';   a[10]='i';  a[11]='g';
    a[12]='l';  a[13]='b';  a[14]='k';  a[15]='r';  a[16]='z';  a[17]='t';
    a[18]='n';  a[19]='w';  a[20]='j';  a[21]='p';  a[22]='f';  a[23]='m';
    a[24]='a';  a[25]='q';   
    scanf("%d",&test);      char c=getchar();
    
    for (int k=1;k<=test;k++)
    {
        gets(s);
        for (int i=0;i<strlen(s);i++)   
        if (s[i]>='a' && s[i]<='z') s[i]=a[s[i]-'a'];
        printf("Case #%d: %s\n",k,s);
    }
    
    //system("pause");
} 
