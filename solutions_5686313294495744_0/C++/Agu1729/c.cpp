#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
using namespace std;

int d[16][65536], n;
vector<pair<string, string> > ttl;


int dp(int k, int bt){
    if(d[k][bt]!=-1){
        return d[k][bt];
    }
    if(k==n-1){
        int check=0;
        for(int i=0;i<=n-1;i++){
            if(i!=k&&((bt>>i)%2)==1&&ttl[i].first==ttl[k].first){
                check|=1;
            }
            if(i!=k&&((bt>>i)%2)==1&&ttl[i].second==ttl[k].second){
                check|=2;
            }
        }
        if (check==3){
            d[k][bt]=1;
            return 1;
        }
        else{
            d[k][bt]=0;
            return 0;
        }
    }
    if((bt>>k)%2==0){
        d[k][bt]=dp(k+1, bt);
        return d[k][bt];
    }
    else{
        int check=0;
        for(int i=0;i<=n-1;i++){
            if(i!=k&&((bt>>i)%2)==1&&ttl[i].first==ttl[k].first){
                check|=1;
            }
            if(i!=k&&((bt>>i)%2)==1&&ttl[i].second==ttl[k].second){
                check|=2;
            }
        }
        if (check==3){
            d[k][bt]=max(dp(k+1, bt), dp(k+1, bt^(1<<k))+1);
            return d[k][bt];
        }
        else{
            d[k][bt]=dp(k+1, bt);
            return d[k][bt];
        }
    }
}

int main(){
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int T, cs, mk;
    cin>>T;
    for(cs=1;cs<=T;cs++){
        cout<<"Case #"<<cs<<": ";
        cin>>n;
        ttl.clear();
        ttl.resize(n);
        mk=0;
        for(int i=0;i<=15;i++){
            for(int j=0;j<=65535;j++){
                d[i][j]=-1;
            }
        }
        for(int i=0;i<=n-1;i++){
            cin>>ttl[i].first>>ttl[i].second;
            mk|=(1<<i);
        }
        cout<<dp(0, mk)<<endl;
    }
    return 0;
}
