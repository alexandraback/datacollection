/*
 * =====================================================================================
 *
 *       Filename:  sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012/5/6 1:47:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <memory.h>

    int mark[2000009];
    int que[2000009];
int main()
{
    int n;
    int i,j;
    int t;
    int val[20];
    int cnt;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&val[j]);
        }
        memset(mark,-1,sizeof(int)*2000009);
        cnt = 0;
        que[cnt++]=0;
        int ans = -1;
        int k;
        for(j=0;j<n;j++)
        {
            int nu=cnt;
            for(k=0;k<nu;k++)
            {
                if(mark[que[k]+val[j]] == -1)
                {
                    mark[que[k]+val[j]] = que[k];
                    que[cnt++]=que[k]+val[j];
                }
                else
                {
                    ans = 1;
                    break;
                }
            }
            if(ans == 1)break;
        }
        printf("Case #%d:\n",i);
        if(ans == 1)
        {
            int p = mark[que[k]+val[j]];
            int pre = que[k]+val[j];
            while(pre!=0)
            {
                printf("%d ", pre - p);
                pre = p;
                p = mark[pre];
            }
            printf("\n");
            mark[que[k]+val[j]]=que[k];
            pre = que[k]+val[j];
            p = mark[pre];
            while(pre!=0)
            {
                printf("%d ", pre - p);
                pre = p;
                p = mark[pre];
            }
        }
        else
        {
            printf("Impossible");
        }
        printf("\n");
    }
    return 1;
}
