#include <cstdio>
#include <cstring>
int main()
{
    freopen("a.out","w",stdout);
    int t;
    int a[30]={24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};
    scanf("%d",&t);
    getchar();
    int cas = 0;
    while(t--)
    {
        char s[110];
        gets(s);
        printf("Case #%d: ",++cas);
        for(int i=0; s[i]; i++)
        if(s[i]!=' ' )
        {
            printf("%c",a[s[i]-'a']+'a');
        }
        else printf(" ");
        printf("\n");
    }


    return 0;
}
