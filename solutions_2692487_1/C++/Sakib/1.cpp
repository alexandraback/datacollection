#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#define inf 1000000000
#define ll long long

using namespace std;

ll a,mots[105],n;

int main()
{
    ll i,j,k,t,T,cost=0,ret=0;

    freopen("A-large(2).in","r",stdin);
    freopen("a-large.txt","w",stdout);

    cin>>T;

    for(t=1;t<=T;t++)
    {
        cin>>a>>n;

        ret=n;
        cost=0;

        for(i=0;i<n;i++) cin>>mots[i];

        sort(mots,mots+n);

        for(i=0;i<n;i++)
        {
            if(mots[i]<a)
            {
                a+=mots[i];
            }

            else
            {
                k=cost+n-i;
                ret=min(ret,k);

                if(a<=1) break;

                while(a<=mots[i])
                {
                    a+=a-1;
                    cost++;

                }

                a+=mots[i];
            }
        }

        if(i==n) ret=min(ret,cost);

        cout<<"Case #"<<t<<": "<<ret<<endl;

    }
    return 0;
}
