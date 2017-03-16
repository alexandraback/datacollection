#include<bits/stdc++.h>
#define P(x,y) make_pair(x,y)
using namespace std;
const int MX=1004;
int to[MX] , start[MX] , vis[MX] , sz[MX] , cycle[MX];
bool dp[1003][1003];
int ans=0;
void fuck(int x){
    memset(vis , 0 , sizeof(vis));
    int cur = x , timer=0 , omar;
    vector < int > vec;
    while(1){
        ++timer;
        if(vis[cur]){
            omar = cur;
            cycle[cur] = timer - vis[cur];
            if(cycle[cur] == 2)
                cycle[vec.back()]=2;
            while(vec.back()!=cur)
                vec.pop_back();
            break;
        }
        vec.push_back(cur);
        vis[cur] =timer;
        cur = to[cur];
    }
   if(cycle[omar] != 2)
        return;
   sz[omar] = max(sz[omar] , (int) vec.size()-1);
}
int main(){
    //freopen("in.in","r",stdin);
    //ظظfreopen("out.out","w",stdout);
    int T , Tn=0;
    cin>>T;
    while(T--){
        vector < pair < int , int > > v;

        v.push_back(P(0 , 0));
//        memset(cnt , 0 , sizeof(cnt));
        memset(dp , 0 , sizeof(dp));
        memset(vis , 0 , sizeof(vis));
        memset(sz , 0 , sizeof(sz));
        memset(cycle , 0 , sizeof(cycle));

        int n;
        scanf("%d",&n);
        printf("Case #%d: ",++Tn);
        for(int j=1;j<=n;j++) {
            scanf("%d",&to[j]);
            start[j] = 1;
        }
        for(int j=1;j<=n;j++) start[to[j]]=0;
        for(int j=1;j<=n;j++){
            if(vis[j]) continue;
            if(!start[j]) continue;
            fuck(j);
        }
        for(int j=1;j<=n;j++){
            if(vis[j]) continue;
            fuck(j);
        }
    //    cout<<endl;
        ans=0;
        for(int j=1;j<=n;j++){
            if(!cycle[j]) continue;
            //cout<<j<<' '<<cycle[j]<<' '<<sz[j]<<endl;
            if(cycle[j] != 2)
                ans = max(ans , cycle[j]);
            else{
          //      cout<<sz[j]<<endl;
                if(to[j] > j) continue;
                v.push_back(P(2 , sz[j] + sz[to[j]] + 2));
        //        cout<<v.back().first<<' '<<v.back().second<<endl;
            }
        }


        int lim = v.size()-1;
        dp[0][0]=1;
        //cout<<lim<<endl;
        for(int j=1;j<=lim;j++){
            for(int i=0;i<=n;i++) dp[j][i] |= dp[j][i-1];
            int  zeroes=0 , left=0 , right=0 , ones=1;
            //cout<<v[j].first<<' '<<v[j].second<<endl;
            for(int i=v[j].first;i<=n;i++){
                int st = max(0 , i - v[j].second) , en = max(0 , i - v[j].first);
                while(right<en)
                    ones+=dp[j-1][++right];
                while(left<st)
                    ones-=dp[j-1][left++];
                if(ones) dp[j][i] = 1;
            }
        }
        for(int j=0;j<MX;j++)
            if(dp[lim][j])
                ans=max(ans , j);
        cout<<ans<<endl;
    }

}

