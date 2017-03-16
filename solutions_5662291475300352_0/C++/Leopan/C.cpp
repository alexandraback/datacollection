#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10 + 10;
vector<int>d,m;
int main(){
    freopen("C-small-1-attempt1.in","r",stdin);
    freopen("C-small.out","w",stdout);
    int T,Case=0,n;
    int D,H,M,ans;
    scanf("%d",&T);
    while(T--){
        d.clear(),m.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&D,&H,&M);
            for(int i=1;i<=H;i++){
                d.push_back(D);
                m.push_back(M+i-1);
            }
        }
        if(d[0]>d[1]){
            swap(d[0],d[1]);
            swap(m[0],m[1]);
        }
        if(m[0]>=m[1]){
            if(1LL*(360-d[0])*(m[0]-m[1])<1LL*(360-d[1]+d[0])*m[1])ans=0;
            else ans=1;

        }
        else{
            if(1LL*(360-d[1])*(m[1]-m[0])<1LL*(d[1]-d[0]+360)*m[0])ans=0;
            else ans=1;
        }
        printf("Case #%d: %d\n",++Case,ans);
    }
    return 0;
}
