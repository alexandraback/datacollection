#include<bits/stdc++.h>
using namespace std;
vector<int>d,m;
int main(){
    freopen("C-small-2-attempt3.in","r",stdin);
    freopen("C-small-2.out","w",stdout);
    int T,Case=0,n;
    int D,H,M,ans;
    scanf("%d",&T);
    while(T--){
        d.clear(),m.clear();
        int mm=0,dd=0,id;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&D,&H,&M);
            for(int i=1;i<=H;i++){
                d.push_back(D);
                m.push_back(M+i-1);
                if(M+i-1>mm){
                    mm=M+i-1;
                    dd=D;
                    id=d.size()-1;
                }
                else if(M+i-1==mm){
                    if(dd>D){
                        dd=D;
                        id=d.size()-1;
                    }
                }
            }
        }
        swap(d[0],d[id]);
        swap(m[0],m[id]);
        ans=0;
        for(int i=1;i<d.size();i++){
            if(m[0]>=m[i]){
                if(1LL*(360-d[0])*(m[0]-m[i])<1LL*(360-d[i]+d[0])*m[i]);
                else ans++;
            }
            else{
                if(1LL*(360-d[i])*(m[i]-m[0])<1LL*(d[i]-d[0]+360)*m[0]);
                else ans++;
            }
        }
        printf("Case #%d: %d\n",++Case,ans);
    }
    return 0;
}
