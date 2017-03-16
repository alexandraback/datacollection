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
using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef pair<int,int> par;
typedef pair<par,int> pr;
int main(){
    int t,T=0;
    scanf("%d",&t);
    while(t--){T++;
        int x,r,c;
        scanf("%d%d%d",&x,&r,&c);
        if(r>c)swap(r,c);
        if(x>=7)
            printf("Case #%d: RICHARD\n",T);
        else if((r*c)%x)
            printf("Case #%d: RICHARD\n",T);
        else if(x==1||x==2)
            printf("Case #%d: GABRIEL\n",T);
        else if(x==3&&r==1)
            printf("Case #%d: RICHARD\n",T);
        else if((x==4||x==5)&&r<=2)
            printf("Case #%d: RICHARD\n",T);
        else if(x==5&&r==3&&c==5)
            printf("Case #%d: RICHARD\n",T);
        else if(x==6&&r<=3)
            printf("Case #%d: RICHARD\n",T);
        else
            printf("Case #%d: GABRIEL\n",T);
        }
    return 0;
    }

