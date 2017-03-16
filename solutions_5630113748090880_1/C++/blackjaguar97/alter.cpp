#include<bits/stdc++.h>
using namespace std;
int cnt[3000];
int main(){
  //  freopen("in.in","r",stdin);
   // freopen("out.out","w",stdout);
    int T , Tn=0;
    cin>>T;
    while(T--){
        memset(cnt , 0 , sizeof(cnt));
        int n;
        scanf("%d",&n);
        memset(cnt , 0 , sizeof(cnt));
        for(int j=1;j<n+n;j++){
            for(int i=1;i<=n;i++){
                int x;
                scanf("%d",&x);
                cnt[x]^=1;
            }
        }
        vector < int > sol;
        for(int j=0;j<3000;j++)
            if(cnt[j])
                sol.push_back(j);
        printf("Case #%d: ",++Tn);
        for(int j=0;j<sol.size();j++){
            if(j) putchar(' ');
            printf("%d",sol[j]);
        }
        puts("");
    }

}

