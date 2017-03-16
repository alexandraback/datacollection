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


#define SZ 60
string tmp;

vector<string> glo;

bool isit(const string &s){
    return binary_search(glo.begin(),glo.end(),s);
}

int dp[SZ][6];

int MN(int a,int b){
    if(a==-1 || b==-1) return max(a,b);
    return min(a,b);
}

void solve(){
    tmp[0]=0;
    cin>>tmp;
    tmp=" "+tmp;

    MEM(dp,-1);
    MEM(dp[0],0);
    FOR(i,1,tmp.size()){

        FOR(en,max(0,i-10),i){



            FORE(p1,en+1,i)
            FORE(p2,p1+5,i){
                int isd=5-(p1-en);
                isd=max(0,isd);

                if(dp[en][isd]==-1) continue;

                char sv1=tmp[p1],sv2=tmp[p2];
                int ac=dp[en][isd]+2;

                int med=min(5,i-p2);

                FORE(c1,'a','z')
                FORE(c2,'a','z'){
                    tmp[p1]=c1;
                    tmp[p2]=c2;

                    if(isit(tmp.substr(en+1,i-en) )){
                        dp[i][med]=MN(dp[i][med],ac);
                        break;
                    }

                }
                tmp[p1]=sv1;
                tmp[p2]=sv2;
            }

            FORE(p1,en+1,i){
                int isd=5-(p1-en);
                isd=max(0,isd);
                if(dp[en][isd]==-1) continue;

                int med=min(5,i-p1);

                char sv1=tmp[p1];
                int ac=dp[en][isd]+1;
                FORE(c1,'a','z'){

                    tmp[p1]=c1;

                    if(isit(tmp.substr(en+1,i-en))){
                        dp[i][med]=MN(dp[i][med],ac);
                        break;
                    }
                }
                tmp[p1]=sv1;

            }


            if(isit(tmp.substr(en+1,i-en))){
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
        glo.pb(tmp);
    }
    sort(AL(glo));




  //  freopen("C:\\a","r",stdin);
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
