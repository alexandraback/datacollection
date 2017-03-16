#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

    int cases;
    int n, m;
    int A[101];
    int B[101];
    unsigned long long int a[101];
    unsigned long long int b[101];

int calcula(int nx, unsigned long long usadon, int mx, unsigned long long usadom, unsigned long long result){
    if(nx >= n ) return result;
    if(mx >= m) return result;
    
    if(A[nx] == B[mx]){
             int restA = a[nx] - usadon;
             int restB = b[mx] - usadom;
             if(restA > restB){
                      //int res1 = calcula(nx+1, 0, mx, usadom, result);
                      //int res2 = calcula(nx, usadon, mx+1, 0, result);
                      int res3 = calcula(nx, restB, mx+1, 0, result+restB);
                      //return max(max(res1, res2), res3);   
                      return res3;      
             }
             else{
                  //int res1 = calcula(nx+1, 0, mx, usadom, result);
                  //int res2 = calcula(nx, usadon, mx+1, 0, result);
                  int res3 = calcula(nx+1, 0, mx, restA, result+restA); 
                  //return max(max(res1, res2), res3);
                  return res3;
             }         
    }
    else{
         int res1 = calcula(nx+1, 0, mx, usadom, result);
         int res2 = calcula(nx, usadon, mx+1, 0, result);
         return max(res1, res2);
    }

   
}


int main(){
    
    cin >> cases;
    
    
    for(int i = 1; i <= cases; i++){
            
            cin >> n >> m;
            
            for(int j = 0; j < n; j++){
                  cin >> a[j];
                  cin >> A[j];  
            }
            
            for(int j = 0; j < m; j++){
                    cin >> b[j];
                    cin >> B[j];
            }
            
            
            // logic
            
            unsigned long long nx = 0;
            unsigned long long mx = 0;
            unsigned long long result = 0;
            
            result = calcula(nx, 0, mx, 0, result);
            
            cout << "Case #" << i << ": " << result << endl;
            
    }   
    
    return 0;
    
}
