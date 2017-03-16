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
#pragma GCC diagnostic error "-m64"
//-wl,--stack=2147483647
//int main() __attribute__((optimize("-O3")));
using namespace std;
typedef pair<int,int> par;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
//int ar[26005];
int mp[30];
int ar[100][100];
unsigned long long int cnt[100];
int main(){
    int t,T=0;
    scanf("%d",&t);
    while(t--){T++;
        int n;
        unsigned long long int m,mx;
        scanf("%d%llu",&n,&m);
        mx=1LLU<<max(0,n-2);
        printf("Case #%d: ",T);
        if(m>mx){puts("IMPOSSIBLE");continue;}
        puts("POSSIBLE");
        memset(ar,0,sizeof(ar));
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                ar[i][j]=1;
        int bs=1;
        while(m<=mx/2){
            mx/=2;
            ar[0][bs++]=0;
            }
        int x=mx-m;
        while(x){
            if(x&1)ar[bs][n-1]=0;
            x>>=1;bs++;
            }
        for(int i=0;i<n;i++,puts(""))
            for(int j=0;j<n;j++)
                printf("%d",ar[i][j]);
        memset(cnt,0,sizeof(cnt));
        cnt[0]=1;
        for(int i=0;i<n;i++){
            printf("%llu\n",cnt[i]);
            for(int j=0;j<n;j++)
                if(ar[i][j])cnt[j]+=cnt[i];
            }
        if(cnt[n-1]!=m)puts("DUCK!");
        }
    return 0;
    }
