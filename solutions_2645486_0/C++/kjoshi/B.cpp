#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <functional>

using namespace std;

int main()
{
    int i,j,k,l;
    int T,t;

    freopen("B-small-attempt4.in","r",stdin);
    freopen("output-B.txt","w",stdout);

    cin>>T;
    for(t=1;t<=T;++t)
    {
        long long E,R,N,V[12000];
        long long ans=0,maxv=0,prev=0;
        cin>>E>>R>>N;
        for(i=0;i<N;++i)
            cin>>V[i];
                    if(R>E)
            R=E;

        if(N==1)
            ans=V[0]*E;
        else
        {

        while(maxv<N)
        {
            for(i=maxv;i<N;++i)
            {
                 if(V[i]>=V[maxv])
                    maxv=i;
            }
            for(j=prev;j<maxv;++j)
            {
                ans+=(V[j]*R);
            }
            ans-=(V[maxv]*R);
            ans+=(V[maxv]*E);
            maxv++;
            prev=maxv;
        }
        }

        cout<<"Case #"<<t<<": "<<ans<<endl;
    }


    return 0;
}
