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
bool finish(vector<bool> seen)
{
    bool result =true;
    for (int i = 0;i<10;i++)
    {
        if(seen[i]==false)
        {
            result=false;
        }
    }
    return result;
}

int main() {

    int cases;

    string line="cccc";
    ifstream myfile("b-small-attempt0.in.txt");
    
    ofstream outputfile("output.txt");
    if (myfile.is_open())
    {   getline (myfile,line);
        stringstream num_cases(line);
        num_cases>>cases;

    
        for(int i=0;i<cases; i++)
        {
            getline(myfile,line);
            stringstream input(line);
            int N;
       
            input>>N;
            vector<int> result;
            vector<int> existing(N*(2*N-1));
            for (int j=0;j<2*N-1;j++)
            {
                getline(myfile,line);
                stringstream heights(line);
                for(int k=0;k<N;k++)
                {
                    heights>>existing[j*N+k];
                }
                
            }
            sort(existing.begin(),existing.end());
            int position=0;
            for (int j=1; j<N*(2*N-1);j++)
            {
                if(existing[j]!=existing[j-1])
                {
                    if((j-position)%2==1)
                    {
                        result.push_back(existing[j-1]);
                    }
                    position = j;
                }
            }
            if((N*(2*N-1)-position)%2==1)
            {
                result.push_back(existing[N*(2*N-1)-1]);

            }
            
            
            outputfile<< "Case #";
            outputfile<<i+1;
            outputfile<<": ";
            for(int j=0;j<N;j++)
            {
                outputfile<<result[j];
                outputfile<<" ";
            }
            outputfile<<"\n";

     
              

                
            
            
          
         
            
            
                
            
           
          
          
          
            
        }
        
  
        
        myfile.close();
    }
    
}
