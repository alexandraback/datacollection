#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(void){

    ifstream fin("bull.in");
    ofstream fout("bull.out");

    int t;
    fin>>t;
    for(int T=0;T<t;T++){

        unsigned long long n,r;
        fin>>r>>n;


        unsigned long long a = 2*r + 1;
        unsigned long long x = 1;
        unsigned long long total = a;
        while(total<=n ){
            x++;
            a+=4;
            total+=a;
           // cout<<a<<" "<<total<<endl;
        }
        fout<<"Case #"<<T+1<<": "<<x-1<<endl;

    }


}
