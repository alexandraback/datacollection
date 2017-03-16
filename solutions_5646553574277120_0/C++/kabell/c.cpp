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



int main(){
	ios::sync_with_stdio(false);

        int T;
        cin>>T;
        for(int t=1; t<=T; t++){
            int c,d,v;
            cin>>c>>d>>v;
          
            vll P(1000,0);
            for(int i=0; i<d; i++){
                int x;
                cin>>x;
                for(int i=100; i>=0; i--)
                    if(P[i])
                        P[i+x]=1;
                P[x]=1;
            }
            int res=0;
            for(int i=1; i<=v; i++){
                if(!P[i]){
                    for(int j=100; j>=0; j--)
                        if(P[j])
                            P[j+i]=1;
                    P[i]=1;
                    
                    res++;
                }

            }

            cout<<"Case #"<<t<<": "<<res<<en;; 
        }


}
