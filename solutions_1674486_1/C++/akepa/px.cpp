#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int cases;
    int nclases;
    int ninh;
    int inh;
    
    int hereda[1001][1001];
    int nalcanzables[1001][1001];
    
    bool calculado[1001];
    
int calculaAlcanzables(int n){
    
    for(int i = 1; i <=nclases; i++){
            if(hereda[n][i] == true){
                                  if(!calculado[i]){
                                                    int res = calculaAlcanzables(i);
                                                    if(res == true) return true;
                                  }
                                  for(int j = 1; j <= nclases; j++){
                                          if(nalcanzables[i][j] > 0){
                                                                nalcanzables[n][j] += nalcanzables[i][j];
                                                                if(nalcanzables[n][j] > 1) return true;
                                          }
                                  }
            }         
    }
    calculado[n] = true;
    return false;
}


int main(){
    
    bool flag = true;
    
    cin >> cases;
    
    for(int i = 1; i <= cases; i++){
            
            flag = true;
            
            for(int j = 0; j < 1001; j++){
                    for(int k = 0; k < 1001; k++){
                            nalcanzables[j][k] = 0;
                            hereda[j][k] = false;     
                    }
                    calculado[j] = false;
            }
            
            cin >> nclases;
            
            for(int j = 1; j <= nclases; j++){
                    
          
                    cin >> ninh;
                    
                    for(int k = 0; k < ninh; k++){
                            
                            cin >> inh;
                            nalcanzables[j][inh] = 1;
                            hereda[j][inh] = true;
                            
                    }
         
            }
            
            for(int j = 1; flag&&(j <= nclases); j++){
                    if(!calculado[j]){
                                     int res = calculaAlcanzables(j);
                                     if(res){
                                             flag = false;
                                             cout << "Case #" << i << ": Yes" << endl;
                                                     
                                     }
                    }        
            }
            if(flag) cout << "Case #" << i << ": No" << endl;   
    }
    
    
    return 0;
    
}
