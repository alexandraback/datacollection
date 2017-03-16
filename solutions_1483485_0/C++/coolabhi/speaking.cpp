#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<cctype>
#include<climits>
#define pp pair<int,int>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    map<char,char> m;
    string s1="abcdefghijklmnopqrstuvwxyz";
    string s2="yhesocvxduiglbkrztnwjpfmaq";
    int t,i,j;
    for(i=0;i<26;i++)
    m[s1[i]]=s2[i];
    char ch[150];
    scanf("%d",&t);
     cin.ignore();
    for(i=1;i<=t;i++)
    {
           
            cin.getline(ch,150);
            printf("Case #%d: ",i);
            for(j=0;j<strlen(ch);j++)
              if(ch[j]!=' ')
                printf("%c",m[ch[j]]);
              else printf(" ");
            printf("\n");
    }
    return 0;
}
