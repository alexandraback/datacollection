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
    ifstream myfile("a-small-attempt0.in.txt");
    
    ofstream outputfile("output.txt");
    if (myfile.is_open())
    {   getline (myfile,line);
        stringstream num_cases(line);
        num_cases>>cases;

    
        for(int i=0;i<cases; i++)
        {
            getline(myfile,line);
            stringstream input(line);
            string word;
            input>>word;
            string result;
            stringstream ss;
            string s;
            ss<<word[0];
            ss>>s;
            result.insert(0,s);
            for(int j=1;j<word.size();j++)
            {
                stringstream ssss;
                string sss;
                ssss<<word[j];
                ssss>>sss;
                string resulto=result;
                string resultt=result;
                resulto.insert(0,sss);
                resultt.insert(resultt.size(),sss);
                if(resultt>resulto)
                {
                    result=resultt;
                }
                else
                {
                    result=resulto;
                }
            }
            
       
      
            
            outputfile<< "Case #";
            outputfile<<i+1;
            outputfile<<": ";
            outputfile<<result;
            outputfile<<"\n";

     
              

                
            
            
          
         
            
            
                
            
           
          
          
          
            
        }
        
  
        
        myfile.close();
    }
    
}
