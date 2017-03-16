/* 
 * File:   main.cpp
 * Author: nitin
 *
 * Created on April 14, 2012, 6:12 AM
 */
#include <iostream>
#include<cstring>
#include<fstream>
#include<string>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
    ifstream myfile("example.txt");
    int test,min,max,tempdiv,temprem,work,muldig,count,caseno=0;
    myfile>>test;
    while(test)
    {
        //done
        caseno++;
        myfile>>min;
        myfile>>max;
        muldig=1;
        count=0;
        while(muldig<=min)muldig=muldig*10;
        muldig=muldig/10;
        for(int i=min;i<=max;i++)
        {
            work=i;
            while(1)
            {
                tempdiv=work/10;
                temprem=work%10;
                work=temprem*muldig+tempdiv;
                if(work==i)
                    break;
                else if(work>=min&&work<=max&&work>i)
                    count++;
            }
        }
        
        cout<<"Case #"<<caseno<<": "<<count<<endl;
        test--;
    }
    return 0;
}

