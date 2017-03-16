#include <cstdio>
#include <cstring>
const char s[]="ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
const char t[]="our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
char c[260],buf[110];
bool f[260],g[260];
int main()
{
    int n=strlen(s);
    printf("%s\n",s);
    for (int i=0;i<n;i++)
    {
        f[s[i]]=true;
        g[t[i]]=true;
        c[s[i]]=t[i];
    }
/*    for (int i='a';i<='z';i++)
    {
        printf("%c %d %d\n",i,f[i],g[i]);
        for (int j='a';j<='z';j++)
            if (!f[i] && !g[j])
                c[i]=j;
    }*/
    c['z']='q';
    c['q']='z';
    int T;
    scanf("%d",&T);
    gets(buf);
    while (T--)
    {
        gets(buf);
        n=strlen(buf);
        static int id=0;
        printf("Case #%d: ",++id);
        for (int i=0;i<n;i++)
            printf("%c",c[buf[i]]);
        printf("\n");
    }
    return(0);
}

