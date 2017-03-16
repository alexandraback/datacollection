#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
int f[1048580];
vector<int> g[10000005];

int main()
{
    freopen("C-small-attempt2.in","r",stdin);
   freopen("result.out","w",stdout);
    int T;
    int a[100];

    cin>>T;

    for (int N=1; N<=T; N++)
    {
        for (int i=0; i<10000005; i++) g[i].clear();
        int n;
        cin>>n;
        for (int i=1; i<=n; i++) cin>>a[i];
        bool flag=false;
        for (int i=1; i<=(1<<n); i++)
        {
            int s=0;
            for (int j=0; j<n; j++)
               if ((i&(1<<j))!=0) s+=a[j+1];
            f[i]=s;

            if (g[s].size()!=0)
            {

                for (int j=0; j<g[s].size(); j++)
                {
                    int k=g[s][j];

                    if (((i&k)==0) && (f[i]==f[k]))
                    {

                        cout<<"Case #"<<N<<": "<<endl;
                        //cout<<f[i]<<" "<<f[k]<<endl;
                        flag=true;
                        for (int j=0; j<n; j++) if ((( (k&(1<<j))))!=0) cout<<a[j+1]<<" ";
                        cout<<endl;
                        for (int j=0; j<n; j++) if (( (i&(1<<j)))!=0) cout<<a[j+1]<<" ";
                        cout<<endl;
                        break;
                    }
                    if (flag) break;
                }
            }
            if (flag) break;
            g[s].push_back(i);
        }
        if (!flag)
        {
            cout<<"Case #"<<N<<": Impossible"<<endl;
        }


    }
    return 0;
}
