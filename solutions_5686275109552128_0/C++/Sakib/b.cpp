#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#define inf 2000000000
#define ll long long
#define Max

using namespace std;

vector <int> v;


int main()
{
    int i,j,k,T,cas,ret=0,n;

    freopen("/Users/sakibshafayat/Documents/Codes/CodesRunning/Codejam15/Quali/B-small-attempt3.in","r",stdin);
    freopen("/Users/sakibshafayat/Documents/Codes/CodesRunning/Codejam15/Quali/B-small.txt","w",stdout);
    //freopen("/Users/sakibshafayat/Documents/Codes/CodesRunning/Codejam15/Quali/B-large.txt","w",stdout);

    scanf("%d",&T);

    for(cas=1;cas<=T;cas++)
    {
        scanf("%d",&n);

        v.clear();

        for(ret=0,i=1;i<=n;i++){
            scanf("%d",&j);
            ret=max(ret,j);
            v.push_back(j);
        }

        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        for(i=ret-1;i;i--){

            for(k=j=0;j<n;j++){

                if(v[j]<=i) break;
                k+=(v[j]-1)/i;
            }

            ret=min(ret,k+i);
        }

        printf("Case #%d: %d\n",cas,ret);
    }

    return 0;
}
