#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const string f="gcj31";
const string fin=f+".in";
const string fout=f+".out";

int vis[4][4][4],visID;
int arr[3000][3],arrID;
int cur[3],maxi[3];
int k;

void solveNaiive(int idx)
{
    if(idx==3)
    {
        int a=cur[0],b=cur[1],c=cur[2];
        if(vis[a][b][c]==0 && vis[a][b][0]<k && vis[a][0][c]<k && vis[0][b][c]<k)
        {
            vis[a][b][c]++;
            vis[a][b][0]++;
            vis[a][0][c]++;
            vis[0][b][c]++;
            arr[arrID][0]=a;
            arr[arrID][1]=b;
            arr[arrID][2]=c;
            arrID++;
        }
        return;
    }
    for(int i=1;i<=maxi[idx];i++)
        cur[idx]=i,solveNaiive(idx+1);
}


int main()
{
    freopen(fin.c_str(),"r",stdin);
    freopen(fout.c_str(),"w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    int T=0;
    while(t--)
    {
        T++;
        cin>>maxi[0]>>maxi[1]>>maxi[2]>>k;
        cout<<"Case #"<<T<<":";
        memset(vis,0,sizeof vis);
        arrID=0;
        solveNaiive(0);
        cout<<" "<<arrID<<"\n";
        for(int i=0;i<arrID;i++)
            cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<"\n";
    }
    return 0;
}
