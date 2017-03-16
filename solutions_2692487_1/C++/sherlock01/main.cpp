#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<algorithm>

#define LL long long

using namespace std;

const int INF=0x3f3f3f3f;
const int N=1000005;
LL a[N];
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int T;
    cin>>T;
    for(int w=1;w<=T;++w)
    {
        LL A;
        int n;
        cin>>A>>n;
        for(int i=0;i<n;++i)
        cin>>a[i];
        sort(a,a+n);
        int ans=n;
        int sum=0;
        for(int i=0;i<n;++i)
        {
            ans=min(ans,sum+(n-i));
            if(A==1){sum=INF;break;}
            while(A<=a[i])
            {
                A=A+A-1;
                ++sum;
            }
            A+=a[i];
        }
        ans=min(ans,sum);
        printf("Case #%d: %d\n",w,ans);
    }
    return 0;
}
