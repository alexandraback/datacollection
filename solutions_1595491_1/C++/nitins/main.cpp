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
    int test,gg,count,i,score,caseno=0;
    int sup=0,p=0,div,rem;
    myfile>>test;
    while(test)
    {
        sup=0,p=0;
        myfile>>gg>>sup>>p;
        count=0;
        i=0;
        while(i<gg)
        {
            i++;
            //computation
            myfile>>score;
            div=score/3;
            if(div>p-1)
            {
                //cond satisfied
                count++;
            }
            else if(div<p-2)
            {
                //cond not stisfied
                continue;
            }
            else if(div==p-2)
            {
                rem=score%3;
                if(rem==2&&sup>0)
                {
                    sup--;
                    count++;
                }
                else continue;
            }
            else if(div==p-1)
            {
                rem=score%3;
                if(rem>0)
                    count++;
                else if(rem==0&&sup>0&&score!=0)
                {
                    sup--;
                    count++;
                }
            }
        }
        cout<<"Case #"<<caseno+1<<": "<<count<<endl;
        test--;caseno++;
    }
    return 0;
}

