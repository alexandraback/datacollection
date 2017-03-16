#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int cnt1[1005],cnt2[1005];

void dfs(int pos,int n,int sum,int *cnt,string &a){
    if(pos == n){
        cnt[sum] = 1;
        return;
    }
    if(a[pos] != '?'){
        sum = sum*10+a[pos]-'0';
        dfs(pos+1,n,sum,cnt,a);
    }
    else{
        for(int i = 0; i < 10; ++i){
            dfs(pos+1,n,sum*10+i,cnt,a);
        }
    }
}

int main(){
    freopen("B-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,t = 0;
    scanf("%d",&T);
    while(T--){
        string a,b;
        cin>>a>>b;
        int len = a.size();
        memset(cnt1,0,sizeof(cnt1));
        memset(cnt2,0,sizeof(cnt2));
        dfs(0,len,0,cnt1,a);
        dfs(0,len,0,cnt2,b);
        int ans1=INF*2,ans2=INF;
        for(int i = 0; i < 1000; ++i){
            for(int j = 0; j < 1000; ++j){
                if(cnt1[i] && cnt2[j]){
                    if(abs(j-i) < abs(ans1-ans2)){
                        ans1 = i,ans2 = j;
                    }
                    else if(abs(j-i) == abs(ans1-ans2) && j<ans2){
                        ans1 = i,ans2 = j;
                    }
                }
            }
        }
        if(len == 1)
            printf("Case #%d: %01d %01d\n",++t,ans1,ans2);
        if(len == 2)
            printf("Case #%d: %02d %02d\n",++t,ans1,ans2);
        if(len == 3)
            printf("Case #%d: %03d %03d\n",++t,ans1,ans2);
    }
    return 0;
}
