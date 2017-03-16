#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    int T;
    ifstream ifp("/Users/clsrn1581/Desktop/codejam/A/A-large.in");
    ofstream ofp("/Users/clsrn1581/Desktop/codejam/A/A-large.out");
    
    ifp >> T;
    
    for(int t  = 1; t <=T; t++){
        string str, out ="";
        ifp >> str;
        
        printf("Case #%d: ", t);
        
        out += str[0];
        for(int i = 1 ; i < str.size() ; i++){
            if(out[0] <= str[i]){
                out = str[i] + out;
            }else{
                out = out + str[i];
            }
        }
        ofp << "Case #" << t << ": " << out << endl;
    }
    return 0;
}