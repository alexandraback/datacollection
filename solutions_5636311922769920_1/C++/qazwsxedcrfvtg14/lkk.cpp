#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/hash_policy.hpp>
//#include<ext/pb_ds/priority_queue.hpp>
//#include<ext/rope>
#pragma GCC optimize ("O3")
#define f first
#define s second
//#define mkptr make_shared<nod>
//#define mkptr new nod
//#pragma GCC diagnostic error "-std=c++11"
//-wl,--stack=2147483647
//int main() __attribute__((optimize("-O3")));
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
int main(){
    int T,t=0;
    scanf("%d",&T);
    while(T--){t++;
        int k,c,s;
        scanf("%d%d%d",&k,&c,&s);
        printf("Case #%d:",t);
        int n=(k+c-1)/c;
        if(n>s)puts(" IMPOSSIBLE");
        else{
            vector<long long int>ve;
            for(int i=0;i<n;i++)
                ve.push_back(i*c);
            for(int i=0;i<c-1;i++){
                for(int j=0;j<n;j++){
                    ve[j]=ve[j]*k+min((i+j*c+1),k-1);
                    }
                }
            for(long long int x:ve)
                printf(" %lld",x+1);
            puts("");
            }
        }
    }
