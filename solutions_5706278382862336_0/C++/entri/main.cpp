#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<sstream>
#include<algorithm>
#include <math.h>

using namespace std;

int T;
long long P,Q;

long long gcd(long long a, long long b){
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void solve(long long P, long long Q){
    long long x = gcd(P,Q);
    P = P/x;
    Q = Q/x;

    long long TQ = Q;
    while(TQ%2 == 0) TQ = TQ/2;

    if (TQ != 1){
        cout <<"impossible"<<endl;
        return;
    };

    long cnt = 0;
    while(P<Q){
        cnt++;
        Q = Q/2;
    };

    cout <<cnt<<endl;

    return;
}

void input_solve(){
    cin >>T;
    for(int i = 1; i<=T; i++){
        long long P, Q;
        char x;
        cin >>P>>x>>Q;
        //cout <<"P is "<<P <<" x is "<<x<<" Q is "<<Q<<endl;
        cout <<"Case #"<<i<<": ";
        solve(P,Q);
    }
}



int main()
{
    //cout << "Hello world!" << endl;

    input_solve();

    return 0;
}

