#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A-small-attempt1.in","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=20;

ll p10[N],f10[N];
int test;
char s[N];
int main(){
    INPUT;OUTPUT;
    p10[0]=1;
    FOR(i,1,15) p10[i]=p10[i-1]*10;
    f10[1]=1;
    f10[2]=10;
    FOR(i,3,14) f10[i]=p10[i/2]+p10[(i-1)/2]-1+f10[i-1];
    //FOR(i,1,5) cout<<f10[i]<<" ";
    scanf("%d",&test);
    FOR(t,1,test){
        scanf("\n%s",s);
        int n=strlen(s);
        ll ans=f10[n];
        //cout<<ans<<'\n';
        ll cur=0;
        REP(i,0,n) cur=10*cur+s[i]-'0';
        if (cur!=p10[n-1]){
            if (cur>=10){
                ll curL=0,curR=0;
                if (n%2) {
                    ans+=1LL*(s[n/2]-'0')*p10[n/2];
                    FORD(i,n/2-1,0) curL=10*curL+s[i]-'0';
                    FOR(i,n/2+1,n-1) curR=10*curR+s[i]-'0';
                }else{
                    FORD(i,n/2-1,0) curL=10*curL+s[i]-'0';
                    FOR(i,n/2,n-1) curR=10*curR+s[i]-'0';
                }
                //cout<<ans<<'\n';
                ll nflip=0;
                REP(i,0,n) if (n%2==0||i!=n/2) nflip+=1LL*(s[i]-'0'-(i==0))*p10[n-i-1];
                if (curR==0) ans+=nflip;
                else ans+=min(nflip,curR+curL);
                //cout<<nflip<<" "<<curR<<" "<<curL<<'\n';
            }else ans=cur;

        }
        printf("Case #%d: %lld\n",t,ans);
    }
}
