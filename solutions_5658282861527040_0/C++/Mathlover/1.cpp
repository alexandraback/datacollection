#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cassert>

using namespace std;

bool _max(double a, double b){
     return a>b;     
}
bool _min(double a, double b){
     return a<b;     
}
int main(int argc, char *argv[])
{
    //ifstream fcin("C:\\Users\\zdb\\Downloads\\B-large.in");
    ifstream fcin("C:\\Users\\zdb\\Downloads\\B-small-attempt2.in");
    //ifstream fcin("file.txt");
    ofstream fcout("ans1.txt");
    int T; fcin >> T;
    for(int i = 1; i <= T; i++){
         int A,B,K;
         int ans = 0;
         fcin >> A >> B >> K;
         for(int u = 0; u < A; u++){
                 for(int v = 0; v < B; v++){
                         if((u&v) < K) ans ++; 
                         //cout << (u & v) << endl;       
                 }
         } 
         fcout << "Case #" << i << ": ";   
         fcout << ans << endl; 
    }    
    system("PAUSE");
    return EXIT_SUCCESS;
}
