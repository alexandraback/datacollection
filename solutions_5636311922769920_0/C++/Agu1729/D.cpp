#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream inp("Dt.txt");
    ofstream outp("Do.txt");
    int T, K, C, S;
    inp>>T;
    for(int i=1;i<=T;i++){
        inp>>K>>C>>S;
        outp<<"Case #"<<i<<": ";
        if(K==S){
            for(int j=1;j<=S;j++){
                outp<<j<<" ";
            }
            outp<<endl;
        }
    }
    return 0;
}
    
    
