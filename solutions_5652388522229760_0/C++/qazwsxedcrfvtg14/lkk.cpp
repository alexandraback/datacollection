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
char s[100];
int run(long long int x){
    int ret=0;
    sprintf(s,"%lld",x);
    for(int i=0;s[i];i++)
        ret|=1<<(s[i]-'0');
    return ret;
    }
int main(){
    int t=0,T;
    scanf("%d",&T);
    while(T--){t++;
        long long int x;
        scanf("%lld",&x);
        printf("Case #%d: ",t);
        if(!x)printf("INSOMNIA\n");
        else{
            int ok=0;
            for(int i=1;i<1000;i++){
                ok|=run(x*i);
                if(ok==1023){
                    printf("%lld\n",x*i);
                    break;
                    }
                }
            }
        }
    }
