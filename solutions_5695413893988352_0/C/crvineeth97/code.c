#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
char c[1000], j[1000];
int main()
{
        int t, cn;
        scanf("%d", &t);
        for(cn=1; cn<=t; cn++)
        {
                int i, flag=2;
                scanf("%s", c);
                scanf("%s", j);
                int len = strlen(j);
                if(c[0]=='?' && j[0]=='?')
                        c[0]=j[0]='0';
                else if(c[0]=='?')
                        c[0]=j[0];
                else if(j[0]=='?')
                        j[0]=c[0];
                if(c[0]>j[0])
                        flag=0;
                else if (c[0]<j[0])
                        flag=1;
                for(i=1; i<len; i++)
                {
                        if(c[i]=='?' && j[i]=='?')
                        {
                                if(flag==2)
                                        c[i]=j[i]='0';
                                if(flag==1)
                                {
                                        c[i]='9';
                                        j[i]='0';
                                }
                                if(flag==0)
                                {
                                        c[i]='0';
                                        j[i]='9';
                                }
                                continue;
                        }
                        else if(c[i]=='?')
                        {
                                if(flag==2)
                                        c[i]=j[i];
                                if(flag==1)
                                        c[i]='9';
                                if(flag==0)
                                        c[i]='0';
                                continue;
                        }
                        else if(j[i]=='?')
                        {
                                if(flag==2)
                                        j[i]=c[i];
                                if(flag==1)
                                        j[i]='0';
                                if(flag==0)
                                        j[i]='9';
                        }
                        if(c[i]>j[i] && flag==2)
                                flag=0;
                        else if (c[i]<j[i] && flag==2)
                                flag=1;
                }
                printf("Case #%d:", cn);
                printf(" %s %s\n", c, j);
        }
        return 0;
}
