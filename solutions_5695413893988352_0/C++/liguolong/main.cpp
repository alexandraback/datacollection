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
long bestmatcher(string &first, string &second, int &state)
{
    int zeroo=0;
    int oneo=1;
    int twoo=2;
 
    for (int i=0; i<first.size(); i++)
    {
        if(state==1)
        {
            if(first[i]=='?')
            {
                first[i]='0';
            }
            if(second[i]=='?')
            {
                second[i]='9';
            }
        }
        if(state==2)
        {
            if(first[i]=='?')
            {
                first[i]='9';
            }
            if(second[i]=='?')
            {
                second[i]='0';
            }
        }
        if(state==0)
        {
            if(first[i]!='?'&&second[i]!='?')
            {
                if(first[i]>second[i])
                {
                    state=1;
                }
                if(second[i]>first[i])
                {
                    state=2;
                }
            }
            if(first[i]=='?'&&second[i]=='?')
            {
                long zero;
                long one;
                long two;
                long minimum;
                string firsto=first.substr(i,first.size()-i);
                string secondo=second.substr(i,first.size()-i);
                string firstt=firsto;
                string secondt=secondo;
                firstt[0]='0';
                secondt[0]='0';
                zero=bestmatcher(firstt,secondt,zeroo);
               
                minimum=zero;
                for(int j=0;j<firstt.size();j++)
                {
                    first[i+j]=firstt[j];
                    second[i+j]=secondt[j];
                    
                }
                firstt=firsto;
                secondt=secondo;
                firstt[0]='0';
                secondt[0]='1';
                two=bestmatcher(firstt,secondt,twoo);
                first[i]='0';
                second[i]='0';
                if(two<minimum)
                {
                    minimum=two;
                    for(int j=0;j<firstt.size();j++)
                    {
                        first[i+j]=firstt[j];
                        second[i+j]=secondt[j];
                        
                    }
                }
                firstt=firsto;
                secondt=secondo;
                firstt[0]='1';
                secondt[0]='0';
                one=bestmatcher(firstt,secondt,oneo);
                if(one<minimum)
                {
                    for(int j=0;j<firstt.size();j++)
                    {
                        first[i+j]=firstt[j];
                        second[i+j]=secondt[j];
                        
                    }
                }
                break;
                


                
            }
            if(first[i]=='?'&&second[i]!='?')
            {
                long zero;
                long one;
                long two;
                long minimum;
                string firsto=first.substr(i,first.size()-i);
                string secondo=second.substr(i,first.size()-i);
                string firstt=firsto;
                string secondt=secondo;
                firstt[0]=second[i];
                zero=bestmatcher(firstt,secondt,zeroo);
                minimum=zero;
                for(int j=0;j<firstt.size();j++)
                {
                    first[i+j]=firstt[j];
                    second[i+j]=secondt[j];
                    
                }

                firstt=firsto;
                secondt=secondo;
                if(second[i]!='9')
                {
                    firstt[0]=second[i]+1;
                    one=bestmatcher(firstt,secondt,oneo);
                    if (one<minimum)
                    {
                        for(int j=0;j<firstt.size();j++)
                        {
                            first[i+j]=firstt[j];
                            second[i+j]=secondt[j];
                            
                        }

                        
                    }

                }
                firstt=firsto;
                secondt=secondo;
                if(second[i]!='0')
                {
                    firstt[0]=second[i]-1;
                    two=bestmatcher(firstt,secondt,twoo);
                    if (two<minimum+1)
                    {
                        
                        for(int j=0;j<firstt.size();j++)
                        {
                            first[i+j]=firstt[j];
                            second[i+j]=secondt[j];
                            
                        }
                        
                        
                    }

                }
                break;
            }
            if(first[i]!='?'&&second[i]=='?')
            {
                long zero;
                long one;
                long two;
                long minimum;
                string firsto=first.substr(i,first.size()-i);
                string secondo=second.substr(i,first.size()-i);
                string firstt=firsto;
                string secondt=secondo;
                secondt[0]=first[i];
                
                zero=bestmatcher(firstt,secondt,zeroo);
                minimum=zero;
                for(int j=0;j<firstt.size();j++)
                {
                    first[i+j]=firstt[j];
                    second[i+j]=secondt[j];
                    
                }
                
                firstt=firsto;
                secondt=secondo;
                if(first[i]!='0')
                {
                    secondt[0]=first[i]-1;
                    
                    one=bestmatcher(firstt,secondt,oneo);
                    if (one<minimum+1)
                    {
                        for(int j=0;j<firstt.size();j++)
                        {
                            first[i+j]=firstt[j];
                            second[i+j]=secondt[j];
                            
                        }
                        
                        
                    }
                    
                }
                firstt=firsto;
                secondt=secondo;
                if(first[i]!='9')
                {
                    secondt[0]=first[i]+1;
                    two=bestmatcher(firstt,secondt,twoo);

                    if (two<minimum)
                    {
                        for(int j=0;j<firstt.size();j++)
                        {
                            first[i+j]=firstt[j];
                            second[i+j]=secondt[j];
                            
                        }
                        
                        
                    }
                    
                }
                break;
            }

            
            
         
                
                
                
            
            
        }


        
    }
    stringstream firstn(first);
    stringstream secondn(second);
    int m;
    int n;
    firstn>>m;
    secondn>>n;
    
    return (abs(m-n));
}
int main() {

    int cases;

    string line="cccc";
    ifstream myfile("b-small-attempt4.in.txt");
    
    ofstream outputfile("output.txt");
    if (myfile.is_open())
    {   getline (myfile,line);
        stringstream num_cases(line);
        num_cases>>cases;

    
        for(int i=0;i<cases; i++)
        {
            getline(myfile,line);
            stringstream input(line);
            string first;
            string second;
            input>>first>>second;
            int zeroo=0;
            bestmatcher(first,second,zeroo);
            outputfile<< "Case #";
            outputfile<<i+1;
            outputfile<<": ";
            outputfile<<first;
            outputfile<<" ";
            outputfile<<second;
            outputfile<<"\n";

     
              

                
            
            
          
         
            
            
                
            
           
          
          
          
            
        }
        
  
        
        myfile.close();
    }
    
}
