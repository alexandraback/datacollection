#include <iostream>
#include <cstdio>
using namespace std;
void solve(long long p,long long q)
{
    int i,j,k;
    k = 0;
    while (q){
        if(q & 1 != 0){
            break;
        }
        q = q /2;
        k++;
    }
    j = 0;
    if (p % q != 0) {printf("impossible\n");return;}
    p = p / q;
    while ( p){
        p = p /2;
        j++;
    }
    printf("%d\n",k+1-j);
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int i = 1; i <= t; i++){
        printf("Case #%d: ",i);
        long long p,q;
        scanf("%lld/%lld",&p,&q);
        solve(p,q);

    }
    return 0;
}

