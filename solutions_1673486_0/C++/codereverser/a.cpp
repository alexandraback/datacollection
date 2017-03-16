#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    
    int cases;
    int length, typed;
    double p[100];
    double result, tmp;
    
    cin >> cases;
    for (int c = 1; c<=cases; c++) { 
        cin >> typed;
        cin >> length;
        for (int i=0; i<typed; i++) cin >> p[i];
        result = 0;
        
        /// Continue typing
        double prob = 1.0;
        for (int k=0; k<typed; k++) prob *= p[k];
        result = prob * (length+1-typed) + (1-prob) * (length+1+length+1-typed);
        
        
        for (int j=1; j<=typed; j++) { 
            double prob = 1.0;
            for (int l=0; l<typed-j; l++) prob *= p[l];    
            tmp = prob * (length+1-typed+2*j) + (1-prob) * (length+1 + length+1-typed+2*j);
            if (tmp < result) result = tmp;
        }
        
        /// Pressing enter rightaway
        if (result > length+2) result = length+2;
        
        cout << "Case #" << c << ": " << setiosflags(ios::fixed) << setprecision(6) << result << endl;
    }
    
    return 0;
}
