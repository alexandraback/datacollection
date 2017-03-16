#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("Aout.txt","w",stdout);
    int T;
    cin>>T;
    for(int cas=1; cas<=T; cas++)
    {
        int n,d;
        cin>>n;
        int cur=0,ex=0;
        for(int i=0; i<n+1; i++)
        {
            scanf("%1d",&d);
            if(cur<i)
            {
                ex+=i-cur;
                cur=i;
            }
            cur+=d;
        }
        printf("Case #%d: %d\n",cas,ex);
    }
    return 0;
}
