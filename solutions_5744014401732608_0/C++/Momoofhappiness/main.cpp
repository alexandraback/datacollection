#include <bits/stdc++.h>
#include <fstream>
long long pot[50];
int slid[50][50];
using namespace std;
int main(){
    fstream potato;
    ofstream optato;
    optato.open("Answer.txt");
    potato.open("B-small-attempt3.in");
    int t = 0, temp=0, possi = 0, brute = 0, ettu = 0, bah=0;
    long long tmep=0;
    potato >> t;
    for(int k=0; k<t; k++){
        optato << "Case #" << k+1 << ": ";
        potato >> temp;
        potato >> tmep;
        possi = 0;
        ettu = 0;
        for(int hi=0; hi<(int)pow(2, (temp-1)*(temp-2)/2); hi++){
                for(int i=0; i<50; i++){
            pot[i]=1;
            for(int m=0; m<50; m++){
                slid[i][m] = 0;
            }
        }
        for(int i=0; i<49; i++){
            slid[i][i+1] = 1;
        }
        ettu = 0;
                brute = hi;
                bah=2;
            for(int m=0; m<((temp-1)*(temp-2)/2); m++){
                if(bah>=temp-ettu){
                    ettu++;
                    bah=2;
                }
                if(brute%2==1){
                    slid[ettu][bah+ettu] = 1;
                }
                brute = brute/2;
                bah++;
            }
        for(int i=0; i<temp; i++){
            for(int m=i+2; m<temp; m++){
                if(slid[i][m]==1){
                    for(int j=m; j<temp; j++){
                        pot[j]+=pot[i];
                    }
                }
            }
        }
  //      printf("%d ", pot[temp-1]);
    //    printf("%d\n", tmep);
        if(pot[temp-1] == tmep){
                    possi = 1;
                    goto woah;
                }
        }
     woah:   if(possi == 1){
            optato << "POSSIBLE\n";
            for(int i=0; i<temp; i++){
            for(int m=0; m<temp; m++){
                optato << slid[i][m];
            }
            optato << "\n";
        }
        }else{
            optato << "IMPOSSIBLE\n";
        }
    }
optato.close();
}
