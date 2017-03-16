#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int ti=0;ti<t;++ti)
    {
        int n,m,b;
        cin>>n>>m>>b;

        int mn=min(n,m),mx=max(n,m);
        char tab[mn][mx];
        for(int i=0;i<mn;++i)
            for(int j=0;j<mx;++j)
                tab[i][j]='*';
        tab[0][0]='c';

        cout<<"Case #"<<ti+1<<": "<<endl;
        if(b<m*n-1)
        {
            if(mn==1)
            {
                for(int i=1;i<mx-b;++i)
                    tab[0][i]='.';
            }else if(mn==2)
            {
                if(b%2 || m*n-b==2)
                {
                    cout<<"Impossible"<<endl;
                    continue;
                }
                tab[1][0]='.';
                for(int i=1;i<mx-b/2;++i)
                {
                    tab[0][i]='.';
                    tab[1][i]='.';
                }
            }else
            {
                int z=n*m-b;
                if(z==2 || z==3 || z==5 || z==7)
                {
                    cout<<"Impossible"<<endl;
                    continue;
                }

                int sd=min(mn,(int)floor(sqrt(z)));

                for(int i=0;i<sd;++i)
                    for(int j=0;j<sd;++j)
                        tab[i][j]='.';
                tab[0][0]='c';
                z-=sd*sd;
                if(z==1)
                {
                    tab[sd-1][sd-1]='*';
                    ++z;
                }
                for(int i=sd;i<mx && z>1;++i)
                {
                    z-=2;
                    tab[0][i]='.';
                    tab[1][i]='.';
                }
                for(int i=2;z>0 && i<sd;++i)
                    for(int j=sd;z>0 && j<mx;++j)
                    {
                        if(i==sd-1 && j==mx-1 && z==2)
                            continue;
                        tab[i][j]='.';
                        --z;
                    }
                for(int i=0;i<mx && z>0;++i)
                {
                    tab[sd][i]='.';
                    --z;
                }
            }
        }

        if(n==mn)
        {
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<m;++j)
                    cout<<tab[i][j];
                cout<<endl;
            }
        }else
        {
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<m;++j)
                    cout<<tab[j][i];
                cout<<endl;
            }
        }
    }
    return 0;
}
