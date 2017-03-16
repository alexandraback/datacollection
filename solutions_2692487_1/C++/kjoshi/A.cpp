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

    freopen("A-large.in","r",stdin);
    freopen("output-A.txt","w",stdout);

    cin>>T;
    for(t=1;t<=T;++t)
    {
        int A,mote[200],N,ans=0;
        cin>>A>>N;
        for(i=0;i<N;++i)
            cin>>mote[i];
        sort(mote,mote+N);
        k=0;
        vector<int> v1;
        v1.push_back(N);
        while(k<N&&ans<=N)
        {
            for(i=k;mote[i]<A&&i<N;++i)
                A+=mote[i];
            k=i;
            v1.push_back(ans+(N-k));
            while(ans<=N&&A<=mote[k])
            {
                A+=A-1;
                ans++;
            }
        }
        sort(v1.begin(),v1.end());
        cout<<"Case #"<<t<<": "<<v1[0]<<endl;
        //printf("Case #%d: %d\n",t,a);
    }


    return 0;
}
