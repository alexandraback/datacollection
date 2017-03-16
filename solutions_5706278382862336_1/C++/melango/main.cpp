#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
long long hcf (long long int x, long long int y);

int main()
{
    ifstream input;
    input.open("large.txt");
    ofstream output;
    output.open("largeo.txt");
    int t;
input>>t;
int cse;
for(cse=1;cse<=t;cse++)
{
    long long int nu;
    input>>nu;
    char y;
    input>>y;
    long long int de;
    input>>de;
    int check=1;
    if((int)log2(de)!=log2(de)){check=0;}
    if(check==0){
    long long fact=hcf((long long int)nu,(long long int)de);
    nu=(long double)nu/(long double)fact;

    de=(long double)de/(long double)fact;
    }
    if((int)log2(de)==log2(de)){check=1;}


    if(check==0)
    {
        cout<<"Case #"<<cse<<": impossible"<<endl;
        output<<"Case #"<<cse<<": impossible"<<endl;
    }
    else
    {
        float gen=ceil(-1*(log2((long double)nu/(long double)de)));
        cout<<"Case #"<<cse<<": "<<gen<<endl;
        output<<"Case #"<<cse<<": "<<gen<<endl;

    }

}

return 0;
}
long long hcf (long long int x, long long int y)
{
    while(x!=y)
    {
        if(x>y)
        {
            long long int z=1;
            if(x/y>10){z=x/y-3;}
            x=x-z*y;
        }
        if(y>x)
        {

            long long int z=1;
            if(y/x>10){z=y/x-3;}
            y=y-z*x;
        }
    }
    return x;
}
