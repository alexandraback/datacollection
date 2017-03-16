#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define MA 100001
using namespace std;
#define inf 1<<29
double dp[MA];//错误开始再某个位置的可能
double pos[MA];
double ac[MA];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int a,b;
    int cn;
    int num=0;
    scanf("%d",&cn);
    while(cn--)
    {
        scanf("%d%d",&a,&b);
        for(int i=1;i<=a;++i)
          scanf("%lf",&pos[i]);
        ac[0]=1;
        for(int i=1;i<=a;++i){
           ac[i]=ac[i-1]*pos[i];
          // cout <<ac[i]<<endl;
        }
        for(int i=1;i<=a;++i)
        {
            dp[i]=ac[i-1]*(1-pos[i]);
         //   cout << dp[i]<<endl;
        }
        dp[a+1]=ac[a];
      //  cout << ac[a]<<endl;
        double ans=inf;
        double t;
        for(int i=0;i<=a;++i)//tui多少3
        {
            t=0;
            for(int j=1;j<=a+1;++j)//zai nali cuo
            {
             //   double tt=0;
            //    cout << a-i <<" "<<j<<endl;
                if(a-i>=j)
                   t+=dp[j]*(i+b+i+1+b+1);
                else
                   t+=dp[j]*(i+b+i+1);
            }
            if(t-a<ans)
               ans=t-a;
        }
     //   cout << ans<<endl;
        t=a+1+b+1-a;
        if(t<ans)
          ans=t;
        printf("Case #%d: %.6lf\n",++num,ans);

    }
    return 0;
}





