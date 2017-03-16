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
        ll zac=0; ll skok=1;
        while(skok!=0) {
            ll stred=zac+skok;
            if(stred*(2*r+2*stred-1)<=t) {zac+=skok; skok*=2;}
            else skok/=2;
        }
        printf("Case #%d: %lld\n",i1+1,zac);
    }
return 0;
}
