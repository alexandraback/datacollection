#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>


using namespace std;

const int INF=0x3f3f3f3f;

const int N=200;
const int prime=1000000007;
vector<string>a;
int c[N];
int main()
{
    //freopen("data.txt","r",stdin);
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T;
    cin>>T;
    for(int ca=1; ca<=T; ++ca)
    {
        printf("Case #%d: ",ca);
        int A,B,K;
        cin>>A>>B>>K;
        int ans=0;
        for(int i=0;i<A;++i)
        {
            for(int j=0;j<B;++j)
            {
                if((i&j)<K)
                ++ans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
