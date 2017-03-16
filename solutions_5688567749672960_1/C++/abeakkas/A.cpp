/*
* abeakkas
* Google CodeJam 2015 - Round 1B
* Problem A
* Bu da mi gol degil
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <utility>

typedef long long int ll;

#define pr pair<ll,ll>
#define vpr vector<pair<ll,ll> >

//DEBUGGING
#define _s cout<<
#define _d <<" "<<
#define _e <<endl;

//(ll *)calloc(1000000,sizeof(ll));
//(ll *)malloc(1000000*sizeof(ll));

using namespace std; 
ifstream fin ("A.in");
ofstream fout ("A.out");

// messy but works ¯\_(".)_/¯
ll find(ll x){
    if(x<23) return x;    
    ll d=0,k=1;
    while(k<=x){d++;k*=10;}
    ll r=0;
    k=1;
    ll l=1;
    ll n=1;
    bool flag=false;
    while(k<=x){
        r+=l*((x/k)%10);
        if(2*n>d+1){
            if(n==d && x/k!=1) flag=true;
            if(n!=d && (x/k)%10!=0) flag=true;    
        }        
        k*=10;
        if((d%2==1 &&2*n>=d)||(d%2==0 && 2*n>d)){
                l/=10;  
        }    
        else if(!(d%2==0 && 2*n==d))l*=10;
        n++;    
    }
    if(flag) r++;
    return r+find(k/10-1);        
}

int main(){
    ll T;
    fin>>T;
    for(ll iT=1;iT<=T;iT++){
        ll x;
        fin>>x;
        fout<<"Case #"<<iT<<": "<<find(x)<<endl;
    }
	return 0;
}
