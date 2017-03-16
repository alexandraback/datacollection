#include<stdio.h>

int t,n,u[1005],min1,min2,co,star,ch;
struct node
{
    int a,b;
}st[1005];
struct node1
{
    int val,s,num;
}min;

int main()
{
    int i,j,k;
    freopen("1.in","r",stdin);
    freopen("1.txt","w",stdout);
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%d",&n);
        star=0;
        for(i=0;i<n;i++)
        {
            u[i]=0;
            scanf("%d%d",&st[i].a,&st[i].b);
        }
        for(co=0;;co++)
        {
            min.val=4000;
            min.s=0;
            min.num=-1;
            ch=0;
            for(i=0;i<n;i++)
            {
                if(u[i]<2 && st[i].b<=star)
                {
                    ch=1;
                    min.num=i;
                    min.s=2;
                    break;
                }else if(u[i]<1 && st[i].a<=star){
                    if(min.num==-1)
                    {
                        min.num=i;
                        min.s=1;
                        ch=1;
                    }else if(st[i].b>st[min.num].b){
                        min.num=i;
                        min.s=1;
                        ch=1;
                    }
                }
            }
            if(ch==0)break;
            star+=min.s-u[min.num];
            u[min.num]=min.s;
//            printf("[%d=%d %d]\n",co,star,min.num+1);
        }
        if(star==n*2)printf("Case #%d: %d\n",k,co);
        else printf("Case #%d: Too Bad\n",k);
    }
    
    scanf(" ");
    return 0;
}
