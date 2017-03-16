#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int T,t,r,j;
    scanf("%d",&T);
    for(j=1;j<=T;j++)
    {
        scanf("%d%d",&r,&t);
        int i = 2*r+1,ans = 0,sum=0;
        while(1)
        {
            sum+=i;
            if(sum <= t)
            ans++;
            else
            break;
            i += 4;
        }
        printf("Case #%d: %d\n",j,ans);
    }
}
