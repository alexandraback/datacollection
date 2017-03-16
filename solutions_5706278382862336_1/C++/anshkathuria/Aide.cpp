#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iostream>
#include <cstring>
#include <fstream>

#define ll long long

using namespace std;

const int T=2*1e2 + 5;

ll P,Q;

bool chk(ll x){
    while (x%2==0)
        x/=2;
    return (x==1);
}

int main(){
    ifstream fin ("A-large.in",ios::in);
    fstream fout;
    fout.open ("A-large.txt",ios::out);
    int tests;
    fin>>tests;
    int t=tests;
    while (tests--){
        char ch;
        fin>>P>>ch>>Q;
        ll g=__gcd(P,Q);
        P/=g;
        Q/=g;
        if (!chk(Q)){
            fout<<"Case #"<<t-tests<<": "<<"impossible"<<endl;
            continue;
        }

        ll x=1;
        ll ans=0;
        while ( P*x < Q )
            x*=2ll,ans++;
        fout<<"Case #"<<t-tests<<": "<<ans<<endl;
    }
    return 0;
}
