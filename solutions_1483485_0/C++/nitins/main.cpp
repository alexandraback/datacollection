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
    char a[26]={'y','n','f','i','c','w','l','b','k','u','o','m','x','s','e','v','z','p','d','r','j','g','t','h','a','q'};
    int test;
    cin>>test;
    string b;
    ifstream myfile ("example.txt");
    char actual[test][101];
    int mem;
    for(int i=0;i<test;i++)
    {
        getline(myfile,b);
        cout<<b<<endl;
        for(int j=0;mem=j,b[j]!='\0';j++)
        {
            if(b[j]==' '||b[j]=='.')
            {
                actual[i][j]=' ';
                continue;
            }
            for(int temp=0;temp<26;temp++)
            {
                if(b[j]==a[temp])
                {
                    actual[i][j]=97+temp;
                    break;
                }
            }
        }
        actual[i][mem]='\0';
    }
    for(int i=0;i<test;i++)
    cout<<"Case #"<<i+1<<":"<<" "<<actual[i]<<"\n";
    return 0;
}

