/* 
 * File:   main.cpp
 * Author: Parnami
 * Created on April 12, 2014, 4:43 AM
 * Description : Google Code Jam 2014 First Round A. Question 2
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <set>
#include <sstream>
#include <fstream>
#include <bitset>

using namespace std;

inline int fastRead()
{
    int input;
    char c=0;
    while (c<33) c=getchar();
    input=0;
    while (c>33)
    {
          input=input*10+c-'0';
          c=getchar();
    }
    return input;
}

long long int gcd(long long int a, long long int b) {
  long long int tmp;
  while(b){a%=b; tmp=a; a=b; b=tmp;}
  return a;
}

bool is_power_of_2(long long int i) {
    if ( i < 0 ) {
        return 0;
    }
    return ! (i & (i-1));
}

double arr[45];

int main(int argc, char** argv) 
{
    int t,i,lineNumber,j,count,answer,l,counter,finalCount,flag;
    long long int one,two,temp;
    char slash;
    string fileName = "in.txt";
    ifstream input_data("A-large.in");
    ofstream outputFile("outters.txt");
    //input_data.open;
    input_data>>t;
    for(i=0;i<t;i++)
    {
        input_data>>one>>slash>>two;
        outputFile<<"Case #"<<i+1<<": ";
        //cout<<one<<"    /    "<<two<<endl;
        temp = gcd(one,two);
        one = one/temp;
        two = two/temp;
        cout<<temp<<"  "<<one<<"  "<<two<<endl;
        if(is_power_of_2(two) && one<=two)
        {
            temp = two;
            finalCount=counter=0;
            flag=0;
            while(temp!=1)
            {
                temp = temp/2;
                counter++;
                if(one>temp)
                {
                    one-=temp;
                    finalCount=counter;
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                outputFile<<finalCount<<endl;
            }
            else
            {
                outputFile<<counter<<endl;
            }
        }
        else
        {
            outputFile<<"impossible"<<endl;
        }
    }
    return 0;
}
