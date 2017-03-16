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

    for (int step=0;step<case_count;step++)
    {
        int n;
        int f[2501] = {0};
        fin>>n;
        for (int i = 0;i<2*n-1;i++)
            for (int j=0;j<n;j++)
        {
            int x;
            fin>>x;
            f[x]++;
        }
        vector<int> ans;
        for (int i=0;i<=2500;i++)
            if (f[i]%2!=0) ans.push_back(i);
        sort(ans.begin(),ans.end());

        fout<<"Case #"<<step+1<<": ";
        fout<<ans[0];
        for (int i=1;i<ans.size();i++)
            fout<<" "<<ans[i];
        fout<<endl;
    }

    fin.close();
    fout.close();
    return 0;
}

