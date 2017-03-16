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
int a[1200],b[1200];
int main()
{
   freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T,cas,i,j,k,n;
    scanf("%d",&T);
    for(cas=1;cas<=T;cas++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d",&a[i],&b[i]);
        int value=0;
        int now=0;
        bool flag=true;
        while(flag)
        {
            flag=false;
            for(i=0;i<n;i++)
                if(b[i]!=-1&&value>=b[i])
                {
                    flag=true;
                    now++;
                    if(a[i]==-1)
                        value+=1;
                    else
                        value+=2;
                    b[i]=-1;a[i]=-1;
                    break;
                }
            if(flag) continue;
            int pa=-1,pb=-1;
            for(i=0;i<n;i++)
                if(a[i]!=-1&&value>=a[i])
                {
                    if(b[i]>pb)
                    {
                        pa=i;
                        pb=b[i];
                    }
                }
            if(pa!=-1)
            {
                flag=true;
                now++;
                value++;
                a[pa]=-1;
            }
           // cout<<value<<" "<<i<<endl;
        }
        printf("Case #%d: ",cas);
        for(i=0;i<n;i++)
            if(b[i]!=-1){
                printf("Too Bad\n");
                break;
            }
        if(i==n)
            printf("%d\n",now);
    }
    return 0;
}
