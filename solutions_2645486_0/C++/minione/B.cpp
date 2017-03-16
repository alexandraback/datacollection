#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int T,E,R,n;
int ans=0;
int v[20000];

void search(int dep, int energy, int gain)
{
    //cout<<dep<<"  "<<energy<<"  "<<gain<<endl;
    if (dep==n-1)
    {
        gain+=energy*v[dep];
        //cout<<dep+1<<"  "<<energy<<"  "<<gain<<endl;
        if (gain>ans) ans=gain;
    }
    else
    {
        for (int i=0; i<=energy; ++i)
        {
            if (energy-i+R<=E)
            {
                search(dep+1,energy-i+R,gain+v[dep]*i);
            }
        }
    }
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    cin>>T;
    for (int tt=1; tt<=T; ++tt)
    {
        cin>>E>>R>>n;
        for (int i=0; i<n; ++i) cin>>v[i];
        ans=0;
        search(0,E,0);
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}
