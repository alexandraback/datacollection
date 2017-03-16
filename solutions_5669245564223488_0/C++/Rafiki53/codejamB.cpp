#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<list>
#include<math.h>
#include<algorithm>
#include<string>
#include<set>
#include<queue>
#define limit 1000000007
#define inf 9223372036854775807ll
#define iinf 2147483647
#define mp make_pair
#define pb push_back
#define rep(i,k,n) for(int i=k;i<n;i++)
using namespace std;
int alfin[30],alfout[30],alfmid[30],alfccl[30],visited[30];
bool inmid=false,ok=true;
vector<vector<int> > nei;
long long fac(long long a){
    if(a==1 || a==0) return 1;
    else return (a*fac(a-1))%limit;
}
void dfs(int v){
    visited[v]++;
    rep(i,0,nei[v].size()){
        if(visited[nei[v][i]]) ok=false;
        else dfs(nei[v][i]);
    }
}
int main(){
    freopen("B-small-attempt3.in", "r", stdin);
    freopen("B.out", "w",stdout);
    int n,t,res=0,act,start;
    long long ans=1;
    string car;
    cin >> t;
    rep(q,1,t+1){
        nei.clear();
        nei.resize('z'-'a'+1);
        ans=1;
        res=0;
        ok=true;
        cin >> n;
        rep(i,0,n){
                cin >> car;
                inmid=false;
                act=car[0]-'a';
                start=act;
                rep(k,1,car.size()){
                    if(car[k]-'a'!=act){
                        if(inmid) alfmid[act]++;
                        else{
                            alfin[act]++;
                            inmid=true;
                        }
                        act=car[k]-'a';
                    }
                }
                if(inmid){
                        alfout[act]++;
                        nei[start].pb(act);
                }
                else alfccl[act]++;
        }
        rep(i,0,'z'-'a'+1){
            if(!alfin[i]) dfs(i);
        }
        rep(i,0,'z'-'a'+1){
            if(alfmid[i]+alfin[i]+alfout[i]>1 && (alfmid[i]!=0 || alfin[i]!=1 || alfout[i]!=1)) ok=false;
            ans=(ans*fac(alfccl[i]))%limit;
            if(alfin[i]==0 && alfout[i]+alfccl[i]!=0) res++;
        }
        ans=(ans*fac(res))%limit;
        if(ok) cout << "Case #" << q << ": " << ans << "\n";
        else cout << "Case #" << q << ": 0\n";
        rep(i,0,'z'-'a'+1){
            alfin[i]=0;
            alfout[i]=0;
            alfmid[i]=0;
            alfccl[i]=0;
            visited[i]=0;
        }
    }

    return 0;
}
