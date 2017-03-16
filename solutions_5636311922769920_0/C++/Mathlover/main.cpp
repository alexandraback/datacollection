#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
    freopen("D-small-attempt1.in","r",stdin);
    freopen("3.out","w",stdout);
    int t;
    int ca=0;
    scanf("%d",&t);
    while(t--)
    {
        int k,c,s,p=0;
        scanf("%d%d%d",&k,&c,&s);
        printf("Case #%d: ",++ca);
        if(c*s<k)
        {
            puts("IMPOSSIBLE");
            continue;
        }
        vector<long long>vec;
        for(p=0;p<k;)
        {
            long long ans=0;
            for(int i=0;i<c;++i)
            {
                ans=ans*k+p;
                p++;
                if(p>=k)
                    break;
            }
            vec.push_back(ans);
        }
        for(int i=0;i<vec.size();++i)
        {
            printf("%I64d%c",vec[i]+1," \n"[i==vec.size()-1]);
        }

    }
}
