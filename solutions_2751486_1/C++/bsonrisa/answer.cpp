#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

long long doit(string str, int minN) {
     
     long long total = 0;
     int beginLen = 0;
     int firstOther = -1;
     
     for (int index = str.length() - 1; index >= 0; index--) {
         
         int calc1 = 0;
         int calc2 = 0;
         
         bool isConsonant = !(str[index] == 'a' || str[index] == 'e' || str[index] == 'i' || str[index] == 'o' || str[index] == 'u');
         if (isConsonant) {
            beginLen++;         
         } else {         
            if (beginLen >= minN) {
               firstOther = index + 1 + (minN - 1);                            
            }         
            beginLen = 0;       
         }
         if (beginLen >= minN) {
            calc1 = (str.length() - index) - (minN - 1);
         }
         if (firstOther >= 0) {
            calc2 = (str.length() - index) - (firstOther - index);
         }
         //cout << calc1 << calc2 << endl;
         
         total += max(calc1, calc2);
         
     }
     return total;
     
}

int main() {
 
    ifstream infile("C:/a.in");
    ofstream outfile("C:/a.out");
    int numCases = 0;
    infile >> numCases;
    for (int i = 0; i < numCases; i++) {
        int minN;
        string str;
        infile >> str >> minN;   
        long long result = doit(str, minN);
        //system("PAUSE");
        outfile << "Case #" << (i+1) << ": " << result << endl;
    }    
    outfile.close();
    return 0;   
    
}
