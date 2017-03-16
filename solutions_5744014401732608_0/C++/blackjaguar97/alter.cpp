#include <bits/stdc++.h>

using namespace std;

char sol[200][200];
long long T , Tn , lim , dp[200];
long long calc(int x){
    if(x == lim) return 1;
    long long &ret = dp[x]; if(ret!=-1) return ret;
    ret = 0;
    for(int nxt=1;nxt<=lim;nxt++){
        if(sol[x][nxt] == '1')
            ret+=calc(nxt);
    }
    return ret;
}
int main() {
   // freopen("in.in","r",stdin);
   // freopen("out.out","w",stdout);
    cin>>T;
    while(T--){
        for(int j=0;j<200;j++) for(int i=0;i<200;i++) sol[j][i] = '0';
        long long K;
        cin>>lim>>K;
        memset(dp , -1 , sizeof(dp));
        printf("Case #%lld: ",++Tn);

        long long n=1 , mx=0;
        if( (K&1) ) sol[1][lim] = '1';
        for(long long j=1;j<63;j++){
            if( (K&(1ll<<j)) == 0) continue;
            mx = j;
        }
        long long layer=0;
        while(mx--){
            layer++;
            sol[n][n+1] = '1';
            sol[n][n+2] = '1';
            sol[n+1][n+2] = '1';
            n+=2;
            if( (K&(1ll<<layer)) && n!=lim ) sol[n][lim] = '1';
        }
        //cout<<n<<' '<<lim<<endl;
        //continue;
        if(n>lim || calc(1) != K){
            puts("IMPOSSIBLE");
            continue;
        }
        puts("POSSIBLE");
        for(long long j=1;j<=lim;j++){
            for(long long i=1;i<=lim;i++)
                putchar(sol[j][i]);
            puts("");
        }
    }
}

