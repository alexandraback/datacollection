#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

int T;
const int NMAX = 102;
long double C[NMAX],F[NMAX],X[NMAX];
long double Mi = 1e9L;

void readInput(){
    cin >>T;
    for(int i = 0; i<T; i++){
        cin >>C[i]>>F[i]>>X[i];
    };
};

long double cookieClick(long double C, long double F, long double X){
    //cout <<C<<" "<<F<<" "<<X<<endl;
    C = C*Mi;
    F = F*1;
    X = X*Mi;
    vector<long double> rate, CK, R, Time;
    CK.push_back(0.0L);
    rate.push_back(1*2.0L);
    Time.push_back(0.0L);

    int farm = 0;

    long double res = X/2;
    R.push_back(res);
    while(true){
        long double t = (C-CK[farm]) / rate[farm];
        //cout <<t<<endl;
        Time.push_back(Time[farm] + t);
        CK.push_back(C - t*rate[farm]);
        rate.push_back(F+rate[farm]);

        t = Time[farm] + (X - CK[farm]) / rate[farm];
        if (res <t) break;
        //res = min(res, t);
        if (t<res) res = t;
        R.push_back(res);

        //printf("%0.8f",t);
        //cout<<endl;
        farm++;
        if (farm > X/2) break;
        //cout <<farm<<" "<<CK[farm]<<" "<<C<<" "<<rate[farm]<<" "<<Time[farm]<<endl;
    };

    return res/Mi;
}

void solve(){
    for(int i=0;i<T;i++){
        long double res = cookieClick(C[i],F[i],X[i]);
        cout <<"Case #"<< (i+1) <<": ";
        printf("%0.8lf", res);
        cout <<endl;
    };
}

int main()
{
    //long double x;
    readInput();
    solve();
    //writeOutput();
    return 0;
}
