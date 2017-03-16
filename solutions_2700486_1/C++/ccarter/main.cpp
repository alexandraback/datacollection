#include <iostream>

using namespace std;
double calc(int n,int k)
{
    double mul=1;
    int cnt=n;
    k=n-k;
    for (int i=1;i<=k;i++)
    {
        mul*=(n-k+i);
        mul/=(k-i+1);
        while (mul>1 && cnt>0) {mul/=2;cnt--;}
    }
    while(cnt>0) {mul/=2;cnt--;}
    return mul;
}
int main()
{
    int tt,ri=1;
    scanf("%d",&tt);
    while (tt--)
    {
        int n,x,y;
        double p=1;
        scanf("%d %d %d",&n,&x,&y);
        printf("Case #%d: ",ri++);
        if (x<0) x*=-1;
        int st=1,c=0;
        while(n>st)
        {
            n-=st;
            st+=4;
            c++;
        }
        if (x+y<=(c-1)*2) p=1;
        else if (x+y>=(c+1)*2) p=0;
        else{
            int k;
            k=y+1;
            if (k==2*c+1) {
                if (n==st) p=1;
                else p=0;
            }
            else {
                p=0;
                for (int i=k;i<=n;i++)
                    p+=calc(n,i);
                if (n-2*c>=k) p=1;

            }
        }
        printf("%.7lf\n",p);
    }
    return 0;
}
