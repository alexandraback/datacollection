#include<stdio.h>
#include<stdlib.h>
int mul(int a,int b)
{
    int sign = (a*b)>0?1:-1;
    a = abs(a);
    b = abs(b);
    if(a==1) return sign*b;
    if(b==1) return sign*a;


    int ret[][4]= {
        { 1, 2, 3, 4 },
        { 2,-1, 4,-3 },
        { 3,-4,-1, 2 },
        { 4, 3,-2,-1 }
    };

    return sign*ret[a-1][b-1];


}

int pow(int x,int n)
{
    if(n==1) return x;
    if(x==1) return 1;
    if(x==-1) return (n%2)?1:-1;
    if(n%2==0)
    {
        int tm = pow(x,n/2);
        return mul(tm,tm);
    }
    return mul(pow(x,n-1),x);
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t = 0; t<T; t++)
    {
        int L,X;
        scanf("%d%d",&L,&X);

        int ans = 1;
        char CH;
     //   scanf("%c",&CH);

        char str[10003];
        scanf("%s",str);

        int state = 0;//0 nothing, 1 i found, 2 j found
        for(int x = 0;x<X;x++)
        for(int i=0;i<L;i++)
        {
            char ch=str[i];
           // scanf("%c",&ch);
            //printf("%c",ch);
            int tm = (ch=='1')?1:(ch-'i'+2);
           // printf("   =  %d\n",tm);
            ans = mul(ans,tm);
            if(state == 0 && ans == 2)
            {
                state = 1;
                ans = 1;
            }
            else if(state == 1 && ans == 3)
            {
                state = 2;
                ans = 1;
            }
        }
       // printf("%d\n",ans);
        bool possible = pow(ans,X)==-1?true:false;

        if(state == 2 && ans==4)
            printf("Case #%d: YES\n",t+1);
        else
            printf("Case #%d: NO\n",t+1);
    }
    return 0;
}
