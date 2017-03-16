/*
 * This is my code,
 * my code is amazing...
 */
//Template v2.0
//iostream is too mainstream
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<iomanip>
//clibraries
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime>
//defines
#define ll long long
#define lld long double
#define pll pair<ll,ll>
#define pld pair<lld,lld>
#define vll vector<ll>
#define vvll vector<vll>
#define INF 1000000000000000047
const char en='\n';
#define debug(x){cerr<<x<<en;}
#define prime 47
#define lprime 1000000000000000009
#define lldmin LDBL_MIN
#define MP make_pair
#define PB push_back
using namespace std;


ll rev(ll x){
    ll r=0;
    while(x){
        r*=10;
        r+=x%10;
        x/=10;
    }
    return r;
}

ll len(ll x){
    int l=0;
    while(x){
        l++;
        x/=10;
    }
    return l;
}


int main(){
	ios::sync_with_stdio(false);

            ll start=1;
            queue<int>Q;
            Q.push(1);
            Q.push(0);
            vll V(2000000,-1);
            while(Q.size()>0){
                ll t=Q.front(); Q.pop();
                ll p=Q.front(); Q.pop();
                
                if(t>1000000)continue;
                if(V[t]==-1)
                    V[t]=p;
                else continue;
                Q.push(t+1);
                Q.push(p+1);
                Q.push(rev(t));
                Q.push(p+1);
                

            }


        int T;
        cin>>T;

        for(int t=1; t<=T; t++){
            ll x;
            cin>>x;
            
            cout<<"Case #"<<t<<": "<<V[x]+1<<en;
        }





}
