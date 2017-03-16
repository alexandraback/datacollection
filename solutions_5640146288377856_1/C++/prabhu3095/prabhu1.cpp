#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out1.txt","w",stdout);

    int t,r,c,w;
    cin>>t;
    for(int j=1;j<=t;j++)
    {
        cin>>r>>c>>w;
        int ans=0;


        if(c%w!=0)
            ans=c/w+1+max(c%w,w-1)+(c/w)*(r-1);
        else
            ans=ans=c/w+max(c%w,w-1)+(c/w)*(r-1);

            cout<<"Case #"<<j<<": "<<ans<<endl;

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
