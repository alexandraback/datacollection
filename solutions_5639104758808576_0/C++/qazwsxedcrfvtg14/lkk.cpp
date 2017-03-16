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
char s[10000];
int main(){
    int t,T=0;
    scanf("%d",&t);
    while(t--){T++;
        int n;
        scanf("%d%s",&n,s);
        int ans=0;
        int sig=0;
        for(int i=0;i<=n;i++)
            ans+=max(0,i-sig),sig=max(sig,i),sig+=s[i]-'0';
        printf("Case #%d: %d\n",T,ans);
        }
    return 0;
    }

