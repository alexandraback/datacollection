#include<cstdio>

int t,a,b;
int id;
int hash[10000000];

int main()
{
    int ii=1;
    for (scanf("%d",&t);t--;)
    {
        scanf("%d%d",&a,&b);
        int res=0;
        

        for (int i=a;i<=b;i++,ii++)
        {
            int digit[20],cnt=0;
            for (int j=i;j;j/=10) digit[++cnt]=j%10;
            for (int j=1;j<=cnt;j++) digit[j+cnt]=digit[j];
            for (int j=cnt*2;j>cnt;j--)
            if (digit[j])
            {
                int sum=0;
                for (int k=0;k<cnt;k++) sum=sum*10+digit[j-k];
                if (sum>=a && sum<=b && i<sum && hash[sum]!=ii)
                    res++,hash[sum]=ii;
            }
        }
        printf("Case #%d: %d\n",++id,res);
    }
}

