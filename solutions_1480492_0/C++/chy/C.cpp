#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <utility>
#include <sstream>
#include <algorithm>
using namespace std;
#define ll long long
const long long LINF = ~(((long long)0x1)<<63)/2;
const int INF=0X3F3F3F3F;
const double eps=1e-7;
int dir[100];
double v[100],s[100];
char r[100];
int main()
{
   freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    int T,i,j,k,cas,n;
    scanf("%d",&T);
    for(cas=1;cas<=T;cas++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s%lf%lf",r,&v[i],&s[i]);
            if(r[0]=='L')dir[i]=1;
        }
        double ans=0;
        bool flag=false;
        double pre=-1;
        while(true)
        {
            double value=INF*1.0;
            k=-1;
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    if(i!=j)
                    {
                        if(s[i]+5<=s[j]&&v[i]>v[j]&&dir[i]==dir[j])
                        {
                            double now=(s[j]-s[i]-5)/(v[i]-v[j]);
                            if(now<value)
                            {
                                k=i;
                                value=now;
                            }
                        }
                    }
            if(k==-1)
                break;
         //   cout<<value<<endl;
            ans+=value;
            dir[k]^=1;
            for(i=0;i<n;i++){
                s[i]=s[i]+v[i]*value;
              //  printf("%lf %d\n",s[i],dir[i]);
             //  cout<<s[i]<<" "<<dir[i]<<endl;
            }
           // cout<<k<<endl;
            for(i=0;i<n;i++)
                if(i!=k&&dir[k]==dir[i])
                {
                    if((s[i]>=s[k]&&s[i]<s[k]+5)||(s[k]<s[i]+5&&s[k]>=s[i]))
                        break;
                }
            if(i!=n||(pre==value&&value==0))
            {
                flag=true;
                break;
            }
            pre=value;
           // cin>>k;
           // cout<<endl;
        }
        printf("Case #%d: ",cas);
        if(flag)
            printf("%.5lf\n",ans);
        else
            printf("Possible\n");
    }
    return 0;
}
/*
6
R 741 3929

R 999 10000

R 897 3912

L 951 6226

L 999 10000
R 1000 0
*/
