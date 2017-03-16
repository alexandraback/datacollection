#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define For(i,n) for(int i=0; i<(n); i++)
#define mp(a,b) make_pair((a),(b))
typedef long long ll;

int main() {
    int t1;
    scanf("%d ",&t1);
    For(i1,t1) {
        ll r,t;
        scanf("%lld %lld ",&r,&t);
        ll zac=0,kon=2000000ll;
        while(kon-zac>1) {
            ll stred=(zac+kon)/2;
            if(stred*(2*r+2*stred-1)<=t) zac=stred;
            else kon=stred;
        }
        printf("Case #%d: %lld\n",i1+1,zac);
    }
return 0;
}
