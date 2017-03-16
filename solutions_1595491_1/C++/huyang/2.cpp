#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
   // freopen("B-large.in","r",stdin);
   // freopen("2.out","w",stdout);
    int te,i,j,k,n,s,p;
    scanf("%d",&te);
    for(int pp=1;pp<=te;pp++)
    {
        int ans=0;
        scanf("%d%d%d",&n,&s,&p);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&k);
            
            
            if(k==0){
                if(k>=p)ans++;
                continue;
            }
            if(k>=29){
                if(10>=p)ans++;
                continue;
            }

            if(k%3==0){
                k/=3;
                if(k>=p)ans++;
                else if(k==p-1&&s>0)
                {s--;ans++;}
            }else
            if(k%3==1){
                k/=3;k++;
                if(k>=p)ans++;
            }else
            {
                k/=3;k++;
                if(k>=p)ans++;
                else if(k==p-1&&s>0){
                    s--;ans++;}
            }
        }
        printf("Case #%d: %d\n",pp,ans);
    }
    return 0;
}
