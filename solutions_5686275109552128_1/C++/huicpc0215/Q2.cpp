#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
int box[1010];
int main(){
    freopen("./B-large.in","r",stdin);
    freopen("./B-large.out","w",stdout);
    int T,casenum=1;
    scanf("%d",&T);
    while(T--){
        int ans,maxpi=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&box[i]);
            if( box[i] > maxpi )
                maxpi = box[i];
        }
        ans = maxpi;
        for(int i=1;i<=maxpi;i++){
            int tmpans = i;
            for(int j=0;j<n;j++){
                tmpans += (box[j]-1)/i;
            }
            ans = min ( ans , tmpans );
        }
        printf("Case #%d: %d\n",casenum++,ans);
    }
    return 0;
}
