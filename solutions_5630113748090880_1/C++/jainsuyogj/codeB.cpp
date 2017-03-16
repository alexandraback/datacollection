#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define maxi 1000006
vector<vector<int> > arr;
int tmp[51][51];
int an[51][51];
int vis[51];
int n;
int mx=0;
int tt[2600];
int main()
{
    freopen("inb.txt","r",stdin);
    freopen("outb.txt","w",stdout);
    int t;
    cin>>t;
    for(int ii=1;ii<=t;ii++)
    {
       /* int ans=0;
        cin>>n;
        arr.clear();
        int mn=11000,mx=0,inmn,inmx;
        for(int i=0;i<2*n-1;i++){
            arr.push_back(new vector<int>());
            for(int j=0;j<n;j++){
                cin>>tmp[i][j];
                arr[i].push_back(tmp[i][j]);
                if(tmp[i][j]<mn)
                {
                    mn=tmp[i][j],inmn=i;
                }
                if(tmp[i][j]>mx)
                {
                    mx=tmp[i][j],inmx=i;
                }
            }
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<2*n-1;i++)
        {

        }*/
        for(int i=0;i<2600;i++)
            tt[i]=0;
        int n;
        cin>>n;
        for(int i=0;i<2*n-1;i++)
        for(int j=0;j<n;j++){
            int q;
            cin>>q;
            tt[q]++;
        }

        cout<<"Case #"<<ii<<": ";
        for(int i=0;i<2600;i++)
            if(tt[i]%2!=0)
                cout<<i<<" ";
        cout<<endl;
        mx=0;
    }
}
