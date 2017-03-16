// Abdurrahman Akkas - abdurak
// Google CodeJam 2014
// Qualification Round
// Problem B

#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int main(){
    ifstream fin("B.in");
    ofstream fout("B.out");
    int T,iT;
    fin>>T;
    fout<<setprecision(15);
    for(iT=1;iT<=T;iT++){
        double C,F,X;
        double V=2;
        fin>>C>>F>>X;
        double mint=X/V*2,t=X/V;
        while(t<mint){
            mint=t;
            t=mint-(X-C)/V+X/(V+F);
            V+=F;
        }
        fout<<"Case #"<<iT<<": ";
        fout<<mint;
        fout<<endl;
    }
    return 0;
}
