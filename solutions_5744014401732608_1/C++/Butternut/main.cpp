// Author:   Charles AUGUSTE

#include <iostream>
#include <fstream>
#include <math.h>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <Imagine/LinAlg.h>

using namespace std;
using namespace Imagine;

int main(){
    int T;
    cin >> T;
    for (int compt=1; compt<T+1; ++compt){
        long long int B,M;
        cin >> B;
        cin >> M;
        Matrix<int> F(B,B);
        F.fill(0);
        long double M2 =M;
        if (M<=pow(2,B-2)){
            cout << "Case #" << compt << ": POSSIBLE" << endl;
            M2 = log2(M2);
            long long int puis = (int)floor(M2);
            for (int i = 0; i<=puis; ++i){
                for (int j = 1; j<=puis; ++j){
                    if (j>i){
                        F(i,j)=1;
                    }
                }
            }
            long long int reste = M-pow(2,puis);
            for (int i = puis; i>=1; i=i-1){
                if (pow(2,i-1)<reste){
                    reste -= (pow(2,i-1));
                    F(i, puis+1) = 1;
                }
            }
            if (reste == 1){
                F(0, puis+1) = 1;
            }

            F(0,B-1)=1;
            for (int i = 0; i<B-1; ++i){
                for (int j = 0; j<B-1; ++j){
                    if (F(i,j)==1){
                        F(j,B-1)=1;
                    }
                }
            }
            for (int i = 0; i<B; ++i){
                for (int j = 0; j<B; ++j){
                        cout << F(i,j);
                }
                cout << endl;
            }
        }

        else{
            cout << "Case #" << compt << ": IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
