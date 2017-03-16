#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<ext/rope>
#pragma GCC optimize ("O3")
#define f first
#define s second
//#define mkptr make_shared<nod>
//#define mkptr new nod
//#pragma GCC diagnostic push
#pragma GCC diagnostic error "-std=c++11"
//-wl,--stack=2147483647
//int main() __attribute__((optimize("-O3")));
using namespace std;
//using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef pair<int,int> par;
typedef pair<par,int> pr;
int ar[1000];
int main(){
    int t,T=0;
    scanf("%d",&t);
    while(t--){T++;
        int n;
        scanf("%d",&n);
        int ma=0;
        for(int i=0;i<n;i++)
            scanf("%d",&ar[i]),ma=max(ar[i],ma);
        int ans=0x7fffffff;
        for(int i=1;i<=ma;i++){
            int cnt=0;
            for(int j=0;j<n;j++)
                cnt+=(ar[j]-1)/i;
            ans=min(ans,cnt+i);
            }
        printf("Case #%d: %d\n",T,ans);
        }
    return 0;
    }

