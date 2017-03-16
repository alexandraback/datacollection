#include <iostream>
#include <algorithm>
using namespace std;

int n;
double p1[2000], p2[2000];

int deceitfulWar()
{
    int win=0;
    bool used[2000];
    for(int i=1; i<=n; ++i)
        used[i] = false;
    for(int j=n; j>=1; --j)
    {
        bool canWin = false;
        for(int i=1; i<=n; ++i)
            if(!used[i] && p2[j]<p1[i])
            {
                canWin = true;
                used[i] = true;
                break;
            }
        if(canWin)
        {
            ++win;
        }
        else
        {
            for(int i=1; i<=n; ++i)
                if(!used[i])
                {
                    used[i]=true;
                    break;
                }
        }
    }
    return win;
}

int war()
{
    int win = 0;
    bool used[2000];
    for(int i=1; i<=n; ++i)
        used[i] = false;
    for(int i=1; i<=n; ++i)
    {
        bool canWin = true;
        for(int j=1; j<=n; ++j)
        {
            if(!used[j] && p2[j]>p1[i])
            {
                used[j] = true;
                canWin = false;
                break;
            }
        }
        if(canWin)
        {
            ++win;
            for(int j=1; j<=n; ++j)
                if(!used[j])
                {
                    used[j] = true;
                    break;
                }
        }
    }
    return win;
}

int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; ++i)
    {
        cin>>n;
        for(int j=1; j<=n; ++j) cin>>p1[j];
        for(int j=1; j<=n; ++j) cin>>p2[j];
        sort(p1, p1+n+1);
        sort(p2, p2+n+1);
        /*for(int j=1; j<=n; ++j) cout<<p1[j]<<" ";
        cout<<endl;
        for(int j=1; j<=n; ++j) cout<<p2[j]<<" ";
        cout<<endl;*/
        cout<<"Case #"<<i<<": "<<deceitfulWar()<<" "<<war()<<endl;
    }
    return 0;
}
