//
//  main.cpp
//  MagicTrick
//
//  Created by L on 14-4-12.
//  Copyright (c) 2014ๅนด L. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, const char * argv[])
{

    // insert code here...
    ifstream fin;
    ofstream fout;
    int case_count;
    fin.open("data.in",std::ofstream::in);
    fout.open("data.out",std::ofstream::out);
    fin>>case_count;
    string str;
    getline(fin,str);

    for (int step=0;step<case_count;step++)
    {
        string ans = "";
        getline(fin,str);
        ans = str[0];
        for (int i=1; i<str.length();i++)
            if (str[i]>=ans[0]) ans = str[i]+ans;
            else ans +=str[i];
        fout<<"Case #"<<step+1<<": "<<ans<<endl;
    }

    fin.close();
    fout.close();
    return 0;
}

