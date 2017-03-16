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
    ifstream myfile("c-small-attempt0.in.txt");
    
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
            vector<int> BFF(N);
            vector<vector<int>>pairs;
            vector<int> pairsl;
    
            int circlelength=0;
            getline(myfile,line);
            stringstream inputbff(line);
         
            for(int j=0;j<N;j++)
            {
                inputbff>>BFF[j];
                BFF[j]-=1;
           
            }
            
            
            for(int j=0;j<N;j++)
            {
                vector<int> path;
                path.push_back(j);
                int position=j;
                while(find(path.begin(),path.end(),BFF[position])==path.end())
                {
                    path.push_back(BFF[position]);
                    position=BFF[position];
               }
               
                int circlesize=(int)(path.end()-find(path.begin(),path.end(),BFF[position]));
                if (circlesize>circlelength)
                {
                    circlelength=circlesize;
                }
                if (circlesize==2)
                {
                    vector<int> duo;
                    duo.push_back(position);
                    duo.push_back(BFF[position]);
                    if(find(pairs.begin(),pairs.end(),duo)==pairs.end())
                    {
                        pairs.push_back(duo);
                        pairsl.push_back(0);
                        
                    }
                    int pathposition=(int)(find(pairs.begin(),pairs.end(),duo)-pairs.begin());
                    if (pairsl[pathposition]<path.size()-1)
                    {
                        pairsl[pathposition]=(int)path.size()-1;
                    }
                    
                }
                
                
                
            }
            int sum=0;
            for (int j=0;j<pairsl.size();j++)
            {
                sum+=pairsl[j];
            }
            circlelength=max(circlelength,sum);
            

            
       
      
            
            outputfile<< "Case #";
            outputfile<<i+1;
            outputfile<<": ";
            outputfile<<circlelength;
            outputfile<<"\n";

     
              

                
            
            
          
         
            
            
                
            
           
          
          
          
            
        }
        
  
        
        myfile.close();
    }
    
}
