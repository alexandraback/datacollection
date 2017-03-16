#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>

using namespace std;



typedef long long int ll;

int T;
ll r,p;

int main(void){

    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);


    scanf("%d",&T);

    for(int caso=1;caso<=T;caso++){

        scanf("%I64d %I64d",&r,&p);

        ll n=((1.0-2*r)+sqrt(1.0*(2*r-1)*(2*r-1)+8*p))/4;
        ll n2=((1.0-2*r)-sqrt(1.0*(2*r-1)*(2*r-1)+8*p))/4;
        n=max(n,n2);
        n=max(n,(ll)0);

        printf("Case #%d: %I64d\n",caso,n);
    }

    return 0;
}
