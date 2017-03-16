#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <cmath>

using namespace std;

vector<int> results;

bool isPresent(int num){
    for (unsigned int i = 0; i < results.size(); i += 1){
        if(results.at(i) == num) return true;
    }
    return false;
}

int main(int argc, char const* argv[]){
   
    ifstream infile ("C-small-attempt0.in");
    
    //cout << "opening file" << endl;
    
    if (infile.is_open()){
     
        int numTests;
        infile >> numTests;
        
        //cout << numTests << endl;
        
        for(int test = 0; test < numTests; test++){
            int min, max;
            infile >> min >> max;
            
            int numRecycle = 0;
            
            for(int i = min; i <= max; i++){
                int currentNum = i;
                int temp = i;
                
                results.clear();
                                
                //find all pairs for currentNum that is larger
                int tenPow = log10( (double)(currentNum) );
                
                //cout << "num digit - 1: " << tenPow << endl;
                
                for(int dummy = 1; dummy <= tenPow; dummy++){
                
                    //cout << "(currentNum % (int)pow(10, dummy)): " << (currentNum % (int)pow(10, dummy)) << endl;
                    //cout << "pow(10, tenPow - dummy + 1): " << pow(10, tenPow - dummy + 1) << endl;
                    //cout << "currentNum / (int)pow(10, dummy): " << currentNum / (int)pow(10, dummy) << endl;
                
                    temp = (currentNum % (int)pow(10, dummy)) * 
                            pow(10, tenPow - dummy + 1) + currentNum / (int)pow(10, dummy);
                    
                    //cout << "num shifted num: " << temp << endl;
                    //cout << "@@@@@@@@@@@@@@@@@" << endl;
                    
                    int tempTenPow = log10( (double)(temp) );
                    
                    //cout << tenPow << " " << tempTenPow << endl;
                    
                    if(!isPresent(temp)){
                        if(temp > currentNum && temp <= max && tenPow == tempTenPow ){
                        
                            //cout << "found pair: " << currentNum << ", " << temp << endl;
                            
                            results.push_back(temp);
                            numRecycle++;
                        }                            
                    }
                    
                }
                
            }
            
            cout << "Case #" << test + 1 << ": " << numRecycle << endl;;
        }    
    
        infile.close();
    }
}
