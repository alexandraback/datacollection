#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("out.txt", "w",stdout);
    int t;
    cin>>t;
    for(int jj=1;jj<=t;jj++)
    {
        int c,d,v,f[35];
        bool tab[65]={0};
        cin>>c>>d>>v;
        int ans=0;//you got me :/
        for(int i=1;i<=d;i++) {cin>>f[i];tab[f[i]]=true;}
        vector<int> t;
        for(int i=1;i<=v;i++)
        {
            if(tab[i]){int x=t.size();
            for(int j=0;j<x;j++) t.push_back(i+t[j]);t.push_back(i);}

            if(!tab[i]&&find(t.begin(),t.end(),i)==t.end())
            {
                int x=t.size();
                tab[i]=true;ans++;
                for(int j=0;j<x;j++) t.push_back(i+t[j]);t.push_back(i);}
            }
            cout<<"Case #"<<jj<<": "<<ans<<endl;
        }

    return 0;
}
