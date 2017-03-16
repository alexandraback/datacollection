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
#define MX 1005

using namespace std;
map<string,int>mp;
pii P[22];
int dp[17][(1<<17)];
int n;
int A[17],B[17];
int mat[17][17];

int solve(int indx,int bit){
    if(bit==(1<<n)-1)
        return 0;
    int &ret=dp[indx][bit];
    if(ret!=-1)
        return ret;
    ret=0;
    memset(A,0,sizeof A);
    memset(B,0,sizeof B);
    memset(mat,0,sizeof mat);
    for(int i=0;i<n;i++){
        if(bit&(1<<i)){
            A[P[i].xx]=1;
            B[P[i].yy]=1;
            mat[P[i].xx][P[i].yy]=1;
        }
    }
    for(int i=0;i<n;i++){
        if(bit&(1<<i)) continue;
        if(mat[P[i].xx][P[i].yy]==1)
            ret=max(ret,solve(i,bit|(1<<i)));
        else{
            if(A[P[i].xx] && B[P[i].yy])
                ret=max(ret,1+solve(i,bit|(1<<i)));
            else
                ret=max(ret,solve(i,bit|(1<<i)));
        }
    }
    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int test; cin>>test;
    for(int kase=1;kase<=test;kase++){
        cin>>n;
        int cnt=1;
        mp.clear();
        for(int i=0;i<n;i++){
            string a,b; cin>>a>>b;
            if(mp.find(a)==mp.end())
                mp[a]=cnt++;
            if(mp.find(b)==mp.end())
                mp[b]=cnt++;
            P[i]=MP(mp[a],mp[b]);
        }
        memset(dp,-1,sizeof dp);
        int res=solve(0,0);
        cout<<"Case #"<<kase<<": "<<res<<endl;
    }
    return 0;
}

