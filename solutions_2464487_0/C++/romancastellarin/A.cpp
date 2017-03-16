#include <iostream>
#include <fstream>
#include <deque>
#include <cstdlib>
using namespace std;

ifstream fin("entrada.in");
ofstream fout("salida.out");

long long int C,N,T;

int solve(){
    long long int i;
    fin>>N>>T;
    i=0;
    N++;
    do{
        T-=2*N-1;
        N+=2;
        if(T>=0)    i++;
    }while(T>0);
    fout<<i<<endl;;
}

int main(){
    int i;
    fin>>C;
    for(i=1; i<=C;i++){
        fout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
