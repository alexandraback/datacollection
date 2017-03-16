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

int main()
{
    ifstream input;
    input.open("small.txt");
    ofstream output;
    output.open("smallo.txt");
    int t;
input>>t;
int cse;
for(cse=1;cse<=t;cse++)
{
    int nu;
    input>>nu;
    char y;
    input>>y;
    int de;
    input>>de;
    int check=1;
    if((int)log2(de)!=log2(de)){check=0;}

    if(check==0)
    {
        cout<<"Case #"<<cse<<": impossible"<<endl;
        output<<"Case #"<<cse<<": impossible"<<endl;
    }
    else
    {
        float gen=ceil(-1*(log2((float)nu/(float)de)));
        cout<<"Case #"<<cse<<": "<<gen<<endl;
        output<<"Case #"<<cse<<": "<<gen<<endl;

    }

}

return 0;
}
