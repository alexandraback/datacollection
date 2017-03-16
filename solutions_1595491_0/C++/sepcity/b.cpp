#include<iostream>
using namespace std;
int sum[110],cases,n,s,p;
int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    scanf("%d",&cases);
    for(int ca=1;ca<=cases;ca++)
    {
        scanf("%d%d%d",&n,&s,&p);
        int res=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&sum[i]);
            int mx=(sum[i]+2)/3;
            if(mx>=p) res++;
            else if(sum[i]%3 !=1 && mx==p-1 && s)
            {
                bool ok=true;
                if(sum[i]%3==0 && mx-1 <0) ok=false;
                if(ok)
                {
                    res++;
                    s--;
                }
            }
        }
        printf("Case #%d: %d\n",ca,res);
    }
}
