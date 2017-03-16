#include<iostream>
#include<fstream>
using namespace std;

int main () {
    ifstream inp;
    ofstream outp;
    inp.open("bi.txt");
    outp.open ("bo.txt");
    int T, n[2501], N, ans[51], hght, id;
    inp>>T;
    for(int i=1;i<=T;i++){
        inp>>N;
        outp<<"Case #"<<i<<":";
        for(int j=0;j<=2500;j++){
            n[j]=0;
        }
        for(int j=0;j<=2*N-2;j++){
            for(int k=0;k<=N-1;k++){
                inp>>hght;
                n[hght]^=1;
            }
        }
        id=0;
        for(int j=0;j<=2500;j++){
            if(n[j]==1){
                ans[id]=j;
                id++;
            }
        }
        for(int j=0;j<=N-1;j++){
            outp<<" "<<ans[j];
        }
        outp<<endl;
    }
    return 0;
}