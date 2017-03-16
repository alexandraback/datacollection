#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int bff[5000]={0}, flag[5000]={0}, queue[1005][1005]={0};
int main()
{
        int t, cn;
        scanf("%d", &t);
        for(cn=1; cn<=t; cn++)
        {
                int n, i, j, max=0, len, k, last;
                scanf("%d", &n);
                for(i=1; i<=n; i++)
                        scanf("%d", &bff[i]);
                for(i=1; i<=n; i++)
                {
                        len=0;
                        for(j=1; j<=n; j++)
                                flag[j]=0;
                        j=i;
                        while(1)
                        {
                                queue[i][len++]=j;
                                flag[j]=1;
                                last=queue[i][len-1];
                                if(flag[bff[j]])
                                {
                                        if(bff[last]!=i && bff[last]!=queue[i][len-2])
                                                len=0;
                                        break;
                                }
                                j=bff[j];
                        }
                        if(bff[last]==queue[i][len-2])
                        {
                                for(k=1; k<=n; k++)
                                {
                                        if(bff[k]==j && flag[k]==0)
                                        {
                                                len++;
                                                break;
                                        }
                                }
                        }
                        if(max<len)
                                max=len;
                }
                printf("Case #%d: %d\n", cn, max);
        }
        return 0;
}
