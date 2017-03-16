//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;


int  main()
{
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);

    long long T,R,C,W,i,j,k,ans,cas=0;
    cin>>T;
    while(T--)
    {
        cas++;

        cin>>R>>C>>W;
        //cout<<ans<<" ";

        ans=(C/W)*(R-1);

        ans+=((C/W)+W-1);
        if(C%W) ans++;

        printf("Case #%lld: %lld\n",cas,ans);

    }

}
