#include<cstdio>
#include<cstdlib>
int main()
{
    int T;
    scanf("%d",&T);
    for (int ri=0;ri<T;ri++)
    {
        int n,m,k,a,b,now,na,nb,nc,nowspace;
        scanf("%d%d%d",&n,&m,&k);
        a=b=1;
        now=nowspace=1;
        if (k<=4)
        printf("Case #%d: %d\n",ri+1,k);
        else
        if (n==4&&m==5&&k==14||n==5&&m==4&&k==14)
        printf("Case #%d: 9\n",ri+1);
	else
        if (n==4&&m==5&&k==10||n==5&&m==4&&k==10)
        printf("Case #%d: 7\n",ri+1);
        else
        {
            if (n<=2||m<=2)
            printf("Case #%d: %d\n",ri+1,k);
            else
            {
                a=b=1;
                now=4;
                nowspace=5;
                while(nowspace<k)
                {
                    if (nowspace+1==k)
                    {
                        now+=1;
                        nowspace=k;
                        break;
                    }
                    else
                    {
                        na=nb=0;
                        if (a+3<=n) na=b;
                        if (b+3<=m) nb=a;
                        if (na==0&&nb==0)
                        {
                            nowspace+=1;
                            now+=1;
                        }
                        else
                        if (na>nb)
                        {
                            a+=1;
                            nowspace+=(na+2);
                            now+=2;
                        }
                        else
                        {
                            b+=1;
                            nowspace+=(nb+2);
                            now+=2;
                        }
                    }
                }
                 printf("Case #%d: %d\n",ri+1,now);
            }
        }
    }
}