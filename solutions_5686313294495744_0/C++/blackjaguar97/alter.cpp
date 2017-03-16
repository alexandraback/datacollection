#include <bits/stdc++.h>
#define P(x,y) make_pair(x,y)
using namespace std;
const int MX=17;
string str[MX][2];
int dp[1<<MX] , n , mxmask;
int mask[MX][2];
int calc(int curmask){
    if(curmask == mxmask) return 0;
    int &ret = dp[curmask]; if(ret!=-1) return ret;
    ret = -(1<<20);
    for(int j=0;j<n;j++){
        if( (curmask&(1<<j)) ) continue;
        int o0 = (mask[j][0]&curmask);
        int o1 = (mask[j][1]&curmask);
        int d=0 , nxtmask = curmask;
        nxtmask|=(1<<j);
        if(o0 > 0 && o1 > 0){
            d=1;
            if(__builtin_popcount(o0) == 1 && o0 == o1 )
                d=0;
        }
        ret = max(ret , calc(nxtmask) + d);
    }
    return ret;
}
int main(){
   // freopen("in.in","r",stdin);
  //  freopen("out.out","w",stdout);
    int T , Tn=0;
    cin>>T;
    while(T--){
        cin>>n;
        mxmask=(1<<n)-1;
        for(int j=0;j<n;j++) cin>>str[j][0]>>str[j][1];
        memset(mask , 0 , sizeof(mask));
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                if(str[j][0] == str[i][0]){
                    mask[j][0] |= (1<<i);
                    mask[i][0] |= (1<<j);
                }
                if(str[j][1] == str[i][1]){
                    mask[j][1] |=(1<<i);
                    mask[i][1] |=(1<<j);
                }
            }
        }
        memset(dp , -1 , sizeof(dp));
        printf("Case #%d: ",++Tn);
        cout<<calc(0)<<endl;
        //cout<<s1<<' '<<s2<<endl;
    }
}

