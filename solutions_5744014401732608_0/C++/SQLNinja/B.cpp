#include<bits/stdc++.h>
#define ll long long
#define MAX 50
using namespace std;
ll dp[MAX],T[MAX][MAX];
bool valid(ll b,ll m){
    if(m>=b&&m!=1)return 0;
    for(int i=0;i<b;i++)
			for(int j=0;j<b;j++){
                T[i][j]=0;
				dp[j]=0;
			}
    dp[0]=1;
    for(int i=1;i<b-1;i++){
        for(int j=0;j<i;j++)
            dp[i]+=dp[j];
    }
    for(int i=0;i<b-1;i++){
        for(int j=i+1;j<b-1;j++)
            T[i][j]=1;
    }
    for(int i=b-2;i>=0;i--){
        if(dp[i]<=m){
            m-=dp[i];
            T[i][b-1]=1;
        }
    }
    return (m==0);
}
int main()
{
    freopen("B.in","r",stdin);
    freopen("out.txt","w",stdout);
    int tc;cin>>tc;
    for(int t=1;t<=tc;t++){
        printf("Case #%d: ",t);
        ll b,M;
        cin>>b>>M;
        if(valid(b,M)){
        cout <<"POSSIBLE"<<endl;
            for(int i=0;i<b-1;i++,cout<<endl)
                for(int j=0;j<b;j++)
                if(i+1==j)cout<<"1" ;
                else cout<<"0";
            for(int i=0;i<b;i++)
                cout<<"0";
                cout<<endl;
        }
        else cout <<"IMPOSSIBLE"<<endl;
    }
}
