#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef unsigned long long uint;

unsigned int test=0;
const uint one = 1ULL<<31;

ll trans(uint t,int base){
    ll ans=0;
    int co=0;
    while(co<32){
        ans*=base;
        ans+=((t&one)>>31);
        co++;
        t = t<<1;
    }
    return ans;
}

ll finding(ll t){
    ll sqrt_of_t = sqrt(t);
    for(ll g=2;g<sqrt_of_t+1 && g<t;g++){
        if(t%g==0) return g;
    }
    return -1;
}

void print(uint t,int n){
    uint r = 1ULL<<(n-1);
    while(r!=0){
        printf("%d",(t&r)?1:0);
        r = r>>1;
    }
    return;
}


int main(){
    freopen("C-large.txt","w",stdout);
    int t,n,j;
    scanf("%d",&t);
    scanf("%d %d",&n,&j);
    printf("Case #1:\n");
    bool large=false;
    if(n==32){ n=16; large=true;}
    test = (1ULL<<(n-1)) | 1ULL;
    int co = 0;
    while(co<j){
        //print(test,n);
        //printf("\n");
        //system("pause");
        ll ans[10];
        bool flag = true;
        for(int base = 2;base<=10;base++){
            ll temp = finding(trans(test,base));
            //printf("%lld\n",trans(test,base));
            //printf("%lld\n",temp);
            if(temp == -1){
                flag = false;
                break;
            }
            ans[base-2] = temp;
        }
        if(flag){
            print(test,n);
            if(large) print(test,n);
            for(int g=0;g<9;g++) printf(" %lld",ans[g]);
            printf("\n");
            co++;
        }
        test+=2;
    }

}
