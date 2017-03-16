#include<cstdio>
#include<cstring>
#define N 1000
using namespace std;

char str[N];
char pat[6][N]={"ejp mysljylc kd kxveddknmc re jsicpdrysi",
                              "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                              "de kr kd eoya kw aej tysr re ujdr lkgc jv",
                              "our language is impossible to understand",
                              "there are twenty six factorial possibilities",
                              "so it is okay if you want to just give up"};

char map[N];

main()
{
    int i,j,k,n,m,t,ys,flag;

    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);

    for (i=0;i<26;i++)
    {
        flag=0;
        for (j=0;j<3;j++)
        {
            m=strlen(pat[j]);

            for (k=0;k<m;k++)
                if (pat[j][k]-'a'==i)
                {
                    flag=1;
                    break;
                }

             if (flag)
                break;
        }

        map[i]=pat[j+3][k];
    }

    map['z'-'a']='q';
    map['q'-'a']='z';
    scanf("%d\n",&t);
    ys=0;
    while (t--)
    {
        gets(str);
        m=strlen(str);

        printf("Case #%d: ",++ys);

        for (i=0;i<m;i++)
            if (str[i]!=' ')
                printf("%c",map[str[i]-'a']);
            else
                printf(" ");

        printf("\n");
    }

    return 0;
}



