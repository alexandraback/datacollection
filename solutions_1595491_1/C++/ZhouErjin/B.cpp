#include<cstdio>

int n,s,p;
int sum;
int t,id;

int main()
{
    for (scanf("%d",&t);t--;)
    {
        scanf("%d%d%d",&n,&s,&p);
        int res=0;
        for (;n--;)
        {
            scanf("%d",&sum);
            int w=sum/3;
            sum%=3;
            if (w+(sum>0)>=p) res++;
            else
            if (s)
            {
                int now=w+(sum>0);
                if (sum==0)
                {
                    if (w && w+1>=p) res++,s--;
                } else
                if (sum==2)
                if (now+1>=p) res++,s--;
            }
        }
        printf("Case #%d: %d\n",++id,res);
    }
}

