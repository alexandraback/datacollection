#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
#define MAXL 100
using namespace std;

const int mapping[26]={24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};
char line[MAXL+1];
int len;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int k,t,i;
    gets(line);
    sscanf(line,"%d",&t);
    for(k=0;k<t;k++)
    {
        gets(line);
        len=strlen(line);
        for(i=0;i<len;i++)
        {
            if(!isspace(line[i]))
            {
                line[i]=mapping[line[i]-'a']+'a';
            }
        }
        printf("Case #%d: %s\n",k+1,line);
    }
    return 0;
}
