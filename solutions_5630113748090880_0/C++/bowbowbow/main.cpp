#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory.h>
#define MAXN 10000

int Count[MAXN];
using namespace std;

int main(){
    int T;
    ifstream ifp("/Users/clsrn1581/Desktop/codejam/B/B-small-attempt1.in");
    ofstream ofp("/Users/clsrn1581/Desktop/codejam/B/B-small-attempt1.out");
    
    ifp >> T;
    
    for(int t = 1; t <=T; t++){
        memset(Count ,0, sizeof(Count));
        
        int N;
        ifp >> N;
        
        for(int i =1; i <= 2*N-1 ; i++){
            for(int j = 1; j<= N; j++){
                int tmp;
                ifp >> tmp;
                Count[tmp]++;
            }
        }
    
        ofp << "Case #" << t << ": ";
        
        for(int i = 1 ; i<= 2500; i++){
            if(Count[i]%2 == 1){
                ofp << i << " ";
            }
        }
        ofp << endl;
    }
    return 0;
}