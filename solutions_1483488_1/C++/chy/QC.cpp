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
int p[10];
int ok[2111111];
int main()
{
    int T,i,j,k,a,b,cas=1,c;
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    cin>>T;
    p[0]=1;
    for(i=1;i<=8;i++) p[i]=p[i-1]*10;
    for(cas=1;cas<=T;cas++)
    {
        int ans=0;
        memset(ok,0,sizeof(ok));
        cin>>a>>b;
        for(c=a;c<=b;c++)
        {
            vector<int> now;
            int d=c;
            while(d)
            {
                now.push_back(d%10);
                d/=10;
            }
            reverse(now.begin(),now.end());
            for(i=0;i<=now.size();i++)
            {
                int value=c%p[i]*p[now.size()-i]+c/p[i];
                if(value>c&&value>=a&&value<=b&&ok[value]!=c)
                    ans++,ok[value]=c;
            }
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
