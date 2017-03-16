#include<cstdio>

char s[26];
char b1[100][100],b2[100][100];
char ss[10000];
int t,id=0;

int main()
{
    for (int i=0;i<23;i++)
        scanf("%s",b1[i]);
    for (int i=0;i<23;i++)
        scanf("%s",b2[i]);
    for (int i=0;i<23;i++)
        for (int j=0;b1[i][j];j++)
            s[b1[i][j]-'a']=b2[i][j]-'a';
    s['q'-'a']='z'-'a';
    s['z'-'a']='q'-'a';

    
    freopen("input.txt","r",stdin);
    scanf("%d",&t);gets(ss);
    for (;t--;)
    {
        gets(ss);
        printf("Case #%d: ",++id);
        for (int i=0;ss[i];i++)
        if (ss[i]>='a' && ss[i]<='z')
            printf("%c",s[ss[i]-'a']+'a');
        else printf("%c",ss[i]);
        printf("\n");
    }
}

