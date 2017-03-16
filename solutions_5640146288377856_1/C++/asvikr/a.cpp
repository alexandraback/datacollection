#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        printf("Case #%d: ",t);
        cerr<<"done "<<t<<endl;
        int r,c,w;
        scanf("%d %d %d",&r,&c,&w);
        if(r==1){
            if(c==1)
                printf("1\n");
            else
            {
               int ans=(c/w)+(w-1);
               if(c%w!=0 && c!=w)
                 ans+=1;
               printf("%d\n",ans);
            }
        }
        else
        {
            int ans=(c/w)+(w-1);
               if(c%w!=0 && c!=w)
                 ans+=1;
            ans=ans*r;
            printf("%d\n",ans);
        }
    }
    return 0;
}




