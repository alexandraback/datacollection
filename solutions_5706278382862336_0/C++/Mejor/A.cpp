#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <limits>
#include <string>
#include <queue>
#include <cstdio>
using namespace std;

long long gcd(long long a, long long b){
    while (b!=0){
        //fout<<a<<"  "<<b<<endl;
        long long temp=a;
        a=b;
        b=temp%b;

    }
   // fout<<a<<"  "<<b<<endl;
    return a;
}

bool verf (long long a){
    while (a!=1){
        if (a%2==1) return false;
        a/=2;
    }
    return true;
}

int main (){
    ifstream fin("A-small-attempt2.in");
    ofstream fout("A.out");
    int cpt; fin>>cpt;
    for (int k=1;k<=cpt;++k){
        long long p,q,d,ans=0;
        char c;
        bool stop=false;
        fin>>p>>c>>q;
        do {
            d=gcd(q,p);
            p=p/d,q=q/d;
            if (!verf(q)) stop=true;
            else p*=2,ans++;
        } while (p<q && !stop);
        if (ans>40) stop=true;
        if (stop) fout<<"Case #"<<k<<": impossible"<<endl;
        else  fout<<"Case #"<<k<<": "<<ans<<endl;

    }
    return 0;
}
