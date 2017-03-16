#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

typedef long long ll;

int main(){

    int T;
    cin >> T;

    int R, C, M;
    int Rt, Ct;
    int partialR, partialC;
    //int *o, *e, *p;

    for(int i=1;i<=T;i++){
        cin >> R;
        cin >> C;
        cin >> M;
        Rt=R;
        Ct=C;
        partialR=0;
        partialC=0;

        while(M>0){
            if(Rt>Ct){
                if(M>=Ct){
                    M-=Ct;
                    Rt--;
                }else{
                    if(M<=Ct-2){
                        partialR=M;
                        partialC=1;
                        M=0;
                    }else{
                        partialR=M-1;
                        M=1;
                        if((Rt<4)||(Ct<3)){
                            break;
                        }else{
                            partialC=2;
                            M=0;
                        }
                    }
                }
            }else{
                if(M>=Rt){
                    M-=Rt;
                    Ct--;
                }else{
                    if(M<=Rt-2){
                        partialC=M;
                        partialR=1;
                        M=0;
                    }else{
                        partialC=M-1;
                        M=1;
                        if((Ct<4)||(Rt<3)){
                            break;
                        }else{
                            partialR=2;
                            M=0;
                        }
                    }
                }
            }
        }

        if((Ct==1)&&(Rt==2)&&(C>1)) M=1;

        cout << "Case #" << i << ":" << endl;

        if(M==0){
            while(R>Rt){
                for(int j=1;j<=C;j++) cout << "*";
                cout << endl;
                R--;
            }
            for(int k=1;k<=Rt;k++){
                for(int j=1;j<=C-Ct;j++) cout << "*";
                if(k==1){
                    for(int j=1;j<=partialR;j++) cout << "*";
                    for(int j=partialR+1;j<=Ct-1;j++) cout << ".";
                }else{
                    if(k<=partialC){
                        cout << "*";
                    }else if(Ct>1) cout << ".";
                    for(int j=2;j<=Ct-1;j++) cout << ".";
                }
                if(k==Rt){
                    cout << "c";
                }else cout << ".";
                cout << endl;
            }
        }else{
            cout << "Impossible" << endl;
        }
    }

    return 0;
}
