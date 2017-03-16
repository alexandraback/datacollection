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
        int J, S, P, K;
        cin >> J;
        cin >> P;
        cin >> S;
        cin >> K;
        Matrix<int> nb(J+1,S+1);
        Matrix<int> nb2(J+1,P+1);
        Matrix<int> nb3(P+1,S+1);
        nb.fill(0);
        nb2.fill(0);
        nb3.fill(0);
        int compteur = 0;
        for (int i = 1; i<=J; ++i){
            for (int j = 1; j<=P; ++j){
                for (int k = 1; k<=S; ++k){
                    if (nb(i,k)<K && nb2(i,j)<K && nb3(j,k)<K){
                        compteur+=1;
                        nb(i,k)+=1;
                        nb2(i,j)+=1;
                        nb3(j,k)+=1;
                    }
                }
            }
        }
        cout << "Case #" << compt << ": " << compteur << endl;
        nb.fill(0);
        nb2.fill(0);
        nb3.fill(0);
        for (int i = 1; i<=J; ++i){
            for (int j = 1; j<=P; ++j){
                for (int k = 1; k<=S; ++k){
                    if (nb(i,k)<K && nb2(i,j)<K && nb3(j,k)<K){
                        compteur+=1;
                        nb(i,k)+=1;
                        nb2(i,j)+=1;
                        nb3(j,k)+=1;
                        std::cout << i << " " << j << " " << k << endl;
                    }
                }
            }
        }
    }
    return 0;
}
