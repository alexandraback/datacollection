#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

char map[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
char str[200];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    getchar();
    for(int t=1;t<=T;t++)
    {
        gets(str);
        int len=strlen(str);
        for(int i=0;i<len;i++)
        {
            if(str[i]>='a'&&str[i]<='z')
            {
                int k=str[i]-'a';
                str[i]=map[k];
            }
        }
        printf("Case #%d: %s\n",t,str);
    }
    return 0;
}
