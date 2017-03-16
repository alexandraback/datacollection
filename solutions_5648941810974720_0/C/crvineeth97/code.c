#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
char st[1000006];
int a[26]={0}, num[10]={0};
int main()
{
        int t, cn;
        scanf("%d", &t);
        for(cn=1; cn<=t; cn++)
        {
                int i, j;
                for(i=0;i<26;i++)
                        a[i]=0;
                for(i=0;i<10;i++)
                        num[i]=0;
                scanf("%s", st);
                int len = strlen(st);
                for(i=0;i<len;i++)
                        a[st[i]-'A']++;
                num[0]=a['Z'-'A'];
                num[2]=a['W'-'A'];
                num[4]=a['U'-'A'];
                a['O'-'A']-=(num[0]+num[2]+num[4]);
                num[1]=a['O'-'A'];
                num[6]=a['X'-'A'];
                a['S'-'A']-=num[6];
                num[7]=a['S'-'A'];
                a['V'-'A']-=num[7];
                num[5]=a['V'-'A'];
                num[8]=a['G'-'A'];
                a['I'-'A']-=(num[5]+num[6]+num[8]);
                num[9]=a['I'-'A'];
                a['H'-'A']-=(num[8]);
                num[3]=a['H'-'A'];
                printf("Case #%d: ", cn);
                for(i=0;i<10;i++)
                        for(j=0;j<num[i];j++)
                                printf("%d", i);
                printf("\n");
        }
        return 0;
}
