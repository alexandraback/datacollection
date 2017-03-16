#include<iostream>
#include<fstream> 
#include<bitset>
using namespace std;

int main(){
    ifstream inp("Ct.txt");
    ofstream outp("Co.txt");
    bitset<8> a;
    bitset<16> b;
    outp<<"Case #1:"<<endl;
    for(int i=129;i<=227;i+=2){
        a=bitset<8>(i);
        for(int j=0;j<=7;j++){
            b[2*j]=a[j];
            b[2*j+1]=a[j];
        }
        outp<<b<<" 3 4 5 6 7 8 9 10 11"<<endl;
    }
    return 0;
}
