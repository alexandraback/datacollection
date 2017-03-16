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
        int t,k,c;
        fin>>t;
        fin>>k;
        fin>>c;
        if (t>c*k) {
            fout<<"Case #"<<step+1<<": IMPOSSIBLE"<<endl;
        }
        else{
            fout<<"Case #"<<step+1<<": ";
            int cou = 1;
            int i=1;
            while (i<=t)
            {
                long long ans = 1;
                for (int j=i;j<i+k;j++)
                {
                   // cout<<ans<<" ";
                    if (j>t) ans = (ans-1)*t + 1;
                    else ans = (ans-1)*t + j;
                }
                fout<<ans<<" ";
                i+=k;
                //cout<<endl;
            }
            fout<<endl;
        }




    }

    fin.close();
    fout.close();
    return 0;
}

