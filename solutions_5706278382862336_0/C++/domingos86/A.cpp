#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    ll c;
    while (a!=0){
        c=a;
        a=b%a;
        b=c;
    }
    return b;
}

int log2(ll a){
    int k=0;
    while(a>1){
        a/=2;
        k++;
    }
    return k;
}

int main(){

    int T;
    cin >> T;

    ll P,Q;

    ll p240=pow(2,40);
    ll g;

    int k;
    //int N, M;
    //int *o, *e, *p;

    for(int i=1;i<=T;i++){

        fscanf(stdin,"%Ld/%Ld",&P,&Q);

        g=gcd(P,Q);

        P=P/g;
        Q=Q/g;

        cout << "Case #" << i << ": ";

        if(p240%Q!=0){ cout << "Impossible";}
        else{
            cout << log2(Q)-log2(P);
        }

        cout << endl;
    }

    return 0;
}
