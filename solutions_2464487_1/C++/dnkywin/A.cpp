#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream in("A.in"); ofstream out("A.out");
    int T;
    in>>T;
    for (int i=0;i<T;i++){
        out<<"Case #"<<i+1<<": ";
        long long int r; long long int t;
        in>>r>>t;
        //cout<<r<<" "<<t<<"\n";
        long long int lo = 0;
        long long int hi = t;
        while (lo<hi){
            long long int num = (lo+hi)/2+1;
            if ((2*r+2*num-1)<=t/num){
                lo = num;
            }
            else hi = num-1;
        }
        out<<lo<<"\n";
    }
}
