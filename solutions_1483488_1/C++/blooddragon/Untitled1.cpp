#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstring>
#include <sstream>
using namespace std;                   

int main()
{
    int cases, small, temp, blah, large, j, k, length;
    char input1;
    string number1,number2,number3;
    stringstream ss;
    ifstream inputfile;
    ofstream outputfile;
    inputfile.open("C-large.in");
    outputfile.open("C-large.out");
    inputfile >> cases;
    cout<<cases<<"\n";
    input1=inputfile.get();
    for(int i=0; i<cases; i++)
    {
            blah=0;
            outputfile<<"Case #"<<i+1<<": ";
            cout<<"Case #"<<i+1<<": ";
            inputfile>>small;
            input1=inputfile.get();
            inputfile>>large;
            input1=inputfile.get();
            for(j=small; j<=large; j++)
            {
                         ss << j;
                         number1 = ss.str();
                         length=number1.length();
                         for(k=1; k<length; k++)
                         {
                                  number2=number1.substr(k,number1.length());
                                  number2+=number1.substr(0,k);
                                  temp=atoi(number2.c_str());
                                  if(temp==j)
                                  length/=2;
                                  if(temp>=small && temp<=large && temp>j)
                                  {
                                                 blah++;
                                  }
                                  number2.clear();
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
