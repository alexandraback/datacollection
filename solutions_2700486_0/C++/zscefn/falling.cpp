#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    int t;
    cin>>t;
    cout.precision(7);
    for(int i=1; i<=t; ++i) {
        int n,x,y;
        cin>>n>>x>>y;
        int kanta=0;
        int koko=0;
        for(int j=1; ;j+=2) {
            if(j*(j+1)/2 > n) {
                break;
            }
            kanta=j;
            koko=j*(j+1)/2;
        }
        if(abs(x)+abs(y)<=kanta-1) {
            cout<<"Case #"<<i<<": 1.0\n";
            continue;
        };
        if(abs(x)+abs(y)>kanta+1) {
            cout<<"Case #"<<i<<": 0.0\n";
            continue;
        }
        if(koko==n) {
            cout<<"Case #"<<i<<": 0.0\n";
            continue;
        }
        //if((n-koko)>kanta+1)  
        int jakaja=0;
        int jaettava=0;
        for(int j=0; j<=(n-koko)&&j<=kanta+1; ++j) {
            if(n-koko-j>kanta+1) {
                j=n-koko-(kanta+1);
            }
            if(y+1<=j) {
                jaettava+=pow((double)2, min(j, n-koko-j));;
                
            }
            jakaja+=pow((double)2, min(j, n-koko-j));;
        }
        double lol=((double)jaettava)/((double)jakaja);
        cout<<fixed;
        cout<<"Case #"<<i<<": "<<lol<<'\n';
    }
}
