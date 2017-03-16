#include <stdio.h>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    int t;
    scanf("%d",&t);
    for(int tw = 1; tw <= t; tw++){
        int k,c,s;
        scanf("%d%d%d",&k,&c,&s);
        vector<ll> v;
        ll use = 0;
        while(1){
            if(use >= k){
                break;
            }
            ll now = 0;
            ll ww = 1;
            for(int j = 0; j < c; j++){
                if(use >= k){
                    break;
                }
                now += use * ww;
                ww *= (ll)k;
                use++;
            }
            v.push_back(now);
        }
        printf("Case #%d:",tw);
        if(v.size() > s){
            printf(" IMPOSSIBLE\n");
        }
        else{
            for(int i = 0; i < v.size(); i++){
                printf(" %lld",v[i] + 1);
            }
            printf("\n");
        }
    }
}
