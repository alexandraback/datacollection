#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int re[2000010][7];

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int now[10],move[10];
    int tc,ti,a,b,i,tmp,j,k,l,m;
    for(i=1; i<=2000000; i++)
    {
        re[i][0]=0;
        tmp=i;
        j=0;
        while(tmp)
        {
            now[j++]=tmp%10;
            tmp/=10;
        }
        for(k=1;k<j;k++)
        {
            for(l=k,m=0;l<j;l++,m++)
            {
                move[m]=now[l];
            }
            for(l=0;l<k;l++,m++)
            {
                move[m]=now[l];
            }
            for(l=j-1,m=1;l>=0;l--)
            {
                if(move[l]>now[l])break;
                if(move[l]<now[l])
                {
                    m=0;break;
                }
            }
            if(l>=0&&m)
            {
                tmp=1;
                for(l=1;l<j;l++)
                {
                    tmp=tmp*10;
                }
                int tmp2=0;
                for(l=j-1;l>=0;l--)
                {
                    tmp2+=tmp*move[l];
                    tmp/=10;
                }
                for(l=1;l<=re[i][0];l++)
                {
                    if(tmp2==re[i][l])
                    break;
                }
                if(l>re[i][0])re[i][++re[i][0]]=tmp2;
            }
        }
        if(re[i][0])qsort(re[i]+1,re[i][0],sizeof(re[i][0]),cmp);
    }

    int ans;
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    scanf("%d",&tc);
    for(ti=0; ti<tc; ti++)
    {
        ans=0;
        scanf("%d%d",&a,&b);
        for(i=a;i<=b;i++)
        {
            j=re[i][0];
            while(j>0&&re[i][j]>b)j--;
            ans+=j;
        }
        printf("Case #%d: %d\n",ti+1,ans);
    }
    return 0;
}
