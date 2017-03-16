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


            vll V(2000000,-1); 

int g(ll x,int p){
    for(int i=0; i<p; i++)
        x/=10;
    return x%10;
}

ll po(int p){
    ll r=1;
    for(int i=0; i<p; i++)
        r*=10;
    return r;

}

ll pocet(ll x){
      //  cout<<x<<endl;
        
        if(x<500000)
                return V[x];

    int d=len(x);

    ll c1=0;
    for(int i=0; i<d/2; i++)
        c1+=po(i)*g(x,i);
    ll c2=0;
    for(int i=d/2; i<d; i++){
        c2*=10;
        c2+=g(x,i);
    }
    if(c1==0 || c2==0)
        return pocet(x-1)+1;
    //cout<<c1<<" "<<c2<<endl;
    return 1+c1+c2+pocet(po(d-1)-1);

}


int main(){
	ios::sync_with_stdio(false);

            ll start=1; 
            queue<int>Q; 
            Q.push(1); 
            Q.push(0); 
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

            
            cout<<"Case #"<<t<<": "<<pocet(x)+1<<endl;
        }





}
