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


vector<int> problem2(vector<vector<int>> all)
{
    map<int,int> values;
    for(int i=0; i< all.size(); i++)
    {
        vector<int> heights = all[i];
        for(int j=0; j< heights.size(); j++ )
        {
            if(values.find(heights[j]) == values.end())
            {
                values[heights[j]]=0;
            }
            values[heights[j]] ^= heights[j];
        }
    }
    
    vector<int> final;
    
    for(auto it: values)
    {
        if(it.second)
        {
            final.push_back(it.second);
        }
    }
    std::sort(final.begin(), final.end());
    return final;
}

int main(int argc, const char * argv[]) {
    // insert code here..
    ifstream in("/Users/isira/Documents/CodeJam/2016/B-small-attempt0.in");
    ofstream out("/Users/isira/Documents/CodeJam/2016/B-small-attempt0.out");
    string line;
    getline(in, line);
    
    int nTests =0;
    nTests = stoi(line);
    for(int i= 0; i < nTests; i++)
    {

        getline(in, line);
        int N = stoi(line);
        vector<vector<int>> all;
        for(int j=0; j < 2*N -1; j++)
        {
            getline(in, line);
            stringstream ss(line);
            vector<int> heights;
            for(int k=0; k < N; k++)
            {
                string tmp;
                getline(ss,tmp,' ');
                
                heights.push_back(stoi(tmp));
            }
            all.push_back(heights);
            
        }
        out<<"Case #"<<i+1 <<":";
        
        vector<int> results = problem2(all);
        for(int k=0; k < results.size(); k++)
        {
            out<<" "<<results[k];
        }
        out<<endl;
    }

    in.close();
    out.close();

    return 0;
}
