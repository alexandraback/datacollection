#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    //freopen("cpp.in","r",stdin);
    //freopen("cpp.out","w",stdout);
    char s[30],str[150];
    int i,t,n,num;
    s[0]='y';s[1]='h';s[2]='e';s[3]='s';s[4]='o';
    s[5]='c';s[6]='v';s[7]='x';s[8]='d';s[9]='u';
    s[10]='i';s[11]='g';s[12]='l';s[13]='b';s[14]='k';
    s[15]='r';s[16]='z';s[17]='t';s[18]='n';s[19]='w';
    s[20]='j';s[21]='p';s[22]='f';s[23]='m';s[24]='a';
    s[25]='q';
    n=0;
    cin>>num;
    gets(str);
    while(num--)
    {
        gets(str);
        n++;
        for(i=0;i<strlen(str);i++)
            if(str[i]!=' ')
            {
                 t=(int)str[i]-'a';
                 str[i]=s[t];
            }
        cout<<"Case #"<<n<<": "<<str<<endl; 
    }
}
