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


void computeLPSArray(char *pat, int M, long long int *lps)
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;

    lps[0] = 0; // lps[0] is always 0
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           len = lps[len-1];

           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}


int main()
{
    ll T,z;
    freopen("B-small-attempt1.in","r",stdin);
    freopen("out","w",stdout);

    scanf("%lld",&T);
    for(z=1; z<=T; z++)
    {
        ll K,L,S, i, j;
        float ans=1,p;
        scanf("%lld%lld%lld",&K,&L,&S);
        ll A[26] = {0},B[26] = {0},E[L+5];
        char c, D[L+5],F[K+5];
        scanf("%s",F);
        for(i=0; i<K; i++){

            A[F[i] - 'A']++;
        }
        scanf("%s",D);
        for(i=0; i<L; i++){
            B[D[i] - 'A']++;
            if(A[D[i]-'A']==0)
                ans = 0;
        }

        if(ans == 1){
            computeLPSArray(D, L, E);
            for(i=0;i<L; i++){
            //    printf("%lld ",E[i]);
            }
            ans = 0;
            j = L;
            while(j<=S){
                ans++;
                j = j + L - E[L-1];
            }

    //        printf("%f ",ans);
            p =1;
            for(i=0;i<L;i++){
                p = (p*(A[D[i]-'A']))/K;
            }
            p = p*ans;
   //         printf("%f \n",p);
        printf("Case #%lld: %f\n",z,ans-p);
        }
        else{
            printf("Case #%lld: 0.0\n",z);
        }

    }

    return 0;
}
