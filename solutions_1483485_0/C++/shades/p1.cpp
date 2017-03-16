#include<iostream>
#include<stdio.h>

using namespace std;
int main()
{

char a[256];
char t[3][100]={"ejp mysljylc kd kxveddknmc re jsicpdrysi:","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd:","de kr kd eoya kw aej tysr re ujdr lkgc jv:"};
char ans[3][100]={"our language is impossible to understand:","there are twenty six factorial possibilities:","so it is okay if you want to just give up:"};
for(int i=0;i<3;i++)
{
for(int j=0;t[i][j]!=':';j++)
a[t[i][j]]=ans[i][j];
}
a['q']='z';
a['z']='q';
//for(int i=1;i<256;i++)
// printf("%c-> %c\n",i,a[i]);


int n;
cin>>n;
for(int i=1;i<=n;i++)
{
char temp[100];
scanf(" %[^\n]",temp);
cout<<"Case #"<<i<<": ";
for(int i=0;temp[i];i++)
{
cout<<a[temp[i]];
}
cout<<endl;
}

}
