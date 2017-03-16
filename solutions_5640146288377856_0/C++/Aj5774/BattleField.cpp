#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <string.h>

#include <bits/stdc++.h>        //include every c++ library
                                //fgets(array_name,array_size,stdin);
                                //FLT_MAX FLT_MIN INT_MAX INT_MIN DBL_MAX DBL_MIN
#define mod 1000000007
#define ll long long int
using namespace std;

struct point
{
     ll X;
     ll Y;
};

bool operator<(point const& n1, point const& n2)
{
    return n1.X<n2.X || (n1.X==n2.X && n1.Y<n2.Y);
}

void check(ll A[], ll N)
{
    ll i;
    for(i=0; i<N; i++)
        printf("%lld ",A[i]);
    printf("\n");
}


int main()
{
    ll T,z;
    freopen("A-small-attempt1.in","r",stdin);
    freopen("outsmall","w",stdout);

    scanf("%lld",&T);
    for(z=1; z<=T; z++)
    {
        ll R,C,W, i, j, ans = 0;
        scanf("%lld%lld%lld",&R,&C,&W);
        while(C>W){
            C = C - W;
            ans = ans+ R;
        }
        if( C == W){
            ans = ans + R + W - 1;
        }
        else if( C == 1){
            ans = ans + W ;
        }
        else{
            ans = ans + W ;
        }
        printf("Case #%lld: %lld\n",z,ans);
    }

    return 0;
}
