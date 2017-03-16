#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long ll;
bool used[10];
int used_co=0;

bool check(ll a){
    while(a>0){
        if(used[a%10] == false){
            used[a%10] = true;
            used_co++;
        }
        if(used_co==10) return true;
        a/=10;
    }
    if(used_co==10) return true;
    return false;
}


int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-output.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int co=1;co<=t;co++){
        memset(used,false,sizeof(used));
        used_co=0;
        ll n;
        scanf("%lld",&n);
        if(n!=0){
            for(ll h=1;true;h++){
                if(check(n*h)){
                    printf("Case #%d: %lld\n",co,n*h);
                    break;
                }
            }
        }
        else printf("Case #%d: INSOMNIA\n",co);

    }
}
