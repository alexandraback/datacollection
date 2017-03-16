#include <iostream>
#include <fstream>
#include <deque>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxv = 10000001;

ifstream fin("entrada.in");
ofstream fout("salida.out");

int C,N,E,R,V[maxv];
int D[maxv];

int din(int ener, int act){
    int a, auxv,best;
    if(act == N)    return 0;
    if( D[act] != -1)   return D[act];

    for(a=ener; a>=0; a--){
        auxv=din(min(ener-a+R, E),act+1) + V[act]*a;
        if(auxv > best || a==ener) best = auxv;
    }

    return /*D[act]=*/best;
}

int solve(){
    int i;
    fin>>E>>R>>N;
    for(i=0; i<N; i++)
        fin>>V[i];
    fill(D,D+N,-1);


    fout<<din(E,0)<<endl;
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
