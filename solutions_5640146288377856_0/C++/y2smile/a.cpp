#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>

using namespace std;

int main() {
    string filename ("input_a");
    string line;
    ifstream file (filename);
    int k;

    //
    getline (file, line);
    k = stoi(line);
                                                                                                                      
    for (int t = 0; t < k; t++) {   //for each test case                                                              
        int r, c, w;                                                                                                  
                                                                                                                      
        // parsing                                                                                                    
        getline (file, line);                                                                                         
                                                                                                                      
        for (int i = 0; i < line.size(); i++) {                                                                       
            if (line[i] == ' ') {                                                                                     
                r = stoi(line.substr(0, i));                                                                          
                line = line.substr(i + 1, line.size() - i - 1);                                                       
                break;                                                                                                
            }                                                                                                         
        }                                                                                                             
                                                                                                                      
        for (int i = 0; i < line.size(); i++) {                                                                       
            if (line[i] == ' ') {                                                                                     
                c = stoi(line.substr(0, i));                                                                          
                w = stoi(line.substr(i + 1, line.size() - i - 1));                                                    
                break;                                                                                                
            }                                                                                                         
        }                                                                                                             
                                                                                                                      
        // main                                                                                                       
        if (w == 1) {                                                                                                 
            cout << "Case #" << t+1 << ": " << r*c << "\r\n";                                                         
            continue;                                                                                                 
        }                                                                                                             
                                                                                                                      
        int count = floor(((double)c)/((double)w)) * r + w - 1;                                                       
        if (c % w != 0) count++;                                                                                      
                                                                                                                      
        cout << "Case #" << t+1 << ": " << count << "\r\n";                                                           
    }                                                                                                                 
    return 0;
}