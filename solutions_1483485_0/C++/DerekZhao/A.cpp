
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char map[30];
char in[3][100]={"ejp mysljylc kd kxveddknmc re jsicpdrysi","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","de kr kd eoya kw aej tysr re ujdr lkgc jv"};
char out[3][100]={"our language is impossible to understand","there are twenty six factorial possibilities","so it is okay if you want to just give up"};

int main()
{
    memset(map,0,sizeof(map));
    map['y'-'a']='a';
    map['e'-'a']='o';
    map['q'-'a']='z';
    map['z'-'a']='q';
    int len[3],i,j;
    for(i=0;i<3;i++)
    {
        len[i]=strlen(in[i]);
        for(j=0;j<len[i];j++)
        {
            if(in[i][j]>='a'&&in[i][j]<='z')map[in[i][j]-'a']=out[i][j];
        }
    }

    int tc,slen;
    char str[110];
    freopen("A-small-attempt2.in","r",stdin);
    freopen("A-small-attempt2.out","w",stdout);
    scanf("%d",&tc);
    scanf("%c",&str[0]);
    for(i=0;i<tc;i++)
    {
        gets(str);
        slen=strlen(str);
        printf("Case #%d: ",i+1);
        for(j=0;j<slen;j++)
        {
            if(str[j]>='a'&&str[j]<='z'&&map[str[j]-'a'])
            {
                putchar(map[str[j]-'a']);
            }
            else
            {
                putchar(str[j]);
            }
        }
        putchar('\n');
    }
    return 0;
}
