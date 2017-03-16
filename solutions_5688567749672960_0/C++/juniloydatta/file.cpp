#include<bits/stdc++.h>

#define xx first
#define yy second
#define LL long long
#define inf 100000000
#define pb push_back
#define vsort(v) sort(v.begin(),v.end())
#define pi acos(-1)
#define clr(a,b) memset(a,b,sizeof a)
#define bclr(a) memset(a,false,sizeof a)
#define pii pair<int,int>
#define MOD 1000000007
#define MP make_pair
#define MX 10000000

using namespace std;
int get(int x){
    int ret=0;
    while(x){
        int rem=x%10;
        ret=ret*10+rem;
        x/=10;
    }
    return ret;
}
int dis[1000006];
bool chk[1000006];
queue<int>Q;
vector<int>G[1000006];

int main(){
    freopen("fileIN.in","r",stdin);
    freopen("fileOUT.out","w",stdout);
    for(int i=1;i<=1000000;i++){
        G[i].pb(i+1);
        G[i].pb(get(i));
    }
    while(!Q.empty()) Q.pop();
        Q.push(1);
        dis[1]=1;
        chk[1]=true;
        while(!Q.empty()){
            int fr=Q.front();
            Q.pop();
            for(int i=0;i<G[fr].size();i++){
                int adj=G[fr][i];
                if(!chk[adj]){
                    chk[adj]=true;
                    dis[adj]=dis[fr]+1;
                    Q.push(adj);
                }
            }
        }
    int t;
    cin>>t;
    for(int kase=1;kase<=t;kase++){
        int n;
        cin>>n;
        cout<<"Case #"<<kase<<": "<<dis[n]<<endl;
    }
    return 0;
}
