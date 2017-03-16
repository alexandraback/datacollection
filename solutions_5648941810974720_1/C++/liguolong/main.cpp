//
//  main.cpp
//  Playground
//


#include <iostream>
#include <fstream>
#include<sstream>
#include <string>
#include <vector>

#include <cmath>
#include <math.h>
using namespace std;

int main() {

    int cases;

    string line="cccc";
    ifstream myfile("a-large.in.txt");
    
    ofstream outputfile("output.txt");
    if (myfile.is_open())
    {   getline (myfile,line);
        stringstream num_cases(line);
        num_cases>>cases;

    
        for(int i=0;i<cases; i++)
        {
            getline(myfile,line);
            stringstream input(line);
            string numbers;
            input>>numbers;
            vector<int> digits(10,0);
            for (int i=0; i<numbers.size(); i++)
            {
                
                if (numbers[i]=='Z')
                {
                    digits[0]++;
                }
                if (numbers[i]=='U')
                {
                    digits[4]++;
                }
                if (numbers[i]=='X')
                {
                    digits[6]++;
                }
                if (numbers[i]=='G')
                {
                    digits[8]++;
                }
                if (numbers[i]=='W')
                {
                    digits[2]++;
                }
                if (numbers[i]=='O')
                {
                    digits[1]++;
                }
                if (numbers[i]=='R')
                {
                    digits[3]++;
                }
                if (numbers[i]=='F')
                {
                    digits[5]++;
                }
                if (numbers[i]=='V')
                {
                    digits[7]++;
                }
                if (numbers[i]=='I')
                {
                    digits[9]++;
                }
            }
            digits[1]-=digits[0]+digits[2]+digits[4];
            digits[3]-=digits[0]+digits[4];
            digits[5]-=digits[4];
            digits[7]-=digits[5];
            digits[9]-=digits[5]+digits[6]+digits[8];
            
            outputfile<< "Case #";
            outputfile<<i+1;
            outputfile<<": ";
            for(int i=0;i<10;i++)
            {
                for(int j=0;j<digits[i];j++)
                {
                    outputfile<<i;
                
                }
            }
            outputfile<<"\n";

     
              

                
            
            
          
         
            
            
                
            
           
          
          
          
            
        }
        
  
        
        myfile.close();
    }
    
}
