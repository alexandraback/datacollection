#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
   freopen("out.txt","w",stdout);
    int tcase;
    cin>>tcase;
    for(int kj=1;kj<=tcase;kj++)
    {
        int c,d,v,f[35];bool ok[65]={0};
        cin>>c>>d>>v;int ans=0;
        for(int i=1;i<=d;i++) {cin>>f[i];ok[f[i]]=true;}
        vector<int> t;
        for(int i=1;i<=v;i++)
        {
            if(ok[i]){int x=t.size();
            for(int j=0;j<x;j++) t.push_back(i+t[j]);t.push_back(i);}

            if(!ok[i]&&find(t.begin(),t.end(),i)==t.end())
            {
                int x=t.size();
                ok[i]=true;ans++;
                for(int j=0;j<x;j++) t.push_back(i+t[j]);t.push_back(i);}
            }
            cout<<"Case #"<<kj<<": "<<ans<<endl;
        }

    return 0;
}
