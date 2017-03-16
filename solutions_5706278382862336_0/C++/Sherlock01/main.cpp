#include<iostream>
#include<stack>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

typedef long long ll;
typedef pair<int,int> pp;
const double eps=1e-6;
const int INF=0x3f3f3f3f;
const int N=103;

int main()
{
    //freopen("data.txt","r",stdin);
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T;
    cin>>T;
    for(int ca=1;ca<=T;++ca)
    {
        printf("Case #%d: ",ca);
        ll A,B;
        char c;
        cin>>A>>c>>B;
        ll tmp=__gcd(A,B);
        A=A/tmp;
        B=B/tmp;
        ll K=((ll)(1)<<40);
        if(K%B)
        {
            printf("impossible\n");
        }else
        {
            A=K/B*A;
            int ans=40;
            while(A>(ll(1)))
            {
                A=A/2;
                ans--;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
