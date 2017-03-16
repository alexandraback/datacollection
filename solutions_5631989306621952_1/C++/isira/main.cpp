//
//  main.cpp
//  GoogleJam
//
//  Created by Isira Samarasekera on 3/13/16.
//  Copyright (c) 2016 Isira Samarasekera. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <numeric>
#include <math.h>

using namespace std;

string problem1(const string& s)
{
    string last="";
    last += s[0];
    for(int i=1; i< s.size(); i++)
    {
        char c = s[i];
        char f= last[0];
        if(f>c)
        last +=c;
        else
        {
            last = c + last;
        }
        
        
    }
    return last;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream in("/Users/isira/Documents/CodeJam/2016/A-large.in");
    ofstream out("/Users/isira/Documents/CodeJam/2016/A-large.out");
    string line;
    getline(in, line);
    
    int nTests =0;
    nTests = stoi(line);
    for(int i= 0; i < nTests; i++)
    {

        getline(in, line);


        out<<"Case #"<<i+1 <<": ";
        out<<problem1(line)<<endl;
    }

    in.close();
    out.close();

    return 0;
}
