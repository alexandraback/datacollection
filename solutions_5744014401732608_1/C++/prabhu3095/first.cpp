#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll mem[55];
int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("out1.txt", "w", stdout);

    int t;
    cin>>t;
    mem[0]=1;
    for(int i=1; i<=51; i++)
        mem[i]=mem[i-1]*2;
    for(int cas=1; cas<=t; cas++){

        ll n, m;
        cin>>n>>m;
        cout<<"Case #"<<cas<<": ";
        ll mark[55];
        memset(mark, 0, sizeof mark);
        ll x=mem[n-2];

        if(m>x){
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        else{
            cout<<"POSSIBLE\n";
        }
        ll y=m;
        if(x==m)
            y--;


        vector<ll>temp;
        while(y){
            temp.push_back(y%2);
            //cout<<y%2;
            y/=2;

        }
       // cout<<endl;
        for(int i=0; i<temp.size(); i++){
            if(temp[i]){
                mark[i]=1;
            }
        }

        int node[55];
        memset(node, 0, sizeof node);

        for(int i=0; i<n-2; i++){
            if(mark[i]){
                node[n-i-1]=1;
            }
        }

        if(x==m){
            node[1]=1;
        }
        int l=0, c=0;
        for(int i=1; i<=n; i++){
          //  cout<<node[i]<<" ";
          if(node[i]){
            l=i;
            c++;
            break;
          }
        }
        //cout<<endl;*/
        int ans[55][55];
        memset(ans, 0, sizeof ans);

        for(int i=1; i<n; i++){
            ans[i][i+1]=1;
        }
        c=1;
        if(m>1)
        for(int i=2; i<=n; i++){
            if(node[i]){
                if(c){
                    c=0;
                    continue;
                }
                ans[1][i]=1;
            }
        }
        //cout<<l<<endl;
        for(int i=l; i<n; i++){
            for(int j=i+1; j<=n; j++){
                ans[i][j]=1;
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cout<<ans[i][j];
            }
            cout<<"\n";
        }

    }

    return 0;
}
