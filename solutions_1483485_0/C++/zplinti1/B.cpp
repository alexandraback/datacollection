#include <stdio.h>
#include <string.h>
int mp[100]={24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};

char s[200];

int main()
{
    int cas;

    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    scanf("%d",&cas);gets(s);
    for(int ii=1;ii<=cas;ii++)
    {
        printf("Case #%d: ",ii);
        gets(s);
        for(int i=0;s[i];i++)
        {
            if (s[i]==' ') putchar(' ');
            else putchar(mp[s[i]-'a']+'a');
        }
        puts("");
    }
    return 0;
}
