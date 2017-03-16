#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstring>
#include <sstream>
using namespace std;                   

int main()
{
    int cases, small, temp, blah, large, j, k;
    char input1;
    string number1,number2,number3;
    stringstream ss;
    ifstream inputfile;
    ofstream outputfile;
    inputfile.open("C-small-attempt1.in");
    outputfile.open("C-sample.out");
    inputfile >> cases;
    cout<<cases<<"\n";
    input1=inputfile.get();
    for(int i=0; i<cases; i++)
    {
            blah=0;
            outputfile<<"Case #"<<i+1<<": ";
            cout<<"Case #"<<i+1<<": \n";
            inputfile>>small;
            input1=inputfile.get();
            inputfile>>large;
            input1=inputfile.get();
            for(j=small; j<=large; j++)
            {
                         cout<<"Iteration j:"<<j<<"\n";
                         ss << j;
                         number1 = ss.str();
                         for(k=1; k<number1.length(); k++)
                         {
                                  cout<<"Iteration k:"<<k<<"\n";
                                  number2=number1.substr(k,number1.length());
                                  number2+=number1.substr(0,k);
                                  cout<<number2<<" ";
                                  temp=atoi(number2.c_str());
                                  if(temp>=small && temp<=large && temp>j)
                                  {
                                                 if(i==3)
                                                 cout<<"Number pair:"<<j<<" "<<temp<<"\n";
                                                 blah++;
                                  }
                                  number2.clear();
                                  cout<<"blah :"<<blah<<"\n";
                         }
                         number1.clear();
                         ss.str("");
            }
            outputfile<<blah<<"\n";
    }
    inputfile.close();
    outputfile.close();
    return 0;
}
