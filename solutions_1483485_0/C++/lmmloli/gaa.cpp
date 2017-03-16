#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[26]={121,104,101,115,111,99,118,120,100,117,105,103,108,98,107,114,122,116,110,119,106,112,102,109,97,113};
int main()
{
    int len,i,j,t,ca=0;
    char s[10000];
    freopen("A-small-attempt7.in","r",stdin);
    freopen("gaa.out","w",stdout);
    scanf("%d",&t);
    gets(s);
    while (t--)
    {
        gets(s);
        len=strlen(s);
        for (i=0;i<len;i++)
        {
            if (s[i]>='a' && s[i]<='z')
            s[i]=a[s[i]-'a'];
        }
        printf("Case #%d: %s\n",++ca,s);
    }
    return 0;
}
