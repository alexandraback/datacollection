#include <bits/stdc++.h>
#define pii pair<int,int >
using namespace std;
int M,B;
bool ok=false;
vector<pii> ans;
void recur(int x,int y,vector<pii> vec){
    if(ok)return;
    if(x==B){
        int dp[10]={0};
        dp[1]=1;
        for(int i=0;i<vec.size();i++){
            int a=vec[i].first;
            int b=vec[i].second;
            dp[b]+=dp[a];
        }
        if(dp[B]==M){
            ok=true;
            ans=vec;
        }
        return;
    }
    if(y==B+1){
        recur(x+1,x+2,vec);
        return;
    }
    vector<pii> dup1=vec,dup2=vec;
    dup1.push_back(make_pair(x,y));
    recur(x,y+1,dup1);
    recur(x,y+1,dup2);

}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,tc=0,i,j,a;
    cin>>t;
    while(t--){
        cin>>B>>M;
        ok=false;
        ans.clear();
        vector<pii> empt;
        recur(1,2,empt);
        if(ok){
            printf("Case #%d: POSSIBLE\n",++tc);
            int mat[10][10]={0};
            for(i=0;i<ans.size();i++){
                int x=ans[i].first;
                int y=ans[i].second;
                mat[x][y]=1;
            }
            for(i=1;i<=B;i++){
                for(j=1;j<=B;j++)cout<<mat[i][j];
                cout<<endl;
            }
        }
        else {
            printf("Case #%d: IMPOSSIBLE\n",++tc);
        }
    }
    return 0;
}
