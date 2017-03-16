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
#define ff first
#define ss second
using namespace std;



int main(){
	ios::sync_with_stdio(false);

        int T;
        cin>>T;
        for(int t=1; t<=T; t++){

            int n;
            cin>>n;
            
            vector<pll>V;
            
            for(int i=0; i<n; i++){
                int d,h,m;
                cin>>d>>h>>m;
                for(int j=0; j<h; j++)
                    V.PB(MP(d,m+j));
            
            }   

            int ans=0;
            if(V.size()==1)ans=0;
            else{
                if(V[0]<V[1])
                    swap(V[0],V[1]);
                
                double cas1=(360-V[0].ff)/((360)/(double)V[0].second);
                double cas2=(360-V[1].ff)/((360)/(double)V[1].second);
                //cout<<cas1<<" "<<cas2<<en;
                if(max(cas1,cas2)>cas1+V[0].ss)
                    ans=1;
                if(max(cas1,cas2)>cas2+V[1].ss)
                    ans=1;

            }

            cout<<"Case #"<<t<<": "<<ans<<en;
        }




}
