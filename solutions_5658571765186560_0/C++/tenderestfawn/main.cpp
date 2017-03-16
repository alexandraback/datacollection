#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;
typedef long long ll;

int T;
long long L, X, R, C;



int main(){
    ifstream ins("D-small-attempt0.in");
    ofstream ofs("D-small.txt");
    ins >> T;
    for (int cse = 1; cse <= T; cse++){
        
        string ans = "RICHARD";
        
        ins >> X >> R >> C;
        
        if (X > max(R, C) || (R*C%X) || (X+1)/2 > min(R,C) ){
            
        }
        else{
            switch (X){
                case 1:
                case 2:
                case 3:
                    ans = "GABRIEL";
                    break;
                case 4:
                    if ( min (R, C) > 2)
                        ans = "GABRIEL";
                    break;
                case 5:
                    if ( min (R,C) == 3 && max(R,C) == 5)
                        ans = "GABRIEL";
                    break;
                case 6:
                    if (min(R,C) > 3)
                        ans = "GABRIEL";
                default:
                    break;
                    
            }
        }
        
        ofs << "Case #" << cse << ": " <<ans << endl;
    }
    
}


