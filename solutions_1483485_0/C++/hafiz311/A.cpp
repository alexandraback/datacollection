#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;


string s1,s2,s3;

string s4,s5,s6;

char mp[500];

char line[500];


int main()
{
    freopen("in.txt","rt",stdin);
    freopen("A.out","wt",stdout);
    s1="ejp mysljylc kd kxveddknmc re jsicpdrysi";
    s2="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
    s3="de kr kd eoya kw aej tysr re ujdr lkgc jv";
    s4="our language is impossible to understand";
    s5="there are twenty six factorial possibilities";
    s6="so it is okay if you want to just give up";

    for(int i=0;i<s1.size();i++) mp[s1[i]]=s4[i];
    for(int i=0;i<s2.size();i++) mp[s2[i]]=s5[i];
    for(int i=0;i<s3.size();i++) mp[s3[i]]=s6[i];
    mp['q']='z';mp['z']='q';


    //for(int i='a';i<='z';i++) cout<<(char)(i) << " "<<(char)(mp[i])<<endl;
    //mp['q']='z';mp['z']=q;



    int t,cas;
    scanf("%d",&t);
    gets(line);
    for(cas=1;cas<=t;cas++)
    {
        gets(line);
        int len=strlen(line);
        printf("Case #%d: ",cas);
        for(int i=0;i<len;i++) printf("%c",mp[line[i]]);
        printf("\n");
    }

    return 0;
}
