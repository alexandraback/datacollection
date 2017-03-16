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
typedef pair<par,int> pr;
vector<pr>ve;
int used[10][10];
int gg[10][10][10];
int main(){
    int t,T=0;
    scanf("%d",&t);
    while(t--){T++;
        int a,b,c,k;
        scanf("%d%d%d%d",&a,&b,&c,&k);
        //a=min(a,k);
        ve.clear();
        int z=0;
        memset(used,0,sizeof(used));
        memset(gg,0,sizeof(gg));
        bool duck=0;
        for(int x=0;x<a;x++){
            for(int y=0;y<b;y++){
                for(int i=0;i<min(k,c);i++){
                    if(gg[x][y][z]||used[y][z]==k){
                        //duck=1;
                        for(int j=0;j<c;j++){
                            z=(z+1)%c;
                            if(!gg[x][y][z]&&used[y][z]<k)goto flag;
                            }
                        continue;
                        flag:;
                        }
                    used[y][z]++;
                    ve.push_back(pr(par(x,y),z));
                    gg[x][y][z]=1;
                    z=(z+1)%c;
                    }
                }
            if(__gcd(b,c)!=1)
                z=(z+1)%c;
            }
        printf("Case #%d: %d\n",T,ve.size());
        for(auto &i:ve)
            printf("%d %d %d\n",i.f.f+1,i.f.s+1,i.s+1);
        if(duck)puts("duck");
        }
    return 0;
    }
