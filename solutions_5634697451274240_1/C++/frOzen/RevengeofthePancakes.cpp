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

        getline(fin,str);
        cout<<str<<endl;
        int n = str.length(),ans = 0;
        //cout<<n;
        vector<int> a;
        for (int i=0;i<n;i++)
            if (str[i]=='+') a.push_back(1);
            else a.push_back(0);

        for (int i=0;i<n-1;i++)
            if (a[i]!=a[i+1])
            {
                ans++;
            }
        if (a[n-1] == 0) ans++;

        fout<<"Case #"<<step+1<<": "<<ans<<endl;



    }

    fin.close();
    fout.close();
    return 0;
}

