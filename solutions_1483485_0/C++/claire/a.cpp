#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;
char s[10000];
int  a[100]={24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,
             19,13,22,9,15,5,12,0,16};

/*void init()
{

    char s1[10000],s2[10000];
    int i,j;
    for (i=1; i<=3; i++)
    {
        cin.getline(s1,10000,'\n');
        cin.getline(s2,10000,'\n');
        int m=strlen(s1);
        for (j=0; j<m; j++)
         a[s1[j]-'a']=s2[j]-'a';
    }
    a['z'-'a']='q'-'a';
    a['q'-'a']='z'-'a';
    for (i=0; i<26; i++)
     cout<<a[i]<<',';

}*/

int main()
{
    int cas,n,j,t;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.txt","w",stdout);
    //init();
    cin>>t;
    cin.getline(s,10000,'\n');
    for (cas=1; cas<=t; cas++)
    {
        cin.getline(s,10000,'\n');
        printf("Case #%d: ",cas);
        n=strlen(s);
        for (j=0; j<n; j++)
         if (s[j]!=' ')
          s[j]=(char)(a[s[j]-'a']+'a');
        printf("%s\n",s);
    }
}
