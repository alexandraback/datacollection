#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<cmath>
#include<ctime>

#define FO(i,s,e,p) for(int i=(s);i<int(e);i+=p)
#define FOD(i,s,e,p) for(int i=(s);i>int(e);i-=p)


#define FOR(i,s,e) FO(i,s,e,1)
#define FORE(i,s,e) FOR(i,s,e+1)
#define FORD(i,s,e) FOD(i,s,e,1)
#define FORDE(i,s,e) FORD(i,s,e-1)

#define ALL(i,s) for(__typeof((s).begin()) i=(s).begin();i!=(s).end();i++)

#define MEM(tab,fill) memset(tab,fill,sizeof(tab))

#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<sstream>
#include<stack>
#include<queue>
#include<algorithm>
#include<utility>
#include<bitset>
#include<map>
#include<cassert>
#define pb push_back
#define ll long long
using namespace std;

#define EPS 0.0000001
#define MOD 1000000007
#define mp make_pair
#define fi first
#define se second
#define inf ((1<<29)-1)
#define deb(a) cout<<#a<<' '<<a<<endl;
#define PI pair<ll,ll>
#define llu unsigned ll

#define AL(a) (a).begin(),(a).end()
#define PII pair<PI,PI>


#define SZ 4010
string tmp;
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
vector<pair<llu,ll> > glo;
inline pair<llu,ll> has(const string &z)
{
    llu a=1,b=2;
    FOR(i,0,z.size()){
        a*=27;
        b*=29;b%=MOD;
        a+=z[i]-'a';b+=z[i]-'a';
    }
    return mp(a,b);
}
inline pair<llu,ll> has(int aa,int bb)
{
    llu a=1,b=2;
    FORE(i,aa,bb){
        a*=27;
        b*=29;b%=MOD;
        a+=tmp[i]-'a';b+=tmp[i]-'a';
    }
    return mp(a,b);
}
inline bool isit(int a,int b){
    return binary_search(glo.begin(),glo.end(),has(a,b));
}

int dp[SZ][6];

inline int MN(int a,int b){
    if(a==-1 || b==-1) return MAX(a,b);
    return MIN(a,b);
}

void solve(){
    tmp[0]=0;
    cin>>tmp;
    tmp=" "+tmp;

    MEM(dp,-1);
    MEM(dp[0],0);
    FOR(i,1,tmp.size()){

        FOR(en,MAX(0,i-10),i){



            FORE(p1,en+1,i)
            FORE(p2,p1+5,i){
                int isd=5-(p1-en);
                isd=MAX(0,isd);

                if(dp[en][isd]==-1) continue;

                char sv1=tmp[p1],sv2=tmp[p2];
                int ac=dp[en][isd]+2;

                int med=min(5,i-p2);

                FORE(c1,'a','z')
                FORE(c2,'a','z'){
                    tmp[p1]=c1;
                    tmp[p2]=c2;

                    if(isit(en+1,i)){
                        dp[i][med]=MN(dp[i][med],ac);
                        break;
                    }

                }
                tmp[p1]=sv1;
                tmp[p2]=sv2;
            }

            FORE(p1,en+1,i){
                int isd=5-(p1-en);
                isd=MAX(0,isd);
                if(dp[en][isd]==-1) continue;

                int med=min(5,i-p1);

                char sv1=tmp[p1];
                int ac=dp[en][isd]+1;
                FORE(c1,'a','z'){

                    tmp[p1]=c1;

                    if(isit(en+1,i)){
                        dp[i][med]=MN(dp[i][med],ac);
                        break;
                    }
                }
                tmp[p1]=sv1;

            }


            if(isit(en+1,i)){
                FORE(x,0,5){
                    if(dp[en][x]!=-1){
                        int med=min(5,i-(en-x));
                        dp[i][med]=MN(dp[i][med],dp[en][x]);
                    }
                }

            }



        }

        FORDE(x,4,0) dp[i][x]=MN(dp[i][x],dp[i][x+1]);
    }



    cout<<dp[tmp.size()-1][0];



}
#include <fstream>
int main(){
    fstream ff;
    ff.open("train.txt",fstream::in);

    while(ff>>tmp){
        glo.pb(has(tmp));
    }
    sort(AL(glo));
    glo.resize(unique(AL(glo)) -glo.begin());




   // freopen("C:\\a","r",stdin);
    freopen("C:\\w","w",stdout);



    int t;cin>>t;
    FORE(i,1,t){
        printf("Case #%d: ",i);
        solve();
        cout<<endl;
        fprintf(stderr,"%d\n",i);
    }




    return 0;
}
