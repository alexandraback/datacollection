#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;
typedef pair<int,int> pi;
set<pi> st;
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        st.clear();
        int a,b;
        scanf("%d%d",&a,&b);
        for(int i=a;i<=b;i++)
        {
            int s[20],t=i;
            int len=0;
            while(t)
            {
                s[len++]=t%10;
                t/=10;
            }
            int bs=1;
            for(int j=1;j<len;j++) bs*=10;
            t=i;
            for(int j=0;j<len-1;j++)
            {
                t=t/10+bs*s[j];
                if(t>=a&&t<=b&&t>i)
                    if(st.find(pi(i,t))==st.end()) st.insert(pi(i,t));
            }
        }
        printf("Case #%d: %d\n",++cas,st.size());
    }
    return 0;
}
