#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int dp[1<<21];
bool solve(vector<int>arr,pair<int,int>&ans){
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if((arr[i]&arr[j])==0){
                ans.first = arr[i];
                ans.second = arr[j];
                return true;
            }
        }
    }
    return false;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int tt=0;tt<T;tt++){
        int n;
        scanf("%d",&n);
        int arr[30];
        vector<pair<int,int> > que;
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        dp[0] = 0;
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                if((1<<j)&i){
                    continue;
                }
                dp[(1<<j)|i] = dp[i] + arr[j];
                que.push_back(make_pair(dp[(1<<j)|i],(1<<j)|i));
            }
        }
        sort(que.begin(),que.end());
        int pre = -1;
        pair<int,int>ans;
        vector<int>tmp;
        bool succ = false;
        for(int i=0;i<que.size();i++){
            if(pre!=que[i].first){
                if(solve(tmp,ans)){
                    succ = true;
                    break;
                }
                pre = que[i].first;
                tmp.clear();
                tmp.push_back(que[i].second);
            }else{
                tmp.push_back(que[i].second);
            }
        }
        if(solve(tmp,ans)){
            succ = true;
        }
        printf("Case #%d:\n",tt+1);
        if(succ){
            for(int i=0;i<n;i++){
                if(ans.first&(1<<i)){
                    printf("%d ",arr[i]);
                }
            }
            puts("");
            for(int i=0;i<n;i++){
                if(ans.second&(1<<i)){
                    printf("%d ",arr[i]);
                }
            }
            puts("");
        }else{
            puts("Impossible");
        }
    }
}
