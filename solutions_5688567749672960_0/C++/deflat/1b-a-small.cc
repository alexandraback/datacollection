#include<iostream>
#include<sstream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<functional>
#include<climits>
#include<utility>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define FORB(i,s,e,st) for (int i = int(s); i < int(e); i+=(int(st)))
#define FOR(i,s,e) FORB(i,s,e,1)
#define REP(i,x) FOR(i,0,x)
#define CLR(a) memset((a), 0 ,sizeof(a))

#define ctoi(c) (c-'0')

const int MOD = 1000000007;
const double PI  = acos(-1.0);


int main(){

    int T;
    cin>>T;
    REP(t,T){
        cout<<"Case #"<<(t+1)<<": ";
        int n;
        cin>>n;
        vi q;
        int dp[n+1];
        CLR(dp);
        q.push_back(1);
        dp[1]=1;
        while(!q.empty()){
            int tg=q[0];
            q.erase(q.begin());
            if(tg==n) break;
            if(dp[tg+1]==0){
                dp[tg+1]=dp[tg]+1;
                q.push_back(tg+1);
            }
            if(tg>=10){
                int ttg=tg;
                int sw=0;
                while(ttg){
                    sw=sw*10+(ttg%10);
                    ttg=ttg/10;
                }
                if(sw<=n&&dp[sw]==0){
                    dp[sw]=dp[tg]+1;
                    q.push_back(sw);
                }
            }

        }
        cout<<dp[n]<<"\n";
    }
    
}
