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

bool isSubsetSum(ll set[], ll n, ll sum)
{
    // The value of subset[i][j] will be true if there is a subset of set[0..j-1]
    //  with sum equal to i
    bool subset[sum+1][n+1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
      subset[0][i] = true;

    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
      subset[i][0] = false;

     // Fill the subset table in botton up manner
     for (int i = 1; i <= sum; i++)
     {
       for (int j = 1; j <= n; j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i >= set[j-1])
           subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
       }
     }

    /* // uncomment this code to print table
     for (int i = 0; i <= sum; i++)
     {
       for (int j = 0; j <= n; j++)
          printf ("%4d", subset[i][j]);
       printf("\n");
     } */

     return subset[sum][n];
}

int main()
{
    ll T,z;
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out","w",stdout);

    scanf("%lld",&T);
    for(z=1; z<=T; z++)
    {
        ll C,D,V, i, j, ans = 0;
        scanf("%lld%lld%lld",&C,&D,&V);
        ll A[V],S[V];
        for(i=0; i<D; i++){
            scanf("%lld",&A[i]);
        }
        sort(A,A+D);

        for(i=1;i<=V;i++){

        if (isSubsetSum(A, D, i) != true){
                A[D] = i;
                ans++;
                D++;
        }


        }
        printf("Case #%lld: %lld\n",z,ans);
    }

    return 0;
}
